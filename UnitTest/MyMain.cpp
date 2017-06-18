
#include <gtest\gtest.h>
#include <strstream>
#include "..\Core\AlgorithmInteractive.h"

void main(int argc, char* argv[])
{
	//::testing::InitGoogleTest(&argc, argv);
	//RUN_ALL_TESTS();
	

 	Core::AlgorithmInteractive interactive_test;
 
 	////map that contains the key and the name of the variable
 	interactive_test.AddParam("varName1", "x1");
 	interactive_test.AddParam("varName2", "x2");
 	//interactive_test.AddParam("varName3", "x3");
 	//interactive_test.AddParam("varName4", "x4");
 	
 	////add lower bound
 	interactive_test.AddParam("lowBnd1", "-1000000");
 	interactive_test.AddParam("lowBnd2", "-1000000");
	//interactive_test.AddParam("lowBnd3", "2");
	//interactive_test.AddParam("lowBnd4", "1");

	////add higher bound
	interactive_test.AddParam("upBnd1", "1000");
	interactive_test.AddParam("upBnd2", "1000");
	//interactive_test.AddParam("upBnd3", "1000");
	//interactive_test.AddParam("upBnd4", "1000");
 
	////add initial value
	interactive_test.AddParam("initVal1", "-1.23");
	interactive_test.AddParam("initVal2", "2.34");
	//interactive_test.AddParam("initVal3", "-4.56");
	//interactive_test.AddParam("initVal4", "5.12");
	////add gradient
	//interactive_test.AddParam("grad1", "2*x1-2");
	interactive_test.AddParam("grad1", "2*x1");
	interactive_test.AddParam("grad2", "2*x2-8");

 	vector<string> varKey;
 	varKey.push_back("varName1");
 	varKey.push_back("varName2");
	//varKey.push_back("varName3");
	//varKey.push_back("varName4");
 	interactive_test.setVarNameKey(varKey);
 
 	////map that contains the object function
 	interactive_test.AddParam("objFunc", /*"(x1+x2+x3+x4)*(x1+x2+x3+x4)"*/"(x1-1)*(x1-1)+(x2-4)*(x2-4)");
 
 	if (interactive_test.Execute("Optimization"))
 	{
 		auto outData_test = interactive_test.GetOutput();
 		auto res = outData_test["objVal"];
 
 	}


	system("pause");
}

