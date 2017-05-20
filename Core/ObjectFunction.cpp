#include "ObjectFunction.h"

#include "../Middleware/rcc/include/RuntimeObjectSystem/ObjectInterfacePerModule.h"



double ObjectFunction::Compute(const vector<double>& x) const
{
	auto x0 = x.front();
	//Insert Function
double fun=x0*6;

	cout << x0 << endl;
	cout << fun << endl;
	return fun;
}

REGISTERCLASS(ObjectFunction);

