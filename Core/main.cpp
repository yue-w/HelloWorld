#include <nlopt.hpp>
#include "implementOpt.h"
#include "Log.h"

using namespace std;
using namespace CommonTool;
//using namespace nmspace;

int main()
{

	nlopt::opt opt(nlopt::LD_MMA, 2);

	std::vector<double> lb(2);
	lb[0] = -HUGE_VAL; lb[1] = 0;
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

	Log::Info("Hello Gan Gan!!!!!!");
	Log::Info("Object value: %lf\n",minf);
	system("PAUSE");


	return 0;
}

//testFun();
//myclass::Crap();