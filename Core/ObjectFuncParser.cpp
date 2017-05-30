#include "ObjectFuncParser.h"

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

	IFunction* ObjectFuncParser::Parse(const string functionStr)
	{
		Log::PushNDC("ObjectFuncParser");

		//Try to modify ObjectFunction.cpp.
		Log::Info("Function to parse: " + functionStr);;

		//Read all lines of cpp file.
		string filename = "..\\..\\..\\Core\\ObjectFunction.cpp";

		////The following path is for debuging in vs
		//string filename = "..\\Core\\ObjectFunction.cpp";
		
		vector<string> lines;
		ifstream in(filename);

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
		ofstream out(filename);
		for (auto line : lines)
		{
			out << line << endl;
		}
		out.flush();
		out.close();
		Log::Info("Finish insert function.");
		Log::Info("Modified object function " + functionStr);

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
		return dynamic_cast<ObjectFunction*>(objFunc);
	}

	void ObjectFuncParser::InitRccSystem()
	{
		StdioLogSystem *pThreadsafeLog = new StdioLogSystem();

		_sys = new RuntimeObjectSystem();
		_sys->Initialise(pThreadsafeLog, NULL);
	}

}

