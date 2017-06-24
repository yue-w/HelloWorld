#include "NloptPara.h"



NloptPara::NloptPara()
{
}


NloptPara::~NloptPara()
{
}

void NloptPara::SetGradDefine(const vector<Grad*> val)
{
	 _gradDefin = val; 
}
