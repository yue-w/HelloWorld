#include "DataParser.h"

#include "DataWrapper.h"
#include "CommonFunc.h"
#include "OptimizationData.h"
#include "VariableProperty.h"
#include "OptMthdParser.h"

namespace Core
{
	DataParser::DataParser(const DataWrapper* dataWrapper):_dataWapper(new DataWrapper(*dataWrapper)), _optData(NULL)
	{
		//_optMtdMap["0"] = LD_MMA;
		//
		//_optMtdMap["1"] = LN_COBYLA;
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

		//Parse object function. Because there is only one object function,it is stored seperately.
		auto funcData = ParseFunctionData();		

		//Parse inequality constraint functions
		ParseInequalityConstraint(funcData);

		_optData->SetFuncData(funcData);

		//Parse optimization method		 
		OptMethodClass optMtd= ParseOptMethod();
		//optMtd.SetOptMethod(val);
		_optData->SetOptMethod(optMtd);

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
			string gradStr = _dataWapper->GetData(grad_key);		
			varProperty.Grad(gradStr);
		}

		//Parse Gradient for Inequality constraint
		vector<string> inequalGrad=ParseInequalCnst_Grad(i);
		varProperty.GradInequalCnstrt(inequalGrad);

		return varProperty;
	}

	vector<string> DataParser::ParseInequalCnst_Grad(const int indexVariable)
	{
		////Out put
		vector<string> gradForThisInequalFunc;
		/*indexInequalFunc is the index for inequality constraint function.
		indexVariable is the index for the variable*/
		int indexInequalFunc = 1;////The index for the keys start from 1.
		string key = OptimizationData::InequalityConstraintGrad + CommonTool::StringFormat("%d", indexInequalFunc)+ CommonTool::StringFormat("%d", indexVariable); 
		while (_dataWapper->HasData(key))
		{
			string str = _dataWapper->GetData(key);
			gradForThisInequalFunc.push_back(str);			
			indexInequalFunc++;
			key = OptimizationData::InequalityConstraintGrad + CommonTool::StringFormat("%d", indexInequalFunc) + CommonTool::StringFormat("%d", indexVariable);
		}

		return gradForThisInequalFunc;
	}

	Core::FunctionData DataParser::ParseFunctionData()
	{
		FunctionData funcData;

		////Object function
		string objFun_key= OptimizationData::ObjectFunction;
		if (_dataWapper->HasData(objFun_key))
		{
			string objFun = _dataWapper->GetData(objFun_key);
			funcData.ObjFun(objFun);
		}

		////Inequality constraint
		//ParseInequalityConstraint(funcData);

		return funcData;
	}

	void DataParser::ParseInequalityConstraint(FunctionData& funcData)
	{
		vector<string> keys;
		int index = 1;//The index start from 1.	
		string inequaKey = OptimizationData::InequalityConstraint + CommonTool::StringFormat("%d", index);
		////search all the inequal constraint. According to the name rule, the key is OptimizationData::InequalityConstraint+index
		while (_dataWapper->HasData(inequaKey))
		{			
			string oneInequalCns = _dataWapper->GetData(inequaKey);
			keys.push_back(oneInequalCns);
			index++;
			inequaKey = OptimizationData::InequalityConstraint + CommonTool::StringFormat("%d", index);
		}
		funcData.InEqualConstrnFun(keys);
		 
	}

	OptMethodClass DataParser::ParseOptMethod()
	{
			string optMethodKey = OptimizationData::OptMethod;
			if (_dataWapper->HasData(optMethodKey))
			{
				string optMethod = _dataWapper->GetData(optMethodKey);
				OptMthdParser* optParser = new OptMthdParser;
				return optParser->Parse(optMethod);
			}
			else throw;


	}

	//algorithm DataParser::ParseOptMethod()
	//{
	//	string optMethodKey = OptimizationData::OptMethod;
	//	if (_dataWapper->HasData(optMethodKey))
	//	{
	//		string optMethod = _dataWapper->GetData(optMethodKey);

	//	}

	//	return algorithm();
	//}

	//void DataParser::SetOptMtdMap()
	//{
	//	_optMtdMap["0"] = nlopt::LD_MMA;
	//	
	//	_optMtdMap["1"] = nlopt::LN_COBYLA;
	//}

}

