#pragma once
#include <string.h>
#include <vector>

namespace Core
{
	_declspec(dllexport) double TestOptimize(const std::vector<double>& lowerBound, std::vector<double>& var);
	_declspec(dllexport) void test();
}

