#include "OptimizationData.h"


namespace Core
{
	OptimizationData::OptimizationData()
	{
	}


	OptimizationData::~OptimizationData()
	{
	}

	string OptimizationData::GetObjFunc() const
	{
		return _funcData.ObjFun();
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
}

