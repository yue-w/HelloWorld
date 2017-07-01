#pragma once
#include "PublicHeader.h"

namespace Core
{
	//////////////////////////////////////////////////////////////////////////
	//Function data from UI.
	//Include objective function, gradient function, and constraint functions...
	//////////////////////////////////////////////////////////////////////////
	class FunctionData
	{
		string _objFun;
		string _gradFun;
		////inequal constraint functions
		vector<string> _ineqCnstrntFun;
		////equal constraint functions
		vector<string> _eqCnstrntFuns;

		
	public:
		FunctionData();
		~FunctionData();

		string ObjFun() const { return _objFun; }
		void ObjFun(string val) { _objFun = val; }
		string GradFun() const { return _gradFun; }
		void GradFun(string val) { _gradFun = val; }
	};
}


