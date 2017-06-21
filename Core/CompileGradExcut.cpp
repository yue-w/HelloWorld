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
ObjFuncExcut::PushGradPnt(grad0);
Grad1* grad1=new Grad1;
ObjFuncExcut::PushGradPnt(grad1);

//CompileGradExcut-insert end
	
}

double CompileGradExcut::Compute(const std::vector<double>& x) const
{
	return 0.0;
}



