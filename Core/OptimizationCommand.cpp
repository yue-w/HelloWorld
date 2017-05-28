#include "OptimizationCommand.h"

#include "Log.h"
#include "DataWrapper.h"
#include "ObjectFuncParser.h"
#include "IFunction.h"
#include "CommonFunc.h"

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


		//Parse the objective function.
		ObjectFuncParser parser;
		

		

		//auto func = parser.Parse(data->GetData("objFunc"));


		////objFunc is the string that contains the modified object function.
		string objFunc = modifyObjectFunc(data);


		//////WangYue Debug
		//_outData->Add("modi", objFunc);
		//return;
		//////WangYue Debug 

		auto func = parser.Parse(objFunc);

		if (func == NULL)
		{
			Log::Info("func is null");
		}
		else
		{
			//Get input from UI.
			auto x = StringToNum<double>(data->GetData("lb0"));
			vector<double> var{ x };
			//Compute
			auto res = func->Compute(var);
			Core::CommonTool::Log::Info("end compute: "+Num2String(res));
			//Send data to output wrapper.
			_outData->Add("objVal", Num2String(res));
		}

	}

	string OptimizationCommand::modifyObjectFunc(const DataWrapper* data)
	{
		

		////make a copy of data
		unordered_map<string, string> allKeys = data->GetAllData();

		////original object function
		string oriObjfunc = data->GetData("objFunc");

		////Remove the key "objFunc" from the data to make replacing the variable name easier.
		unordered_map<string, string>::iterator it;
		it = allKeys.find("objFunc");
		allKeys.erase(it);


		string modifiedObjFun= data->GetData("objFunc");

		int indexInx = 0;
		///iterate the unordered_map.
		for (std::unordered_map<string, string>::iterator iter = allKeys.begin(); iter != allKeys.end(); ++iter)
		{
			
			string key = iter->first;
			string value = allKeys[key];

			///find and replace the variable
			size_t pos = modifiedObjFun.find(value, 0);
			while (pos !=string::npos)////if find the occurance
			{
				string replace = "x[" + std::to_string(indexInx) + "]";
				modifiedObjFun.replace(pos, value.length(), replace);
				
				 pos = modifiedObjFun.find(value, 0);
			}
			indexInx++;

			//size_t f = modifiedObjFun.find(value);
			//string replace = "[" + std::to_string(i) + "]";
			//modifiedObjFun.replace(f, value.length(), replace);

			
		}


		//string modifiedObjFun;
		//auto objFun = data->GetData("objFunc");
		//auto x1_ = data->GetData("x1");
		//auto x2_ = data->GetData("x2");



		return modifiedObjFun;
	}
	vector<double> OptimizationCommand::changeVariableToVector(const unordered_map<string, string> & variableKeyValue)
	{
		//////make a copy of data, and eraze object function, so that only numbers are remained.
		unordered_map<string, string> allKeys= variableKeyValue;

		unordered_map<string, string>::const_iterator it;
		it = allKeys.find("objFunc");
		allKeys.erase(it);

		//vector<double> x(variableKeyValue.size());
		vector<double> x;
		rsize_t i = 0;
		for (unordered_map<string, string>::iterator it = allKeys.begin(); it!= allKeys.end(); it++)
		{
			////the order of the variable is the same as in the key			
			x.push_back(std::stod(it->second));
		}

		return x;
	}
	unordered_map<string, string> OptimizationCommand::GetOutData() const
	{
		return _outData->GetAllData();
	}

	double OptimizationCommand::TestOptimize(const std::vector<std::string>& lowerBound, std::vector<double>& var)
	{
		nlopt::opt opt(nlopt::LD_MMA, 2);

		vector<double> lb;
		for (auto lb_str : lowerBound)
		{
			lb.push_back(StringToNum<double>(lb_str));
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

		return minf;
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

