#pragma once
#include <string.h>
#include <vector>

namespace Core
{
	_declspec(dllexport) void TestOptimize(const std::vector<std::string>& lowerBound, std::vector<double>& var);
}

