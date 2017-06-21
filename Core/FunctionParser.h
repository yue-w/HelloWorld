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

		bool EraseExistingCodesH() { return _eraseExistingCodes_h; }
		void EraseExistingCodesH(const bool value) { _eraseExistingCodes_h = value; }

		bool EraseExistingCodesCPP() { return _eraseExistingCodes_cpp; }
		void EraseExistingCodesCPP(const bool value) { _eraseExistingCodes_cpp = value; }

		IFunction* Parse(const string gradStr, const string ,int index, string& className);
	private:

		void InitRccSystem();

		//Write .h file
		bool WriteHeadlerFile(const string gradStr, const string, int index, string& className);

		//write .cpp file
		bool WriteCPPFile(const string gradStr, const string, int index);

		bool _eraseExistingCodes_h;
		bool _eraseExistingCodes_cpp;
	};


	class ExcuteGradParser : 
		public FunctionParser
	{
	public:
		ExcuteGradParser();
		~ExcuteGradParser();

		/*vecClassNames stores all the names of 
		the class that have been compiled dynamically by GradPasser::parse*/
		IFunction* Parse(const string functionStr, const string fileName, const vector<string> vecClassNames);
	private:

		void InitRccSystem();
	};
}

