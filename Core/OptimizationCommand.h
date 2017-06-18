#pragma once
#include "Command.h"

namespace Core
{
	class OptimizationData;
	typedef struct {
		double a, b;
	} my_constraint_data;

	//Command of optimization.
	class OptimizationCommand :
		public Command
	{


		DataWrapper* _outData;

	public:
		OptimizationCommand();
		~OptimizationCommand(); 

		virtual void Execute(const DataWrapper* data);

		unordered_map<string, string> GetOutData() const;

	private:


		_declspec(dllexport)  double TestOptimize(const std::vector<std::string>& lowerBound, std::vector<double>& var);

		//Excute Nlopt optimization
		_declspec(dllexport)  void callNloptOptimize(const OptimizationData* optData);

		////Modify the object function input by user
		string modifyObjectFunc(const OptimizationData* optData);

		////Modify the Gradient function input by user
		std::vector<string> ModifyGrad(const OptimizationData* optData);

		////Change the variable from unordered_map to a vector<double> that contains all the variable.
		vector<double> changeVariableToVector(const unordered_map<string, string> &variableKeyValue);

		////common tool. Change the variable name to index. For example x1 to x[0]
		string ChangeNameToIndex(string modified, const OptimizationData* optData);


		//Push Grad Pointer to the static vector in the class ObjFuncExcut
		//void PushGradPointer(const int totalVariable);

	public:
		static double myvfunc(const std::vector<double> &x, std::vector<double> &grad, void *my_func_data);

		static double myvconstraint(const std::vector<double> &x, std::vector<double> &grad, void *data);
	};
}


