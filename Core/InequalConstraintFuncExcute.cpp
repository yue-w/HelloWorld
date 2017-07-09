#include "InequalConstraintFuncExcute.h"
#include "InequalCnstrntFunc.h"
#include "NloptPara.h"
#include "Grad.h"
InequalConstraintFuncExcute::InequalConstraintFuncExcute()
{
}


InequalConstraintFuncExcute::~InequalConstraintFuncExcute()
{
}

double InequalConstraintFuncExcute::InequalConstraintFunction(const std::vector<double>& x, std::vector<double>& grad, void * my_func_data)
{
	NloptPara_OneInequalityConstraint * inequalFuncPara = reinterpret_cast<NloptPara_OneInequalityConstraint*>(my_func_data);

	vector<Grad*> vecGrad = inequalFuncPara->GetGrad();

	if (!grad.empty()) {
		for (size_t i = 0; i<grad.size(); i++)
		{
			Grad* gradDef = vecGrad[i];
			grad[i] = gradDef->Compute(x);
		}
	}

	double value = 0;

	InequalCnstrntFunc* oneInequalDefine = inequalFuncPara->GetOneInequalCnstFunAndGradDefin();
	value = oneInequalDefine->Compute(x);

	return value;
}
