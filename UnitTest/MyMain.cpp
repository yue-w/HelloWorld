
#include <gtest\gtest.h>
//#include <strstream>
#include "..\Core\AlgorithmInteractive.h"

void main(int argc, char* argv[])
{
	//::testing::InitGoogleTest(&argc, argv);
	//RUN_ALL_TESTS();
	////std::cin.get();

	Core::AlgorithmInteractive interactive_test;

	////map that contains the key and the name of the variable
	interactive_test.AddParam("x1key", "x1");
	interactive_test.AddParam("x2key", "x2");
	//interactive_test.AddParam("x3key", "x3");
	//interactive_test.AddParam("x4key", "0.456");

	////map that contains the object function
	interactive_test.AddParam("objFunc", "x1*x1+x2*x2");
	if (interactive_test.Execute("Optimization"))
	{
		auto outData_test = interactive_test.GetOutput();
		auto res = outData_test["objVal"];

	}
	system("pause");
}

