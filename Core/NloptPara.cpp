#include "NloptPara.h"
#include "ObjectFunction.h"


NloptPara::NloptPara()
{
	//_objFunDefin = new ObjectFunction();
}


NloptPara::~NloptPara()
{
}

void NloptPara::SetGradDefine(const vector<Grad*> val)
{
	 _gradDefin = val; 
}

NloptPara_OneInequalityConstraint::NloptPara_OneInequalityConstraint(InequalCnstrntFunc* ineqFun, vector<Grad*> gradDefine):_inequalityFunc(ineqFun),_gradDefine(gradDefine)
{
}
