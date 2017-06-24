#pragma once
#include "IFunction.h"
#include "../Middleware/rcc/include/RuntimeObjectSystem/IObject.h"

class Grad;
class CompileGradExcut: public Core::IFunction, public IObject
{
private:
	
	vector<Grad*> _gradDefin;
public:
	CompileGradExcut();
	~CompileGradExcut();

	////This function should be virtual so that it can be called after dynamic compilation.
	virtual void PushGradPointer();

	

	virtual PerTypeObjectId GetPerTypeId() const { return 0; }
	virtual IObjectConstructor* GetConstructor() const { return NULL; };
	virtual const char* GetTypeName() const { return ""; };

	vector<Grad*> GetGradDefineVector() { return _gradDefin; };

	virtual double Compute(const std::vector<double> &x) const;
};

