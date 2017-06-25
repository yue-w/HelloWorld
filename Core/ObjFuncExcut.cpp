#include "ObjFuncExcut.h"
#include "NloptPara.h"
#include "Grad.h"

//:_dataWapper(new DataWrapper(*dataWrapper))
//ObjFuncExcut::ObjFuncExcut(const ObjectFunction* _objFunDefin):_objFunDefin(new ObjectFunction (*_objFunDefin))
//{
//}

//ObjectFunction* ObjFuncExcut::_objFunDefin = new ObjectFunction();
//vector<Grad*> ObjFuncExcut::_gradDefin ;

ObjFuncExcut::ObjFuncExcut() 
{
	//_objFunDefin = new ObjectFunction();
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
	////data can be passed by my_func_data
	NloptPara * para = reinterpret_cast<NloptPara *> (my_func_data);
	
	if (!grad.empty()) {
		for (size_t i = 0; i<grad.size(); i++)
		{
			Grad* gradDef =	para->GetOneGradDefine(i);
			grad[i] = gradDef->Compute(x);
		}		
	}

	//double obj = _objFunDefin->Compute(x);
	ObjectFunction* objFunDefin = para->GetObjectFunction();

	double obj = objFunDefin->Compute(x);
	return obj;
}

void ObjFuncExcut::PushGrad(Grad * gradPnt)
{
	_gradDefin.push_back(gradPnt);
}
