#pragma once
#include "PublicHeader.h"

class RuntimeObjectSystem;
namespace Core
{
	class IFunction;

	class ObjectFuncParser
	{
		static RuntimeObjectSystem *_sys;
		static bool _compiled;
	public:
		ObjectFuncParser();
		~ObjectFuncParser();

		//Parse string to a function.
		IFunction* Parse(const string functionStr);


	private:

		void InitRccSystem();

		static void LoopRunRcc();
	};

}

