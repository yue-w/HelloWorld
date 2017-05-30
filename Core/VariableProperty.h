#pragma once
#include "PublicHeader.h"

namespace Core
{

	class _EXPORT_DLL_UNIT_TEST VariableProperty
	{
		string _varName;//Name of variable.
		double _lb;//lower bound.
		double _ub;//upper bound.
		double _initVal;//initial value.

	public:
		VariableProperty(const string varName);
		~VariableProperty();

		string VarName() const { return _varName; }

		double Lb() const { return _lb; }
		void Lb(double val) { _lb = val; }
		double Ub() const { return _ub; }
		void Ub(double val) { _ub = val; }
		double InitVal() const { return _initVal; }
		void InitVal(double val) { _initVal = val; }
	};

}

