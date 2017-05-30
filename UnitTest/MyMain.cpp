
#include <gtest\gtest.h>
//#include <strstream>
//#include "..\Core\AlgorithmInteractive.h"

void main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	////std::cin.get();

// 	Core::AlgorithmInteractive interactive_test;
// 
// 	////map that contains the key and the name of the variable
// 	interactive_test.AddParam("varName1", "x1");
// 	interactive_test.AddParam("varName2", "x2");
// 	//interactive_test.AddParam("varName3", "c");
// 	//interactive_test.AddParam("varName4", "d");
// 	
// 	////add lower bound
// 	interactive_test.AddParam("lowBnd1", "2");
// 	interactive_test.AddParam("lowBnd2", "1");
// 
// 	vector<string> varKey;
// 	varKey.push_back("varName1");
// 	varKey.push_back("varName2");
// 	interactive_test.setVarNameKey(varKey);
// 
// 	////map that contains the object function
// 	interactive_test.AddParam("objFunc", "sqrt(x1)+sqrt(x2)"/*"(x1-x2)*(x1-x2)"*/);
// 
// 	if (interactive_test.Execute("Optimization"))
// 	{
// 		auto outData_test = interactive_test.GetOutput();
// 		auto res = outData_test["objVal"];
// 
// 	}
	system("pause");
}

