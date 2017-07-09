#include "OptimizationData.h"


namespace Core
{
	OptimizationData::OptimizationData()
	{
	}


	OptimizationData::~OptimizationData()
	{
	}

	void OptimizationData::SetOptMethod(const OptMethodClass val)
	{

		_optMethod = val;
	}

	OptMethodClass OptimizationData::GetOptMethod() const
	{
		 return _optMethod; 
	}

	string OptimizationData::GetObjFunc() const
	{
		return _funcData.ObjFun();
	}

	vector<string> OptimizationData::GetInequalCnstFunc() const
	{
		return _funcData.InEqualConstrnFun();
	}

	Core::VariableProperty OptimizationData::GetVarData(const int index) const
	{
		if (index<1 || index>_varData.size())
		{
			throw out_of_range("invalid index");
		}

		return _varData.at(index-1);
	}

	size_t OptimizationData::VarCount() const
	{
		return _varData.size();
	}

	const string OptimizationData::VarName = "varName";

	const string OptimizationData::LowerBound="lowBnd";

	const string OptimizationData::UpperBound="upBnd";

	const string OptimizationData::InitialValue="initVal";

	const string OptimizationData::ObjectFunction="objFunc";

	const string OptimizationData::Grad = "grad";

	const string OptimizationData::OptMethod = "optMethod";

	const string OptimizationData::InequalityConstraint = "inequalCnst";

	const string OptimizationData::InequalityConstraintGrad = "inequalGrad";


	OptimizationResult::OptimizationResult( OptimizationData * optData)
	{
		_optData = new OptimizationData;
		_optData = optData;
		_minimumObj = HUGE_VAL;
	}

	OptMethodClass::OptMethodClass(nlopt::algorithm valMethod, bool valCompile)
	{
		_optMethod =valMethod;
		_dynamicCompile = valCompile;
		
	}

	OptMethodClass::OptMethodClass()
	{
	}

	OptMethodClass::~OptMethodClass()
	{
	}

}

