#pragma once
#include "IFunction.h"
#include "../Middleware/rcc/include/RuntimeObjectSystem/IObject.h"

class Grad;

class CompileGradExcut: public Core::IFunction, public IObject
{
private:
	
	vector<Grad*> _gradDefin;

	vector<vector<Grad*>> _gradDefinInequalFunc;
	////Gradient that in one dimentional vector, which will be changed to two dimentional vector
	vector<Grad*> _temGrad;
public:
	CompileGradExcut();
	~CompileGradExcut();

	////This function should be virtual so that it can be called after dynamic compilation.
	virtual void PushGradPointer();

	////
	virtual void PushGradPointer_InequalfuncGrad();

	virtual PerTypeObjectId GetPerTypeId() const { return 0; }
	virtual IObjectConstructor* GetConstructor() const { return NULL; };
	virtual const char* GetTypeName() const { return ""; };

	vector<Grad*> GetGradDefineVector() { return _gradDefin; };

	vector<Grad*> GetTemGrad() const { return _temGrad; }

	vector<vector<Grad*>> GetGradDefineVectorInequal() { return _gradDefinInequalFunc; }
	void SetGradDefineVectorInequal(const vector<vector<Grad*>> val) { _gradDefinInequalFunc = val; }

	virtual double Compute(const std::vector<double> &x) const;
};

