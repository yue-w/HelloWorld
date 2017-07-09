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

		void Parse(const string functionStr, const string fileName);

		virtual IFunction* DynamicCompile(const char* fileName);

	};

	class ObjectFuncParser : public FunctionParser
	{

	public:
		ObjectFuncParser();
		~ObjectFuncParser();

		//Parser string to a function.
		void Parse(const string functionStr, const string fileName);
		IFunction* DynamicCompile(const char* fileName);

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

		void Parse(const string functionStr, const string fileName, int index, string& className);
		IFunction* DynamicCompile(const char* fileName);

	private:

		void InitRccSystem();

		//Write .h file
		bool WriteHeadlerFile(const string gradStr, const string fileName, int index, string& className);

		//write .cpp file
		bool WriteCPPFile(const string gradStr, const string fileName, int index, string& className);

		bool _eraseExistingCodes_h;
		bool _eraseExistingCodes_cpp;
	};

	class InequalConstrtFunParser :
		public FunctionParser
	{

	public:
		InequalConstrtFunParser();
		~InequalConstrtFunParser();

		void Parse(const string functionStr, const string fileName, int index, string& className);
		IFunction* DynamicCompile(const char* fileName);

		bool EraseExistingCodesH() { return _eraseExistingCodes_h; }
		void EraseExistingCodesH(const bool value) { _eraseExistingCodes_h = value; }

		bool EraseExistingCodesCPP() { return _eraseExistingCodes_cpp; }
		void EraseExistingCodesCPP(const bool value) { _eraseExistingCodes_cpp = value; }

	private:
		void InitRccSystem();
		//Write .h file
		bool WriteHeadlerFile(const string gradStr, const string fileName, int index, string& className);

		//write .cpp file
		bool WriteCPPFile(const string gradStr, const string fileName, int index, string& className);

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
		void Parse(const string fileName, const vector<string> vecClassNames);

		void ParseInequalGrad(const string fileName, const vector<string> vecClassNames);

		IFunction* DynamicCompile(const char* fileName);

	private:

		void InitRccSystem();
	};

	class ExcuteInequalConstrtParser : public FunctionParser
	{
	public:
		ExcuteInequalConstrtParser();
		~ExcuteInequalConstrtParser();
		void Parse(const string fileName, const vector<string> vecClassNames);
		IFunction* DynamicCompile(const char* fileName);

	private:

		void InitRccSystem();
	};
}

