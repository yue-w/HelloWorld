#pragma once
#include "IFunction.h"
#include "../Middleware/rcc/include/RuntimeObjectSystem/IObject.h"

class InequalCnstrntFunc;
class CompileIneqlCnstFuncExcut : public Core::IFunction, public IObject
{
private:

	vector<InequalCnstrntFunc*> _ineqFuncDefin;

public:
	CompileIneqlCnstFuncExcut();
	~CompileIneqlCnstFuncExcut();

	////This function should be virtual so that it can be called after dynamic compilation.
	virtual void PushInequFuncPointer();

	virtual PerTypeObjectId GetPerTypeId() const { return 0; }
	virtual IObjectConstructor* GetConstructor() const { return NULL; };
	virtual const char* GetTypeName() const { return ""; };

	vector<InequalCnstrntFunc*> GetIneqFuncDefin() { return _ineqFuncDefin; }

	virtual double Compute(const std::vector<double> &x) const;
};

