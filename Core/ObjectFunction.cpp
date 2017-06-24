#include "ObjectFunction.h"

#include "../Middleware/rcc/include/RuntimeObjectSystem/ObjectInterfacePerModule.h"
#include <math.h>

REGISTERCLASS(ObjectFunction);



double ObjectFunction::Compute(const std::vector<double> &x) const
{
	
//Insert Function
double fun=(x[0]-1)*(x[0]-1)+(x[1]-4)*(x[1]-4);



	return fun;
}





