#include "CompileGradExcut.h"

#include "../Middleware/rcc/include/RuntimeObjectSystem/ObjectInterfacePerModule.h"
#include "ObjFuncExcut.h"
#include "Grad.h"

REGISTERCLASS(CompileGradExcut);
CompileGradExcut::CompileGradExcut()
{
}


CompileGradExcut::~CompileGradExcut()
{
}

void CompileGradExcut::PushGradPointer()
{
//CompileGradExcut-insert start
Grad0* grad0=new Grad0;
_gradDefin.push_back(grad0);
Grad1* grad1=new Grad1;
_gradDefin.push_back(grad1);

//CompileGradExcut-insert end

}

void CompileGradExcut::PushGradPointer_InequalfuncGrad()
{
//Compile Inequal Grad -insert start
Grad11* grad0=new Grad11;
_temGrad.push_back(grad0);
Grad12* grad1=new Grad12;
_temGrad.push_back(grad1);
Grad21* grad2=new Grad21;
_temGrad.push_back(grad2);
Grad22* grad3=new Grad22;
_temGrad.push_back(grad3);

//Compile Inequal Grad -insert end
//_gradDefinInequalFunc.push_back(_temGrad);
}



double CompileGradExcut::Compute(const std::vector<double>& x) const
{
	return 0.0;
}



