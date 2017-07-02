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
Grad2* grad2=new Grad2;
_gradDefin.push_back(grad2);
Grad3* grad3=new Grad3;
_gradDefin.push_back(grad3);

//CompileGradExcut-insert end

}



double CompileGradExcut::Compute(const std::vector<double>& x) const
{
	return 0.0;
}



