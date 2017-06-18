#pragma once
#include "PublicHeader.h"

namespace Core
{
	class DataWrapper;
	class OptimizationData;
	class VariableProperty;
	class FunctionData;////store the object function input from UI

	//////////////////////////////////////////////////////////////////////////
	//Parse data from DataWrapper to a concrete data class.
	//////////////////////////////////////////////////////////////////////////
	class _EXPORT_DLL_UNIT_TEST DataParser
	{
		DataWrapper* _dataWapper;//Input

		OptimizationData* _optData;//Output
	public:
		DataParser(const DataWrapper* dataWrapper);
		~DataParser();

		void Parse();

		OptimizationData GetParsedData() const;

	private:

		//Compute the number of Variables.
		size_t ComputeVarCount();

		VariableProperty ParseEachVar(const int varIndex);
		FunctionData ParseFunctionData();
	};

}

