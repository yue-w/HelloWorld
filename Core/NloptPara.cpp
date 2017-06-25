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
