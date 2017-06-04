#include "ObjFuncExcut.h"


//:_dataWapper(new DataWrapper(*dataWrapper))
//ObjFuncExcut::ObjFuncExcut(const ObjectFunction* _objFunDefin):_objFunDefin(new ObjectFunction (*_objFunDefin))
//{
//}

ObjectFunction *ObjFuncExcut::_objFunDefin = new ObjectFunction();


ObjFuncExcut::ObjFuncExcut() 
{
}


ObjFuncExcut::~ObjFuncExcut()
{
}

double ObjFuncExcut::objectFunction(const std::vector<double>& x, std::vector<double>& grad, void * my_func_data)
{
	if (!grad.empty()) {
		grad[0] = 2*x[0]-2;
		grad[1] = 2*x[1]-8;
	}
	
	double obj = _objFunDefin->objectFunction(x);
	return obj;
}
