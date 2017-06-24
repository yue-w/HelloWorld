#pragma once
#include "ObjectFunction.h"
#include "Grad.h"
//class ObjectFunction;
class ObjFuncExcut
{
private:
	////object function from dynamic compilation
	static ObjectFunction* _objFunDefin;

	////gradient from dynamic compilation
	vector<Grad*> _gradDefin;
	//static Grad* _gradDefin;



public:
	//ObjFuncExcut(const ObjectFunction* _objFunDefin);
	ObjFuncExcut();
	~ObjFuncExcut();
	static double ObjFunction(const std::vector<double> &x, std::vector<double> &grad, void *my_func_data) ;

	////Number of variable
	static size_t _numOfVar;
	void PushGrad(Grad* gradPnt) ;//{ _gradDefin.push_back(gradPnt); }
};

