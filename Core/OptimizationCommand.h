#pragma once
#include "Command.h"

namespace Core
{
	//Command of optimization.
	class OptimizationCommand :
		public Command
	{
		typedef struct {
			double a, b;
		} my_constraint_data;

		DataWrapper* _outData;

	public:
		OptimizationCommand();
		~OptimizationCommand();

		virtual void Execute(const DataWrapper* data);

		map<string, string> GetOutData() const;

	private:

		void TestOptimize(const std::vector<std::string>& lowerBound, std::vector<double>& var);

		static double myvfunc(const std::vector<double> &x, std::vector<double> &grad, void *my_func_data);

		static double myvconstraint(const std::vector<double> &x, std::vector<double> &grad, void *data);
	};
}


