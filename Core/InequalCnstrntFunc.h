#pragma once
#include "IFunction.h"
#include "../Middleware/rcc/include/RuntimeObjectSystem/IObject.h"

class InequalCnstrntFunc : public Core::IFunction, public IObject
{
public:
	InequalCnstrntFunc() {};
	~InequalCnstrntFunc() {};

	////This function should be virtual so that it can be called after dynamic compilation.
	virtual double Compute(const std::vector<double> &x) const;

	virtual PerTypeObjectId GetPerTypeId() const { return 0; }
	virtual IObjectConstructor* GetConstructor() const { return NULL; };
	virtual const char* GetTypeName() const { return ""; };

};


//Inequal Constraint Function Class Headler file-insert start
class	InequalCnstrntFunc0: public InequalCnstrntFunc
{
public:
InequalCnstrntFunc0(){};
~InequalCnstrntFunc0(){};
virtual double Compute(const std::vector<double> &x) const;
};
class	InequalCnstrntFunc1: public InequalCnstrntFunc
{
public:
InequalCnstrntFunc1(){};
~InequalCnstrntFunc1(){};
virtual double Compute(const std::vector<double> &x) const;
};

//Inequal Constraint Function Class Headler file-insert end
