#pragma once
//#include"../Middleware/nlopt/include/nlopt.hpp"
#include "OptimizationCommand.h"
using namespace Core;



namespace testCPPQml
{
	

_declspec(dllexport) double TestOptimize(const std::vector<double>& lowerBound, std::vector<double>& var);
_declspec(dllexport) void test();

}