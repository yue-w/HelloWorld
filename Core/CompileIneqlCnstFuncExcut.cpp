#include "CompileIneqlCnstFuncExcut.h"
#include "InequalCnstrntFunc.h"
#include "../Middleware/rcc/include/RuntimeObjectSystem/ObjectInterfacePerModule.h"

//Register the name of the class.
REGISTERCLASS(CompileIneqlCnstFuncExcut);

CompileIneqlCnstFuncExcut::CompileIneqlCnstFuncExcut()
{
}


CompileIneqlCnstFuncExcut::~CompileIneqlCnstFuncExcut()
{
}

void CompileIneqlCnstFuncExcut::PushInequFuncPointer()
{
//CompileInequalCnstFunc-insert start
InequalCnstrntFunc0* inequal0=new InequalCnstrntFunc0;
_ineqFuncDefin.push_back(inequal0);
InequalCnstrntFunc1* inequal1=new InequalCnstrntFunc1;
_ineqFuncDefin.push_back(inequal1);

//CompileInequalCnstFunc-insert end
}

double CompileIneqlCnstFuncExcut::Compute(const std::vector<double>& x) const
{
	return 0.0;
}
