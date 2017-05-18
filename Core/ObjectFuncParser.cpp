#include "ObjectFuncParser.h"

#include "ObjectFunction.h"
#include "Log.h"

#include <RuntimeCompiler/ICompilerLogger.h>
#include <RuntimeObjectSystem/RuntimeObjectSystem.h>
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
		//Try to modify ObjectFunction.cpp.
		Log::Info("Function to parse: " + functionStr);;

		//Read all lines of cpp file.
		string filename = "E:\\Projects\\HelloWorld\\Core\\ObjectFunction.cpp";
		vector<string> lines;
		ifstream in(filename);
		string line = "";
		while (getline(in,line))
		{
			lines.push_back(line);
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

		_sys->CompileAll(true);
		while (!_sys->GetIsCompiledComplete())
		{

		}

		//Wait for compilation.
		//_t.join();

		ObjectFunction *objFunc = new ObjectFunction();
		return objFunc;
	}

	void ObjectFuncParser::InitRccSystem()
	{
		StdioLogSystem *pThreadsafeLog = new StdioLogSystem();

		_sys = new RuntimeObjectSystem();
		_sys->Initialise(pThreadsafeLog, NULL);
		//Run loop in another thread.
		//_t = std::thread(&LoopRunRcc);
	}

	void ObjectFuncParser::LoopRunRcc()
	{
// 		ThreadLocker locker(_mutex);
// 		while (true)
// 		{
// 			Sleep(1000);
// 
// 			cout << "hi" << endl;
// 			if (_sys->GetIsCompiledComplete())
// 			{
// 				Log::Info("The cpp is compiled.");
// 				break;
// 			}
// 		}
	}

}

