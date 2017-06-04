#include "DataParser.h"

#include "DataWrapper.h"
#include "CommonFunc.h"
#include "OptimizationData.h"
#include "VariableProperty.h"

namespace Core
{
	DataParser::DataParser(const DataWrapper* dataWrapper):_dataWapper(new DataWrapper(*dataWrapper)), _optData(NULL)
	{
	}


	DataParser::~DataParser()
	{
		delete _dataWapper;
		_dataWapper = NULL;
		delete _optData;
		_optData = NULL;
	}

	void DataParser::Parse()
	{
		//Clear previous data.
		if (_optData != NULL)
		{
			delete _optData;
			_optData = NULL;
		}

		_optData = new OptimizationData();

		//Determine number of vars.
		size_t varCount = ComputeVarCount();
		
		for (size_t i = 1; i <= varCount; ++i)
		{
			auto varProperty = ParseEachVar(i);
			_optData->AddVar(varProperty);
		}

		//Parse functions.
		auto funcData = ParseFunctionData();
		_optData->SetFuncData(funcData);
	}

	Core::OptimizationData DataParser::GetParsedData() const
	{
		return *_optData;
	}

	size_t DataParser::ComputeVarCount()
	{
		size_t count = 0;
		while (true)
		{
			//Check if <_dataWapper> contains varName.
			//The number of varName determine the count of vars.
			int index = count + 1;
			//Key for var name.
			string var_key = OptimizationData::VarName + CommonTool::StringFormat("%d", index);
			if (_dataWapper->HasData(var_key))
			{
				++count;
			}
			else
			{
				break;
			}
		}

		return count;
	}

	Core::VariableProperty DataParser::ParseEachVar(const int i)
	{
		//Construct each variable ,including lb,ub...
		string var_key = OptimizationData::VarName + CommonTool::StringFormat("%d", i);
		string varName = _dataWapper->GetData(var_key);
		VariableProperty varProperty(varName);

		//Parse lower bound.
		string lb_key = OptimizationData::LowerBound + CommonTool::StringFormat("%d", i);
		if (_dataWapper->HasData(lb_key))
		{
			string lbStr = _dataWapper->GetData(lb_key);
			double lb = CommonTool::StringToDouble(lbStr);
			varProperty.Lb(lb);
		}

		//Parse upper bound.
		string ub_key = OptimizationData::UpperBound + CommonTool::StringFormat("%d", i);
		if (_dataWapper->HasData(ub_key))
		{
			string ubStr = _dataWapper->GetData(ub_key);
			double ub = CommonTool::StringToDouble(ubStr);
			varProperty.Ub(ub);
		}

		//Parse initial value.
		string initVal_key = OptimizationData::InitialValue + CommonTool::StringFormat("%d", i);
		if (_dataWapper->HasData(initVal_key))
		{
			string initStr = _dataWapper->GetData(initVal_key);
			double intialVal = CommonTool::StringToDouble(initStr);
			varProperty.InitVal(intialVal);
		}

		//Parse gradient
		string grad_key = OptimizationData::Grad + CommonTool::StringFormat("%d", i);
		if (_dataWapper->HasData(grad_key))
		{
			string initStr = _dataWapper->GetData(grad_key);
			
			varProperty.Grad(initStr);
		}

		return varProperty;
	}

	Core::FunctionData DataParser::ParseFunctionData()
	{
		FunctionData funcData;

		string objFun_key= OptimizationData::ObjectFunction;
		if (_dataWapper->HasData(objFun_key))
		{
			string objFun = _dataWapper->GetData(objFun_key);
			funcData.ObjFun(objFun);
		}

		return funcData;
	}

}

