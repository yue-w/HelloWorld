#include "InequalCnstrntFunc.h"
#include "../Middleware/rcc/include/RuntimeObjectSystem/ObjectInterfacePerModule.h"

//Register the name of the class.
REGISTERCLASS(InequalCnstrntFunc);


double InequalCnstrntFunc::Compute(const std::vector<double>& x) const
{
	return 0.0;
}


//Inequal Cnst Class CPP file-insert start
double	InequalCnstrntFunc0::Compute(const std::vector<double>& x) const
{
double inequalCnst=8*x[0]*x[0]*x[0]-x[1];
return inequalCnst;
}
REGISTERCLASS(InequalCnstrntFunc0);
double	InequalCnstrntFunc1::Compute(const std::vector<double>& x) const
{
double inequalCnst=(1-x[0])*(1-x[0])*(1-x[0])-x[1];
return inequalCnst;
}
REGISTERCLASS(InequalCnstrntFunc1);

//Inequal Cnst Class CPP file-insert end
