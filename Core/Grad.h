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
};class Grad0: public Grad
{
public:
Grad0(){};
~Grad0(){};
virtual double Compute(const std::vector<double> &x) const;
};
class Grad1: public Grad
{
public:
Grad1(){};
~Grad1(){};
virtual double Compute(const std::vector<double> &x) const;
};
