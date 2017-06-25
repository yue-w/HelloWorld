#pragma once
#include "PublicHeader.h"
#include "CommonFunc.h"

namespace Core
{
	class OptimizationResult;
	class DataWrapper;

	 class _EXPORT_DLL_UNIT_TEST InverseDataParser
	{
		 OptimizationResult* _optResltData;//Input

		 DataWrapper* _dataWrapper;//Output

	public:
		InverseDataParser(const OptimizationResult* optRst);
		~InverseDataParser();

		void Parse();

		//Compute the number of Variables.
		size_t ComputeVarCount();

		DataWrapper* GetParsedData() const {return _dataWrapper;}

	private:
		void ParseVariableValue();
		void ParseMinimumObjValue();
	};
}

