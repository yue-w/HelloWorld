#pragma once
#include <nlopt.hpp>
#include <math.h>
//#include "nlopt.hpp"
#include <iostream>
using namespace std;

typedef struct {
	double a, b;
} my_constraint_data;

void testFun();

////object function. Array example
//double myfunc(unsigned n, const double *x, double *grad, void *my_func_data);
//
////constraint function. Array example
//double myconstraint(unsigned n, const double *x, double *grad, void *data);


//constraint function. Vector example
double myvfunc(const std::vector<double> &x, std::vector<double> &grad, void *my_func_data);

double myvconstraint(const std::vector<double> &x, std::vector<double> &grad, void *data);


