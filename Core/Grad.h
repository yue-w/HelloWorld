#pragma once
#include "IFunction.h"
#include "../Middleware/rcc/include/RuntimeObjectSystem/IObject.h"


class Grad : public Core::IFunction, public IObject
{
public:
	Grad() {};
	~Grad() {};

	////This function should be virtual so that it can be called after dynamic compilation.
	 virtual double Compute(const std::vector<double> &x) const;

	virtual PerTypeObjectId GetPerTypeId() const { return 0; }
	virtual IObjectConstructor* GetConstructor() const { return NULL; };
	virtual const char* GetTypeName() const { return ""; };
public:
	
};


//Gradient Class Headler file-insert start
class	Grad0: public Grad
{
public:
Grad0(){};
~Grad0(){};
virtual double Compute(const std::vector<double> &x) const;
};
class	Grad1: public Grad
{
public:
Grad1(){};
~Grad1(){};
virtual double Compute(const std::vector<double> &x) const;
};
class	Grad11: public Grad
{
public:
Grad11(){};
~Grad11(){};
virtual double Compute(const std::vector<double> &x) const;
};
class	Grad12: public Grad
{
public:
Grad12(){};
~Grad12(){};
virtual double Compute(const std::vector<double> &x) const;
};
class	Grad21: public Grad
{
public:
Grad21(){};
~Grad21(){};
virtual double Compute(const std::vector<double> &x) const;
};
class	Grad22: public Grad
{
public:
Grad22(){};
~Grad22(){};
virtual double Compute(const std::vector<double> &x) const;
};

//Gradient Class Headler file-insert end

//class InequalCnsrntGrad: public Grad
//{
//public:
//	InequalCnsrntGrad() {};
//	~InequalCnsrntGrad() {};
//};
