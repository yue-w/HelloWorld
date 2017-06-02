#include <gtest\gtest.h>

#include "../Core/DataParser.h"
#include "../Core/DataWrapper.h"
#include "../Core/OptimizationData.h"
#include "../Core/CommonFunc.h"

namespace Core
{
	TEST(Test_DataParser, ComputeVarCountCorrectly)
	{
		//Prepare data wrapper.
		DataWrapper data;
		data.Add("varName1", "x1");
		data.Add("varName2", "x2");
		data.Add("varName3", "x3");

		//Parse.
		DataParser parser(&data);
		parser.Parse();
		auto optData = parser.GetParsedData();

		auto varData = optData.GetVarData(3);

		ASSERT_EQ("x3", varData.VarName());

		ASSERT_EQ(3, optData.VarCount());
	}

	TEST(Test_DataParser, ParseLowerBoundAndUpperBound)
	{
		//Prepare data wrapper.
		DataWrapper data;
		data.Add("varName1", "x1");
		data.Add("lowBnd1", "0");
		data.Add("upBnd1", "1");
		data.Add("initVal1", "0.5");
		data.Add("varName2", "x2");
		//Parse.
		DataParser parser(&data);
		parser.Parse();
		auto optData = parser.GetParsedData();

		ASSERT_EQ(2, optData.VarCount());

		auto varData = optData.GetVarData(1);

		ASSERT_EQ("x1", varData.VarName());
		ASSERT_EQ(0, varData.Lb());
		ASSERT_EQ(1, varData.Ub());
		ASSERT_EQ(0.5, varData.InitVal());
	}

	TEST(Test_DataParser, SomeValuesAreOptional)
	{
		//Prepare data wrapper with no upper bound and lower bound.
		DataWrapper data;
		data.Add("varName1", "x1");
		data.Add("initVal1", "0.5");

		//Parse.
		DataParser parser(&data);
		parser.Parse();
		auto optData = parser.GetParsedData();

		ASSERT_EQ(1, optData.VarCount());

		auto varData = optData.GetVarData(1);

		ASSERT_EQ("x1", varData.VarName());
		ASSERT_EQ(0.5, varData.InitVal());
		ASSERT_EQ(DEFAULT_DOUBLE, varData.Lb());//lower bound is a default double.
		ASSERT_EQ(DEFAULT_DOUBLE, varData.Ub());
	}

	TEST(Test_DataParser, VarCountIsDeterminedByVarName)
	{
		//Prepare data wrapper.
		DataWrapper data;
		data.Add("varName1", "x1");
		data.Add("initVal1", "0.5");
		//Add another var without a Var name.
		data.Add("lowBnd2", "0");
		data.Add("upBnd2", "1");
		data.Add("initVal2", "0.5");

		//Parse.
		DataParser parser(&data);
		parser.Parse();
		auto optData = parser.GetParsedData();

		//Then there is only one var.
		ASSERT_EQ(1, optData.VarCount());
	}

	TEST(Test_DataParser, ParseObjFunc)
	{
		//Prepare data wrapper.
		DataWrapper data;
		data.Add("objFunc", "x1*x1");

		//Parse.
		DataParser parser(&data);
		parser.Parse();
		auto optData = parser.GetParsedData();

		ASSERT_EQ("x1*x1", optData.GetObjFunc());
	}

	TEST(Test_DataParser, ObjFuncIsDefaultValueIfThereIsNoFuncInDataWrapper)
	{
		//Prepare data wrapper.
		DataWrapper data;
		data.Add("varName", "x1");

		//Parse.
		DataParser parser(&data);
		parser.Parse();
		auto optData = parser.GetParsedData();

		ASSERT_EQ(DEFAULT_STRING, optData.GetObjFunc());
	}
}