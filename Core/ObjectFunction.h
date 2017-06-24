#pragma once

#include "IFunction.h"
#include "../Middleware/rcc/include/RuntimeObjectSystem/IObject.h"


class ObjectFunction : public Core::IFunction, public IObject
{
public:
	ObjectFunction() {};
	~ObjectFunction() {};

	//virtual double Compute(const vector<double>& x) const;
	//virtual double objectFunction(const std::vector<double> &x, std::vector<double> &grad, void *my_func_data) const;
	virtual double Compute(const std::vector<double> &x) const;////This function should be virtual so that it can be called after dynamic compilation.

	virtual PerTypeObjectId GetPerTypeId() const { return 0; }
	virtual IObjectConstructor* GetConstructor() const { return NULL; };
	virtual const char* GetTypeName() const { return ""; };
	
};

