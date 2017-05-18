#include "OptimizationCommand.h"

#include "Log.h"
#include "DataWrapper.h"
#include "ObjectFuncParser.h"
#include "IFunction.h"

#include <sstream>
#include <nlopt.hpp>
#include <math.h>

namespace Core
{
	using namespace CommonTool;

	OptimizationCommand::OptimizationCommand():_outData(new DataWrapper())
	{
	}


	OptimizationCommand::~OptimizationCommand()
	{
		delete _outData;
	}

	template <class Type>
	Type stringToNum(const string& str)
	{
		stringstream iss(str);
		Type num;
		iss >> num;
		return num;
	}

	template <class Type>
	string Num2String(const Type& val)
	{
		stringstream iss;
		iss << val;
		return iss.str();
	}

	void OptimizationCommand::Execute(const DataWrapper* data)
	{
		//Get input data.
// 		auto lb0 = data->GetData("lb0");
// 		auto lb1 = data->GetData("lb1");
// 		vector<std::string> lowerbound;
// 		lowerbound.push_back(lb0);
// 		lowerbound.push_back(lb1);
// 		//Optimize.
// 		vector<double> vars;
// 		TestOptimize(lowerbound, vars);
// 		//Output data.
// 		_outData->Add("var0", Num2String(vars[0]));
// 		_outData->Add("var1", Num2String(vars[1]));


		Log::Info("Start execute");

		ObjectFuncParser parser;
		auto func = parser.Parse(data->GetData("objFunc"));
		if (func == NULL)
		{
			Log::Info("func is null");
		}
		else
		{
			vector<double> var{ 2 };
			auto res = func->Compute(var);
			Core::CommonTool::Log::Info("end compute: "+Num2String(res));
			_outData->Add("objVal", Num2String(res));
		}

	}

	map<string, string> OptimizationCommand::GetOutData() const
	{
		return _outData->GetAllData();
	}

	void OptimizationCommand::TestOptimize(const std::vector<std::string>& lowerBound, std::vector<double>& var)
	{
		nlopt::opt opt(nlopt::LD_MMA, 2);

		vector<double> lb;
		for (auto lb_str : lowerBound)
		{
			lb.push_back(stringToNum<double>(lb_str));
		}
		opt.set_lower_bounds(lb);


		////Set the object function
		opt.set_min_objective(myvfunc, NULL);

		////coefficients for the constraint
		my_constraint_data data[2] = { { 2,0 },{ -1,1 } };

		//Set the constraint function
		opt.add_inequality_constraint(myvconstraint, &data[0], 1e-8);
		opt.add_inequality_constraint(myvconstraint, &data[1], 1e-8);

		opt.set_xtol_rel(1e-4);

		std::vector<double> x(2);
		x[0] = 1.234; x[1] = 5.678;
		double minf;
		nlopt::result result = opt.optimize(x, minf);

		var.clear();
		var.push_back(x[0]);
		var.push_back(x[1]);
	}

	double OptimizationCommand::myvfunc(const std::vector<double> &x, std::vector<double> &grad, void *my_func_data)
	{
		Log::PushNDC("Optimization");

		double obj = sqrt(x[1]);

		Log::Info("Objective value is %lf.", obj);

		if (!grad.empty()) {
			grad[0] = 0.0;
			grad[1] = 0.5 / sqrt(x[1]);
		}

		Log::PopNDC();

		return obj;
	}

	double OptimizationCommand::myvconstraint(const std::vector<double> &x, std::vector<double> &grad, void *data)
	{
		my_constraint_data *d = reinterpret_cast<my_constraint_data*>(data);
		double a = d->a, b = d->b;
		if (!grad.empty()) {
			grad[0] = 3 * a * (a*x[0] + b) * (a*x[0] + b);
			grad[1] = -1.0;
		}
		return ((a*x[0] + b) * (a*x[0] + b) * (a*x[0] + b) - x[1]);
	}
}

