#include "ObjectFuncParser.h"

#include "ObjectFunction.h"

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

	RuntimeObjectSystem * ObjectFuncParser::_sys;

	bool ObjectFuncParser::_compiled = false;

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

		//Read all lines of cpp file.
		string filename = "ObjectFunction.cpp";
		vector<string> lines;
		ifstream in(filename);
		string line = "";
		while (getline(in,line))
		{
			lines.push_back(line);
		}
		//Find the position to insert function.
		auto insertPos = find(lines.begin(), lines.end(), "	//Insert Function");
		lines.insert(insertPos, functionStr);
		//Output a new file.
		ofstream out(filename);
		for (auto line : lines)
		{
			out << line << endl;
		}
		out.flush();

		//Wait for compilation.
		while (!_compiled);

		ObjectFunction *objFunc = new ObjectFunction();
		return objFunc;
	}

	void ObjectFuncParser::InitRccSystem()
	{
		StdioLogSystem *pThreadsafeLog = new StdioLogSystem();

		auto _sys = new RuntimeObjectSystem();
		_sys->Initialise(pThreadsafeLog, NULL);
		//Run loop in another thread.
		std::thread t(&LoopRunRcc);
	}

	void ObjectFuncParser::LoopRunRcc()
	{
		while (true)
		{
			Sleep(1000);

			if (_sys->GetIsCompiledComplete())
			{
				_compiled = true;
			}
		}
	}

}

