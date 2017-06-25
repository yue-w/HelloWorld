#include "InverseDataParser.h"
#include "OptimizationData.h"
#include "DataWrapper.h"


namespace Core
{
	InverseDataParser::InverseDataParser(const OptimizationResult* optRst):_optResltData(new OptimizationResult(*optRst)), _dataWrapper(NULL)
	{
	}


	InverseDataParser::~InverseDataParser()
	{
		//delete _optResltData;
		//_optResltData = NULL;
		//delete _dataWrapper;
		//_dataWrapper = NULL;
	}

	


	void InverseDataParser::Parse()
	{
		////Clear previous data.
		if ( _dataWrapper  != NULL)
		{
			delete _dataWrapper;
			_dataWrapper = NULL;
		}
		_dataWrapper = new DataWrapper();


		////set the value and key for the variable values
		ParseVariableValue();

		////set the value and key for the minmium object function
		ParseMinimumObjValue();

	}

	size_t InverseDataParser::ComputeVarCount()
	{
		return _optResltData->VecVariableReslt().size();
		
	}

	void InverseDataParser::ParseVariableValue()
	{

		size_t varCount = ComputeVarCount();

		////Set the value and key for the optimized variable value
		for (size_t i = 1; i <= varCount; ++i)
		{
			string indexS = CommonTool::Num2String<size_t>(i);
			string para = "optVali" + indexS;
			double keyDb = _optResltData->VecVariableReslt()[i - 1];
			string keyStr = CommonTool::Num2String<double>(keyDb);
			_dataWrapper->Add(para, keyStr);
		}
	}

	void InverseDataParser::ParseMinimumObjValue()
	{
		string minObjKey = "minObjVal";
		double minObjValue = _optResltData->MinimumObj();
		string minObjValueStr = CommonTool::Num2String<double>(minObjValue);
		_dataWrapper->Add(minObjKey, minObjValueStr);
	}

}


