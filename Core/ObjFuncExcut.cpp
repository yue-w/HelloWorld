#include "ObjFuncExcut.h"


//:_dataWapper(new DataWrapper(*dataWrapper))
//ObjFuncExcut::ObjFuncExcut(const ObjectFunction* _objFunDefin):_objFunDefin(new ObjectFunction (*_objFunDefin))
//{
//}

ObjectFunction* ObjFuncExcut::_objFunDefin = new ObjectFunction();
vector<Grad*> ObjFuncExcut::_gradDefin ;

ObjFuncExcut::ObjFuncExcut() 
{
}


ObjFuncExcut::~ObjFuncExcut()
{
}

double ObjFuncExcut::ObjFunction(const std::vector<double>& x, std::vector<double>& grad, void * my_func_data)
{
	//if (!grad.empty()) {
	//	grad[0] = 2*x[0]-2;
	//	grad[1] = 2*x[1]-8;
	//}
	
	if (!grad.empty()) {
		for (size_t i = 0; i<grad.size(); i++)
		{
			grad[i] = _gradDefin[i]->Compute(x);
		}		
	}

	double obj = _objFunDefin->Compute(x);
	return obj;
}
