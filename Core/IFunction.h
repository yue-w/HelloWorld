#pragma once
#include "PublicHeader.h"

namespace Core
{
	//Interface of function.
	class IFunction
	{
	public:
		IFunction();
		~IFunction();

		virtual double Compute(const vector<double>& x) const =0;
	};
}


