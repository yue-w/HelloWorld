#include "Command.h"

#include "implementOpt.h"

#include <sstream>

using namespace std;

namespace Core
{
	template <class Type>
	Type stringToNum(const string& str)
	{
		stringstream iss(str);
		Type num;
		iss >> num;
		return num;
	}

	void TestOptimize(const vector<std::string>& lowerBound, vector<double>& var)
	{
		nlopt::opt opt(nlopt::LD_MMA, 2);

		vector<double> lb;
		for (auto lb_str: lowerBound)
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
}