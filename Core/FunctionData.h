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
		//Object function
		string _objFun;

		////inequal constraint functions
		vector<string> _ineqCnstrntFun;

		////equal constraint functions
		vector<string> _eqCnstrntFuns;

		
	public:
		FunctionData();
		~FunctionData();

		string ObjFun() const { return _objFun; }
		void ObjFun(string val) { _objFun = val; }

		 void InEqualConstrnFun(vector<string> val) { _ineqCnstrntFun = val; }
		 vector<string>  InEqualConstrnFun()const { return _ineqCnstrntFun; }



	};
}


