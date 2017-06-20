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
		auto insertPos = find(lines.begin(), lines.end(), "	//Insert Function");
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




		//Get object function from factory.
		auto *objFunc = _sys->GetObjectFactorySystem()->GetConstructor("ObjectFunction")->Construct();
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
		//auto *objFunc = _sys->GetObjectFactorySystem()->GetConstructor("ObjectFunction")->Construct();
		auto *objFunc = _sys->GetObjectFactorySystem()->GetConstructor(fileName)->Construct();		
		return dynamic_cast<CompileGradExcut*>(objFunc);
		
	}



	GradPasser::GradPasser()
	{
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



	void GradPasser::InitRccSystem()
	{
		StdioLogSystem *pThreadsafeLog = new StdioLogSystem();

		_sys = new RuntimeObjectSystem();
		_sys->Initialise(pThreadsafeLog, NULL);
	}

	bool GradPasser::WriteHeadlerFile(const string gradStr, const string fileName, int index, string& className)
	{
		bool success=false;

		ofstream myfile;
		string hName = fileName + ".h";
		myfile.open(hName, ios::app);

		/*
		class Grad : public Core::IFunction, public IObject
		{
		public:
		Grad();
		~Grad();
		virtual double Compute(const std::vector<double> &x) const;

		virtual PerTypeObjectId GetPerTypeId() const { return 0; }
		virtual IObjectConstructor* GetConstructor() const { return NULL; };
		virtual const char* GetTypeName() const { return ""; };
		};

		*/
		string strIndex = std::to_string(index);
		className = "Grad" + strIndex;

		////write
		myfile << "class"<<" "<<className<< ": public Grad"<<endl;
		myfile << "{"<<endl;
		myfile << "public:" << endl;
		myfile << className << "(){};" << endl;
		myfile <<"~"<< className << "(){};" << endl;
		myfile << "virtual double Compute(const std::vector<double> &x) const;" << endl;
		//myfile << "virtual PerTypeObjectId GetPerTypeId() const { return 0; }" << endl;
		//myfile << "virtual IObjectConstructor* GetConstructor() const { return NULL; };" << endl;
		//myfile << "virtual const char* GetTypeName() const { return \" \"; };" << endl;
		myfile << "};" << endl;


		return success;
	}
	bool GradPasser::WriteCPPFile(const string gradStr, const string fileName, int index)
	{
		bool success = false;
		ofstream myfile;
		string cppName = fileName + ".cpp";
		myfile.open(cppName, ios::app);

		string strIndex = std::to_string(index);
		string className = "Grad" + strIndex;

		/*
		double Grad::Compute(const std::vector<double>& x) const
		{

		//insert grad here
		double gradValue = 0.0;

		return gradValue;
		}
		*/

		myfile << "double" << " " << className << "::Compute(const std::vector<double>& x) const" << endl;
		myfile << "{" << endl;
		myfile << "double gradValue=" << gradStr << ";" << endl;
		myfile << "return gradValue;"<<endl;
		myfile << "}" << endl;
		////Register this class for dynamic compiling
		myfile << "REGISTERCLASS(" << className << ");" << endl;
		return success;
	}


	ExcuteGradParser::ExcuteGradParser()
	{

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


		//Find the position to insert function.
		auto insertPos = find(lines.begin(), lines.end(),"\t//&*)(%$#-insert start" );//"	//&*)(%$#-insert start"
		//

		//Find the position to stop
		auto endPos = find(lines.begin(), lines.end(),"\t//&*)(%$#-insert end" );  //"	//&*)(%$#-insert end"
				
		////erase the old codes
		insertPos = lines.erase(insertPos+1,endPos-1);

		//insert the new codes
		for (size_t i = 0; i < vecClassNames.size(); i++)
		{
			endPos = find(lines.begin(), lines.end(), "\t//&*)(%$#-insert end");  //"	//&*)(%$#-insert end"
			insertPos = endPos - 1;

			string insertCode1 = vecClassNames[i] + "* ";
			string objectName = "grad" + std::to_string(int(i));
			
			insertCode1 += objectName + "=" + "new" + " " + vecClassNames[i] + ";";
			insertPos = lines.insert(insertPos, insertCode1);
			

			string insertCode2 = "ObjFuncExcut::PushGradPnt(" + objectName + ");";
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



		////Get object function from factory.
		//auto *objFunc = _sys->GetObjectFactorySystem()->GetConstructor("ObjectFunction")->Construct();
		//return dynamic_cast<ObjectFunction*>(objFunc);

		return NULL;
	}
	void ExcuteGradParser::InitRccSystem()
	{
		StdioLogSystem *pThreadsafeLog = new StdioLogSystem();

		_sys = new RuntimeObjectSystem();
		_sys->Initialise(pThreadsafeLog, NULL);
	}
}

