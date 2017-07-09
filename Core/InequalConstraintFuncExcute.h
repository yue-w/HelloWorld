#pragma once
#include "PublicHeader.h"
//#include "InequalCnstrntFunc.h"
class InequalConstraintFuncExcute
{
public:
	InequalConstraintFuncExcute();
	~InequalConstraintFuncExcute();

	static double InequalConstraintFunction(const std::vector<double> &x, std::vector<double> &grad, void *my_func_data);
};

