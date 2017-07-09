#include "ObjectFunction.h"

#include "../Middleware/rcc/include/RuntimeObjectSystem/ObjectInterfacePerModule.h"
#include <math.h>
using namespace std;





double ObjectFunction::Compute(const std::vector<double> &x) const
{
	
//Insert Function
double fun=sqrt(x[1]);



	return fun;
}


REGISTERCLASS(ObjectFunction);




