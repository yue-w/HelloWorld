#pragma once
#include "IFunction.h"
#include "../Middleware/rcc/include/RuntimeObjectSystem/IObject.h"


class Grad : public Core::IFunction, public IObject
{
public:
	Grad() {};
	~Grad() {};
	virtual double Compute(const std::vector<double> &x) const;

	virtual PerTypeObjectId GetPerTypeId() const { return 0; }
	virtual IObjectConstructor* GetConstructor() const { return NULL; };
	virtual const char* GetTypeName() const { return ""; };
};


