#include "ObjectFunction.h"

#include "../Middleware/rcc/include/RuntimeObjectSystem/ObjectInterfacePerModule.h"
#include <math.h>


double ObjectFunction::objectFunction(const std::vector<double> &x) const
{
	
	//Insert Function
double fun=(x[0]-1)*(x[0]-1)+(x[1]-4)*(x[1]-4);



	return fun;
}

REGISTERCLASS(ObjectFunction);

