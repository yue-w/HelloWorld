#pragma once
#include "IFunction.h"
#include "../Middleware/rcc/include/RuntimeObjectSystem/IObject.h"
class CompileGradExcut: public Core::IFunction, public IObject
{
public:
	CompileGradExcut();
	~CompileGradExcut();

	void PushGradPointer();

	

	virtual PerTypeObjectId GetPerTypeId() const { return 0; }
	virtual IObjectConstructor* GetConstructor() const { return NULL; };
	virtual const char* GetTypeName() const { return ""; };

	virtual double Compute(const std::vector<double> &x) const;
};

