#pragma once
#include "PublicHeader.h"
#include "ThreadLocker.h"

class RuntimeObjectSystem;
namespace Core
{
	class IFunction;

	class FunctionParser
	{
	public:
		static RuntimeObjectSystem *_sys;
		static mutex _mutex;

		std::thread _t;

	public:
		FunctionParser();
		~FunctionParser();

		IFunction* Parse(const string functionStr, const string fileName);

		IFunction* DynamicCompile(const char* fileName);

	};

	class ObjectFuncParser : public FunctionParser
	{

	public:
		ObjectFuncParser();
		~ObjectFuncParser();

		//Parser string to a function.
		IFunction* Parse(const string functionStr, const string fileName);


	private:

		void InitRccSystem();
	};

	class GradPasser :
		public FunctionParser
	{
	public:
		GradPasser();
		~GradPasser();

		IFunction* Parse(const string gradStr, const string ,int index);
	private:

		void InitRccSystem();

		//Write .h file
		bool WriteHeadlerFile(const string gradStr, const string, int index);

		//write .cpp file
		bool WriteCPPFile(const string gradStr, const string, int index);


	};


	class ExcuteGradParser : public FunctionParser
	{
	public:
		ExcuteGradParser();
		~ExcuteGradParser();

		IFunction* Parse(const string functionStr, const string fileName);
	};
}

