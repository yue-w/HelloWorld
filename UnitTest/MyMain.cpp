
#include <gtest\gtest.h>
//#include <strstream>
#include "..\Core\AlgorithmInteractive.h"

void main(int argc, char* argv[])
{
	//::testing::InitGoogleTest(&argc, argv);
	//RUN_ALL_TESTS();
	////std::cin.get();

	Core::AlgorithmInteractive interactive_test;
	interactive_test.AddParam("c", "c");
	interactive_test.AddParam("a", "a");
	interactive_test.AddParam("x1", "x1");
	interactive_test.AddParam("x2", "x2");
	interactive_test.AddParam("b", "b");
	interactive_test.AddParam("objFunc", "x1*x1+x2*x2");
	if (interactive_test.Execute("Optimization"))
	{
		auto outData_test = interactive_test.GetOutput();
		auto res = outData_test["objVal"];

	}
	system("pause");
}

