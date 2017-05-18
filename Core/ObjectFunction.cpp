#include "ObjectFunction.h"

#include <RuntimeObjectSystem/ObjectInterfacePerModule.h>

ObjectFunction::ObjectFunction()
{
}


ObjectFunction::~ObjectFunction()
{
}

double ObjectFunction::Compute(const vector<double>& x) const
{
	auto x0 = x.front();
	//Insert Function
double fun=x0;
	return fun;
}

REGISTERCLASS(ObjectFunction);

