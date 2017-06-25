#include "OptimizationCommand.h"

#include "Log.h"
#include "DataWrapper.h"
#include "DataParser.h"
#include "OptimizationData.h"
#include "FunctionParser.h"
#include "IFunction.h"
#include "CommonFunc.h"
#include "ObjFuncExcut.h"

#include <sstream>
#include <nlopt.hpp>
#include <math.h>
//#include "GradPasser.h"
#include "CompileGradExcut.h"
#include "Grad.h"
#include "InverseDataParser.h"


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

		////objFunc is the string that contains the modified object function.
		DataParser dataParser(data);
		dataParser.Parse();
		OptimizationData optData = dataParser.GetParsedData();
		string objFunc = modifyObjectFunc(&optData);

		//Parse the objective function.
		ObjectFuncParser parser;
		//string pathObj = "..\\..\\..\\Core\\ObjectFunction.cpp";//Path used in Qt
		string pathObj = "..\\Core\\ObjectFunction.cpp";//////Path used for debugging in VS
		IFunction* func = parser.Parse(objFunc, pathObj);
		IFunction* iFunctionObjFunc = parser.DynamicCompile("ObjectFunction");
		func = dynamic_cast<ObjectFunction*>(iFunctionObjFunc);
		//vector<double> x;
		//x.push_back(0);
		//x.push_back(0);
		//func->Compute(x);
		
		vector<string> grad = ModifyGrad(&optData); 
		//pass the gradient
		GradPasser gradPasser;
		vector<string> vecClassName(grad.size());
		for (size_t i = 0; i<grad.size(); i++)
		{
			string className = "";

			//string pathGrad = "..\\..\\..\\Core\\Grad"; ////Path used for Qt
			string pathGrad = "..\\Core\\Grad";////For debugging in VS

			auto funcGrad = gradPasser.Parse(grad[i], pathGrad,i, className);
			vecClassName[i] = className;
		}
		IFunction* iFuncGrad = gradPasser.DynamicCompile("Grad");

		Grad* grad1 = dynamic_cast<Grad*> (iFuncGrad);
		


		///////Dynamic Compiling
		ExcuteGradParser excuPasser;

		//string pathExcuGrad = "..\\..\\..\\Core\\CompileGradExcut.cpp";////Path for debugging in VS
		string pathExcuGrad = "..\\Core\\CompileGradExcut.cpp";////Path for debugging in VS
		excuPasser.Parse(objFunc, pathExcuGrad, vecClassName);
		IFunction* iFunc = excuPasser.DynamicCompile("CompileGradExcut");

		CompileGradExcut* comPilExcu =dynamic_cast<CompileGradExcut*>(iFunc);
		comPilExcu->PushGradPointer();
	

		if (func == NULL)
		{
			Log::Info("func is null");
		}
		else
		{
			NloptPara* nloptPara = new NloptPara();
			nloptPara->SetGradDefine(comPilExcu->GetGradDefineVector());

			ObjectFunction* testD = dynamic_cast<ObjectFunction*> (func);
			nloptPara->SetObjectFunction(testD);

			//Optimization reslut
			OptimizationResult* optResult = new OptimizationResult(&optData);

			////Excute. Call NLOPT
			CallNloptOptimize(&optData,nloptPara, optResult);

			//vector<std::string> varNameKeys = data->getVecVariableNameKeys();

			InverseDataParser inverseDataParser(optResult);
			inverseDataParser.Parse();
			DataWrapper* outPutWraper = inverseDataParser.GetParsedData();
		}

	}

	string OptimizationCommand::modifyObjectFunc(const OptimizationData* optData)
	{
		string modifiedObjFun = optData->GetObjFunc();////Object function input by the user
		return ChangeNameToIndex(modifiedObjFun, optData);
		
		
		/*
		////will be modified and returned
		string modifiedObjFun= optData->GetObjFunc();////Object function input by the user

		int varNumber = optData->VarCount();
		int indexInx = 0;
		for (size_t i = 1; i<=varNumber; i++) 
		{
			auto varData = optData->GetVarData(i);
			string value = varData.VarName();

				///find and replace the variable
				size_t pos = modifiedObjFun.find(value, 0);
				while (pos != string::npos)////if find the occurance
				{
					string replace = "x[" + std::to_string(indexInx) + "]";
					modifiedObjFun.replace(pos, value.length(), replace);

					pos = modifiedObjFun.find(value, 0);
				}
				indexInx++;

		}


		return modifiedObjFun;*/

	
	}
	std::vector<string> OptimizationCommand::ModifyGrad(const OptimizationData * optData)
	{
		int varNumber = optData->VarCount();

		////will be returned.
		std::vector<string> grad(varNumber);
		
		int indexInx = 0;
		for (size_t i = 1; i <= varNumber; i++)
		{
			auto varData = optData->GetVarData(i);
			string modifiedGrad = varData.Grad();

			//change xi to x[i-0]. Start

			//int varNumber = optData->VarCount();
			//int indexInx = 0;
			//for (size_t i = 1; i <= varNumber; i++)
			//{
			//	auto varData = optData->GetVarData(i);
			//	string value = varData.VarName();

			//	///find and replace the variable
			//	size_t pos = modifiedGrad.find(value, 0);
			//	while (pos != string::npos)////if find the occurance
			//	{
			//		string replace = "x[" + std::to_string(indexInx) + "]";
			//		modifiedGrad.replace(pos, value.length(), replace);

			//		pos = modifiedGrad.find(value, 0);
			//	}
			//	indexInx++;

			//}

			//change xi to x[i-0]. End

			grad[i - 1] = ChangeNameToIndex(modifiedGrad, optData);
			//grad[i - 1] = modifiedGrad;
		}

		return grad;
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
	string OptimizationCommand::ChangeNameToIndex(string  modified, const OptimizationData* optData)
	{

		int varNumber = optData->VarCount();
		int indexInx = 0;
		for (size_t i = 1; i <= varNumber; i++)
		{
			auto varData = optData->GetVarData(i);
			string value = varData.VarName();

			///find and replace the variable
			size_t pos = modified.find(value, 0);
			while (pos != string::npos)////if find the occurance
			{
				string replace = "x[" + std::to_string(indexInx) + "]";
				modified.replace(pos, value.length(), replace);

				pos = modified.find(value, 0);
			}
			indexInx++;

		}



		return modified;

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

	void  OptimizationCommand::CallNloptOptimize(const OptimizationData* optData, NloptPara* nloptPara, OptimizationResult* optResult)
	{

		////Get the total amount of variable.
		size_t numberVariable = optData->VarCount();
		
		
		//Set lower bound, upper bound, initial value...
		vector<double> lb(numberVariable);
		vector<double> ub(numberVariable);
		vector<double> x(numberVariable);

		for (size_t index = 0; index<numberVariable; index++)
		{
			auto varData = optData->GetVarData(index+1);////the index start from one
			lb[index] = varData.Lb();
			ub[index] = varData.Ub();
			x[index]=varData.InitVal();
		}


		nlopt::opt opt(nlopt::LD_MMA, x.size());//LD_MMA //GN_DIRECT//LD_AUGLAG_EQ
		opt.set_lower_bounds(lb);
		opt.set_upper_bounds(ub);

		////Set static value for ObjFuncExcut::ObjFunction
		//ObjFuncExcut::_numOfVar = numberVariable;

		////Set the object function	
		//opt.set_min_objective(ObjFuncExcut::ObjFunction, NULL);
		opt.set_min_objective(ObjFuncExcut::ObjFunction, nloptPara);


		////Set the constraint function
		//opt.add_inequality_constraint(myvconstraint, &data[0], 1e-8);
		//opt.add_inequality_constraint(myvconstraint, &data[1], 1e-8);

		opt.set_xtol_rel(1e-4);


		double minf;
		nlopt::result result = opt.optimize(x, minf);
		
		SetOptResult(optResult, x,  minf);
	}

	//void OptimizationCommand::PushGradPointer(const int totalVariable)
	//{
	//	for (size_t i = 0; i<totalVariable; i++)
	//	{
	//		string className = "Grad";
	//		string indexStr = std::to_string(i);
	//		className += indexStr;
	//		//ObjFuncExcut::pushGradPnt(className);
	//	}
	//}

	void OptimizationCommand::SetOptResult(OptimizationResult * optResult, const vector<double> x, const double minf)
	{
		optResult->MinimumObj(minf);
		optResult->VecVariableReslt(x);

		////Add more, such as iteration time...

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

