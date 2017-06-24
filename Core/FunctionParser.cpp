#include "FunctionParser.h"

#include "ObjectFunction.h"
#include "Log.h"

#include <RuntimeCompiler/ICompilerLogger.h>
#include <RuntimeObjectSystem/RuntimeObjectSystem.h>
#include <RuntimeObjectSystem/IObjectFactorySystem.h>
#include <stdarg.h>
#include <assert.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdarg.h>
#include <thread>
#include <fstream>
#include "CompileGradExcut.h"
#include "Grad.h"


#ifdef _WIN32
#include "Windows.h"
#pragma warning( disable : 4996 4800 )
#endif

using namespace Core::CommonTool;

//Loger for rcc.
class StdioLogSystem : public ICompilerLogger
{
public:
	virtual void LogError(const char * format, ...);
	virtual void LogWarning(const char * format, ...);
	virtual void LogInfo(const char * format, ...);

protected:
	void LogInternal(const char * format, va_list args);
	char m_buff[100];
};

void StdioLogSystem::LogError(const char * format, ...)
{
	va_list args;
	va_start(args, format);
	LogInternal(format, args);
}

void StdioLogSystem::LogWarning(const char * format, ...)
{
	va_list args;
	va_start(args, format);
	LogInternal(format, args);
}

void StdioLogSystem::LogInfo(const char * format, ...)
{
	va_list args;
	va_start(args, format);
	LogInternal(format, args);
}
void StdioLogSystem::LogInternal(const char * format, va_list args)
{
	int result = vsnprintf(m_buff, 100 - 1, format, args);
	// Make sure there's a limit to the amount of rubbish we can output
	m_buff[100 - 1] = '\0';

	std::cout << m_buff;
#ifdef _WIN32
	OutputDebugStringA(m_buff);
#endif
}


namespace Core
{

	RuntimeObjectSystem * ObjectFuncParser::_sys=NULL;

	std::mutex ObjectFuncParser::_mutex;

	ObjectFuncParser::ObjectFuncParser()
	{
		InitRccSystem();
	}


	ObjectFuncParser::~ObjectFuncParser()
	{
	}

	IFunction* ObjectFuncParser::Parse(const string functionStr, string fileName)
	{
		Log::PushNDC("ObjectFuncParser");

		//Try to modify ObjectFunction.cpp.
		Log::Info("Function to parse: " + functionStr);;

		//Read all lines of cpp file.
		//string fileName = "..\\..\\..\\Core\\ObjectFunction.cpp";

		////The following path is for debuging in vs
		//string fileName = "..\\Core\\ObjectFunction.cpp";
		
		vector<string> lines;
		ifstream in(fileName);

		string line = "";
		if (in.is_open())
		{
			while (getline(in, line))
			{
				lines.push_back(line);
			}
		}

		else
		{
			throw ERROR;
		}


		//Find the position to insert function.
		string startMark = "//Insert Function";
		auto insertPos = find(lines.begin(), lines.end(), startMark);
		*(insertPos + 1) = "double fun=" + functionStr + ";";

		//Output a new file.
		ofstream out(fileName);
		for (auto line : lines)
		{
			out << line << endl;
		}
		out.flush();
		out.close();
		Log::Info("Finish insert function.");
		Log::Info("Modified object function " + functionStr);




		////Get object function from factory.
		//auto *objFunc = _sys->GetObjectFactorySystem()->GetConstructor("ObjectFunction")->Construct();
		//return dynamic_cast<ObjectFunction*>(objFunc);
		return NULL;

	
	}

	IFunction * ObjectFuncParser::DynamicCompile(const char * fileName)
	{
		Log::PushNDC("ObjectFuncParser");

		//Try to modify ObjectFunction.cpp.
		string toParse(fileName);
		Log::Info("Function to parse: " + toParse);

		//Dynamic compile.
		_sys->CompileAll(true);
		//Wait for finishing compilation.
		while (!_sys->GetIsCompiledComplete())
		{
		}
		_sys->LoadCompiledModule();

		Log::PopNDC();

		//Get object function from factory.
		auto *objFunc = _sys->GetObjectFactorySystem()->GetConstructor("ObjectFunction")->Construct();
		
		//auto *objFunc = _sys->GetObjectFactorySystem()->GetConstructor(fileName)->Construct();		
		return dynamic_cast<ObjectFunction*>(objFunc);
		
	}

	void ObjectFuncParser::InitRccSystem()
	{
		StdioLogSystem *pThreadsafeLog = new StdioLogSystem();

		_sys = new RuntimeObjectSystem();
		_sys->Initialise(pThreadsafeLog, NULL);
	}

	FunctionParser::FunctionParser()
	{
	}

	FunctionParser::~FunctionParser()
	{
	}

	IFunction * FunctionParser::Parse(const string functionStr, string fileName)
	{
		return nullptr;
	}

	IFunction * FunctionParser::DynamicCompile(const char* fileName)
	{
		//Log::PushNDC("ObjectFuncParser");

		////Try to modify ObjectFunction.cpp.
		//string toParse(fileName);
		//Log::Info("Function to parse: " + toParse);

		////Dynamic compile.
		//_sys->CompileAll(true);
		////Wait for finishing compilation.
		//while (!_sys->GetIsCompiledComplete())
		//{
		//}
		//_sys->LoadCompiledModule();

		//Log::PopNDC();

		////Get object function from factory.
		////auto *objFunc = _sys->GetObjectFactorySystem()->GetConstructor("ObjectFunction")->Construct();
		//auto *objFunc = _sys->GetObjectFactorySystem()->GetConstructor(fileName)->Construct();		
		//return dynamic_cast<CompileGradExcut*>(objFunc);
		return NULL;
		
	}



	GradPasser::GradPasser()
	{
		InitRccSystem();    
		_eraseExistingCodes_h = true;
		_eraseExistingCodes_cpp = true;
	}


	GradPasser::~GradPasser()
	{
	}

	IFunction * GradPasser::Parse(const string functionStr, const string fileName, int index,  string& className)
	{
		string indexStr = std::to_string(index);
		className = "Grad" + indexStr;

		    
		bool hState = WriteHeadlerFile(functionStr, fileName, index, className );

		bool cppState = WriteCPPFile(functionStr, fileName, index);

		//////Get object function from factory.
		//auto *objFunc = _sys->GetObjectFactorySystem()->GetConstructor(fileName)->Construct();
		//return dynamic_cast<ObjectFunction*>(objFunc);
		return NULL;

	}

	IFunction * GradPasser::DynamicCompile(const char * fileName)
	{
		Log::PushNDC("GradParser");

		//Try to modify ObjectFunction.cpp.
		string toParse(fileName);
		Log::Info("Function to parse: " + toParse);

		//Dynamic compile.
		_sys->CompileAll(true);
		//Wait for finishing compilation.
		while (!_sys->GetIsCompiledComplete())
		{
		}
		_sys->LoadCompiledModule();

		Log::PopNDC();

		//Get object function from factory.
		auto *gradPtr = _sys->GetObjectFactorySystem()->GetConstructor("Grad")->Construct();

		//auto *objFunc = _sys->GetObjectFactorySystem()->GetConstructor(fileName)->Construct();		
		return dynamic_cast<Grad*>(gradPtr);
		//return nullptr;
	}



	void GradPasser::InitRccSystem()
	{
		StdioLogSystem *pThreadsafeLog = new StdioLogSystem();

		_sys = new RuntimeObjectSystem();
		_sys->Initialise(pThreadsafeLog, NULL);
	}

	bool GradPasser::WriteHeadlerFile(const string gradStr, const string fileName, int index, string& className)
	{
		
		vector<string> lines;
		ifstream in(fileName+".h");

		string line = "";
		if (in.is_open())
		{
			while (getline(in, line))
			{
				lines.push_back(line);
			}
		}

		else
		{
			throw ERROR;
		}


		//Find the position to insert function.
		string startMark = "//Gradient Class Headler file-insert start";
		auto insertPos = find(lines.begin(), lines.end(), startMark);
																					  
		//Find the position to stop
		string endMark = "//Gradient Class Headler file-insert end";
		auto endPos = find(lines.begin(), lines.end(), endMark);

		 ////erase the old codes
		if (EraseExistingCodesH())
		{
			insertPos = lines.erase(insertPos + 1, endPos - 1);
			endPos = find(lines.begin(), lines.end(), endMark);
		}
		

		////The new codes that will be inserted
		string strIndex = std::to_string(index);
		className = "Grad" + strIndex;

		vector<string> newCodes;
		string newCode = "class\t" + className + ": public Grad";
		newCodes.push_back(newCode);
		newCode = "{";
		newCodes.push_back(newCode);
		newCode = "public:";
		newCodes.push_back(newCode);
		newCode = className + "(){};";
		newCodes.push_back(newCode);
		newCode = "~" + className + "(){};";
		newCodes.push_back(newCode);
		newCode = "virtual double Compute(const std::vector<double> &x) const;";
		newCodes.push_back(newCode);
		newCode = "};";
		newCodes.push_back(newCode);

		////insert new codes
		lines.insert(endPos - 1, newCodes.begin(), newCodes.end());

		bool success = false;

		//Output a new file.
		ofstream out;
		string hName = fileName + ".h";
		out.open(hName);

		if (out.is_open())
		{
			success = true;

			for (auto line : lines)
			{
				out << line << endl;
			}
			out.flush();
			out.close();

		}
		
		EraseExistingCodesH(false);

		return success;
	}
	bool GradPasser::WriteCPPFile(const string gradStr, const string fileName, int index)
	{
		vector<string> lines;
		ifstream in(fileName + ".cpp");

		string line = "";
		if (in.is_open())
		{
			while (getline(in, line))
			{
				lines.push_back(line);
			}
		}

		else
		{
			throw ERROR;
		}

		//Find the position to insert function.
		string startMark = "//Gradient Class CPP file-insert start";
		auto insertPos = find(lines.begin(), lines.end(), startMark);

		//Find the position to stop
		string endMark = "//Gradient Class CPP file-insert end";
		auto endPos = find(lines.begin(), lines.end(), endMark);

		////erase the old codes
		if (EraseExistingCodesCPP())
		{
			insertPos = lines.erase(insertPos + 1, endPos - 1);
			endPos = find(lines.begin(), lines.end(), endMark);
		}

		////The new codes that will be inserted
		string strIndex = std::to_string(index);
		string className = "Grad" + strIndex;

		vector<string> newCodes;
		string newCode = "double\t" + className + "::Compute(const std::vector<double>& x) const";
		newCodes.push_back(newCode);
		newCode = "{";
		newCodes.push_back(newCode);
		newCode = "double gradValue=" + gradStr + ";";
		newCodes.push_back(newCode);
		newCode = "return gradValue;";
		newCodes.push_back(newCode);
		newCode = "}";
		newCodes.push_back(newCode);
		//////Register this class for dynamic compiling
		newCode = "REGISTERCLASS(" + className + ");";
		newCodes.push_back(newCode);

		////insert new codes
		lines.insert(endPos - 1, newCodes.begin(), newCodes.end());

		//output the new file
		bool success = false;
		ofstream out;
		string cppName = fileName + ".cpp";
		out.open(cppName);


		if (out.is_open())
		{
			success = true;

			for (auto line : lines)
			{
				out << line << endl;
			}
			out.flush();
			out.close();

		}

		EraseExistingCodesCPP(false);

		return success;


		






	}


	ExcuteGradParser::ExcuteGradParser()
	{
		InitRccSystem();
	}


	ExcuteGradParser::~ExcuteGradParser()
	{
	}

	IFunction * ExcuteGradParser::Parse(const string functionStr, const string fileName, const vector<string> vecClassNames)
	{

		vector<string> lines;
		ifstream in(fileName);

		string line = "";
		if (in.is_open())
		{
			while (getline(in, line))
			{
				lines.push_back(line);
			}
		}

		else
		{
			throw ERROR;
		}


		//Find the position to insert function. The insert does not use this as benchmark, it insert right
		//above the mark of "insert end"
		string startMark = "//CompileGradExcut-insert start";
		auto insertPos = find(lines.begin(), lines.end(), startMark);
		//

		string endMark = "//CompileGradExcut-insert end";
		//Find the position to stop. The insert start from right above this mark.
		auto endPos = find(lines.begin(), lines.end(), endMark);
				
		////erase the old codes
		insertPos = lines.erase(insertPos+1,endPos-1);

		//insert the new codes
		for (size_t i = 0; i < vecClassNames.size(); i++)
		{
			endPos = find(lines.begin(), lines.end(), endMark); 
			insertPos = endPos - 1;

			string insertCode1 = vecClassNames[i] + "* ";
			string objectName = "grad" + std::to_string(int(i));
			
			insertCode1 += objectName + "=" + "new" + " " + vecClassNames[i] + ";";
			insertPos = lines.insert(insertPos, insertCode1);
			

			//string insertCode2 = "ObjFuncExcut::PushGradPnt(" + objectName + ");";
			string insertCode2 = "_gradDefin.push_back(" + objectName + ");";

			lines.insert(insertPos+1, insertCode2);

		}



		//Output a new file.
		ofstream out(fileName);
		for (auto line : lines)
		{
			out << line << endl;
		}
		out.flush();
		out.close();


		return NULL;
	}
	IFunction * ExcuteGradParser::DynamicCompile(const char * fileName)
	{
		Log::PushNDC("ExcutGradParser");

		//Try to modify ObjectFunction.cpp.
		string toParse(fileName);
		Log::Info("Function to parse: " + toParse);

		//Dynamic compile.
		_sys->CompileAll(true);
		//Wait for finishing compilation.
		while (!_sys->GetIsCompiledComplete())
		{
		}
		_sys->LoadCompiledModule();

		Log::PopNDC();

		//Get object function from factory.
		auto *CompileGradPtr = _sys->GetObjectFactorySystem()->GetConstructor("CompileGradExcut")->Construct();

		//auto *objFunc = _sys->GetObjectFactorySystem()->GetConstructor(fileName)->Construct();		
		return dynamic_cast<CompileGradExcut*>(CompileGradPtr);

		//return nullptr;
	}
	void ExcuteGradParser::InitRccSystem()
	{
		StdioLogSystem *pThreadsafeLog = new StdioLogSystem();

		_sys = new RuntimeObjectSystem();
		_sys->Initialise(pThreadsafeLog, NULL);
	}
}

