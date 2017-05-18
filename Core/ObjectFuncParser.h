#pragma once
#include "PublicHeader.h"
#include "ThreadLocker.h"

class RuntimeObjectSystem;
namespace Core
{
	class IFunction;

	class ObjectFuncParser
	{
		static RuntimeObjectSystem *_sys;
		static mutex _mutex;

		std::thread _t;
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

