#pragma once
#include "PublicHeader.h"

namespace Core
{
	//Interface of function.
	class IFunction
	{
	public:
		IFunction() {};
		~IFunction() {};

		//virtual double objectFunction(const std::vector<double> &x, std::vector<double> &grad, void *my_func_data) const =0;
		virtual double objectFunction(const std::vector<double> &x) const = 0;
	};
}


