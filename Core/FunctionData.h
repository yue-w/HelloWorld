#pragma once
#include "PublicHeader.h"

namespace Core
{
	//////////////////////////////////////////////////////////////////////////
	//Function data from UI.
	//Include objective function, gradient function...
	//////////////////////////////////////////////////////////////////////////
	class FunctionData
	{
		string _objFun;
		string _gradFun;
	public:
		FunctionData();
		~FunctionData();

		string ObjFun() const { return _objFun; }
		void ObjFun(string val) { _objFun = val; }
		string GradFun() const { return _gradFun; }
		void GradFun(string val) { _gradFun = val; }
	};
}


