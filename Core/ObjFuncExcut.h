#pragma once
#include "ObjectFunction.h"
//class ObjectFunction;
class ObjFuncExcut
{
private:
	static ObjectFunction* _objFunDefin;
public:
	//ObjFuncExcut(const ObjectFunction* _objFunDefin);
	ObjFuncExcut();
	~ObjFuncExcut();
	static double objectFunction(const std::vector<double> &x, std::vector<double> &grad, void *my_func_data) ;
};

