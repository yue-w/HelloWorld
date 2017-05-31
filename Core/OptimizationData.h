#pragma once
#include "PublicHeader.h"

#include "VariableProperty.h"
#include "FunctionData.h"

namespace Core
{
	class _EXPORT_DLL_UNIT_TEST OptimizationData
	{
		vector<VariableProperty> _varData;
		FunctionData _funcData;

	public:
		OptimizationData();
		~OptimizationData();

		void AddVar(const VariableProperty varData) { _varData.push_back(varData); }
		void SetFuncData(const FunctionData& data) { _funcData = data; }

		//Get string of objective function.
		string GetObjFunc() const;

		//<index> should not be larger than Count of var.
		//<index> start from 1.
		VariableProperty GetVarData(const int index) const;

		size_t VarCount() const;

	public:

		//Name rules.
		static const string VarName;
		static const string LowerBound;
		static const string UpperBound;
		static const string InitialValue;
		static const string ObjectFunction;
	};
}


