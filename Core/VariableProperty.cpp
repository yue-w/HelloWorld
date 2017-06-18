#include "VariableProperty.h"

#include "CommonFunc.h"

namespace Core
{
	VariableProperty::VariableProperty(const string varName):_varName(varName)
	{
		_lb = DEFAULT_DOUBLE;
		_ub = DEFAULT_DOUBLE;
		_initVal = DEFAULT_DOUBLE;
		_grad = "";
	}


	VariableProperty::~VariableProperty()
	{
	}
}

