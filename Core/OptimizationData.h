#pragma once
#include "PublicHeader.h"

#include "VariableProperty.h"
#include "FunctionData.h"
#include <vector>

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
		static const string Grad;
	};

	////Optimization result
	class _EXPORT_DLL_UNIT_TEST OptimizationResult 
	{
		OptimizationData* _optData;

		////Minimum Object function value
		double _minimumObj;

		////Result of the variables
		std::vector<double> _vecVariableReslt;

		////Iteration numbers
		int _itNumbers;

		////Add more...


	public:
		OptimizationResult( OptimizationData* optData );

		void MinimumObj(double val) { _minimumObj = val; }
		double MinimumObj() { return _minimumObj; }

		void VecVariableReslt(const std::vector<double> x) { _vecVariableReslt = x; }
		std::vector<double> VecVariableReslt() { return _vecVariableReslt; }

		void ItNumbers(int value) { _itNumbers = value; }
		int ItNumbers() { return _itNumbers; }



	};






}


