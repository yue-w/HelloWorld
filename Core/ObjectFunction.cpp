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
	//Insert Function
	return 0;
}

REGISTERCLASS(ObjectFunction);

