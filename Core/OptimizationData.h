#pragma once
#include "PublicHeader.h"

#include "VariableProperty.h"
#include "FunctionData.h"
#include <vector>

namespace nlopt
{
	enum  algorithm;
}
namespace Core
{
	class OptMethodClass
	{
	private:
		nlopt::algorithm _optMethod;
		bool _dynamicCompile;
	public:
		OptMethodClass(nlopt::algorithm valMethod, bool valCompile);
		OptMethodClass();
		~OptMethodClass();

		void SetOptMethod(nlopt::algorithm val) { _optMethod = val; }
		nlopt::algorithm GetOptMethod() { return _optMethod; }

		void SetDynamicComp(bool val) { _dynamicCompile = val; }
		bool GetDynamicComp() { return _dynamicCompile; }
	};



	class _EXPORT_DLL_UNIT_TEST OptimizationData
	{
		vector<VariableProperty> _varData;
		FunctionData _funcData;
		//nlopt::algorithm _optMethod;
		OptMethodClass _optMethod;

	public:
		OptimizationData();
		~OptimizationData();

		void AddVar(const VariableProperty varData) { _varData.push_back(varData); }
		void SetFuncData(const FunctionData& data) { _funcData = data; }
		FunctionData GetFuncData() const { return _funcData; }

		void SetOptMethod(const OptMethodClass val);
		OptMethodClass GetOptMethod() const;

		//Get string of objective function.
		string GetObjFunc() const;

		//Get strings of inequality constriant function
		vector<string> GetInequalCnstFunc() const;


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
		static const string OptMethod;
		static const string InequalityConstraint;
		static const string InequalityConstraintGrad;

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


