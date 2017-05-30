#include "ObjectFunction.h"

#include "../Middleware/rcc/include/RuntimeObjectSystem/ObjectInterfacePerModule.h"
#include <math.h>


double ObjectFunction::objectFunction(const std::vector<double> &x, std::vector<double> &grad, void *my_func_data) const
{
	
	//Insert Function
double fun=x[0]*x[0]+x[1]*x[1];



	return fun;
}

REGISTERCLASS(ObjectFunction);

