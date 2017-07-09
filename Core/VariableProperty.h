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
		string _grad;//gradient
		/*gradient for inequal constraint. Every variable hasa gradient for every inequal constraint equation. 
		The dimention of this vector is the same with the number of inequality constraint function. This vector
		can be empty if non-gradient method is used.*/
		vector<string> _gradInequalCnstrnt;

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
		string Grad()const { return _grad; }
		void Grad(string val) { _grad = val; }
		vector<string> GradInequalCnstrt() { return _gradInequalCnstrnt; }
		void GradInequalCnstrt(vector<string> val) { _gradInequalCnstrnt = val; }
	};

}

