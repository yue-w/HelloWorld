#pragma once

#include "IFunction.h"
#include "../Middleware/rcc/include/RuntimeObjectSystem/IObject.h"


class ObjectFunction : public Core::IFunction, public IObject
{
public:
	ObjectFunction() {};
	~ObjectFunction() {};

	virtual double Compute(const vector<double>& x) const;

	virtual PerTypeObjectId GetPerTypeId() const { return 0; }
	virtual IObjectConstructor* GetConstructor() const { return NULL; };
	virtual const char* GetTypeName() const { return ""; };
};

