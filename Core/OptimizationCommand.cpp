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
#include "NloptPara.h"
#include "CompileIneqlCnstFuncExcut.h"
#include "InequalConstraintFuncExcute.h"
#include "InequalCnstrntFunc.h"

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
		string pathObj;
		string pathGrad;
		string pathExcuGrad;
		string pathInequal;
		string pathExcuInequal;

		bool debugInVS = false;
		if (debugInVS)
		{
			pathObj = "..\\Core\\ObjectFunction.cpp";//////Path used for debugging in VS
			pathGrad = "..\\Core\\Grad";////For debugging in VS
			pathExcuGrad = "..\\Core\\CompileGradExcut.cpp";////Path for debugging in VS
			pathInequal = "..\\Core\\InequalCnstrntFunc";////For debugging in VS
			pathExcuInequal = "..\\Core\\CompileIneqlCnstFuncExcut.cpp";////Path for debugging in VS

		}
		else {
			pathObj = "..\\..\\..\\Core\\ObjectFunction.cpp";
			pathGrad = "..\\..\\..\\Core\\Grad";
			pathExcuGrad = "..\\..\\..\\Core\\CompileGradExcut.cpp";
			pathInequal = "..\\..\\..\\Core\\InequalCnstrntFunc";
			pathExcuInequal = "..\\..\\..\\Core\\CompileIneqlCnstFuncExcut.cpp";

		}
		////objFunc is the string that contains the modified object function.
		DataParser dataParser(data);
		dataParser.Parse();
		OptimizationData optData = dataParser.GetParsedData();
		string objFunc = modifyObjectFunc(&optData);

		//Parse the objective function and dynamic compiling
		ObjectFuncParser parser;
		//string pathObj = "..\\Core\\ObjectFunction.cpp";//////Path used for debugging in VS
		//string pathObj = "..\\..\\..\\Core\\ObjectFunction.cpp";//Path used in Qt
		parser.Parse(objFunc, pathObj);
		IFunction* iFunctionObjFunc = parser.DynamicCompile("ObjectFunction");
		ObjectFunction* func = dynamic_cast<ObjectFunction*>(iFunctionObjFunc);
		////Pass object function to the NloptPara, which will bring it ot nlopt
		NloptPara* nloptPara = new NloptPara;
		ObjectFunction* objFun = dynamic_cast<ObjectFunction*> (func);
		nloptPara->SetObjectFunction(objFun);

		////Compile Gradient for Object Function.
		//string pathGrad = "..\\Core\\Grad";////For debugging in VS
		//string pathExcuGrad = "..\\Core\\CompileGradExcut.cpp";////Path for debugging in VS
		//string pathGrad = "..\\..\\..\\Core\\Grad";////Path used for Qt
		//string pathExcuGrad = "..\\..\\..\\Core\\CompileGradExcut.cpp";////Path used for Qt
		OptMethodClass optMthod = optData.GetOptMethod();
		if (optMthod.GetDynamicComp())
		{
			CompileGrad(pathGrad, pathExcuGrad, &optData, nloptPara);
		}


		//Parse the inequality constraint function
		//string pathInequal = "..\\Core\\InequalCnstrntFunc";////For debugging in VS
		//string pathExcuInequal = "..\\Core\\CompileIneqlCnstFuncExcut.cpp";////Path for debugging in VS
		//string pathInequal = "..\\..\\..\\Core\\InequalCnstrntFunc";////Path used for Qt
		//string pathExcuInequal = "..\\..\\..\\Core\\CompileIneqlCnstFuncExcut.cpp";////Path used for Qt
		//vector<string> vecInequalCnstFuncs = ModifyInequalConstraints(&optData);
		CompileInequalCnstFunc(pathInequal, pathExcuInequal, &optData, nloptPara);
		

		if (func == NULL)
		{
			Log::Info("func is null");
			
			_outData = NULL;
		}
		else
		{
			//NloptPara* nloptPara = new NloptPara();
			//nloptPara->SetGradDefine(comPilExcu->GetGradDefineVector());



			//Optimization reslut
			OptimizationResult* optResult = new OptimizationResult(&optData);

			////Excute. Call NLOPT
			CallNloptOptimize(&optData,nloptPara, optResult);

			//vector<std::string> varNameKeys = data->getVecVariableNameKeys();

			InverseDataParser inverseDataParser(optResult);
			inverseDataParser.Parse();
			DataWrapper* outPutWraper = inverseDataParser.GetParsedData();
			_outData = outPutWraper;
			
		}

	}

	string OptimizationCommand::modifyObjectFunc(const OptimizationData* optData)
	{
		string objFunc = optData->GetObjFunc();////Object function input by the user
		return ChangeNameToIndex(objFunc, optData);
		
		
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
	vector<string> OptimizationCommand::ModifyInequalConstraints(const OptimizationData * optData)
	{
		size_t numOfCnsts = optData->GetInequalCnstFunc().size();
		vector<string> changedStrings(numOfCnsts);
		for (size_t i = 0; i < numOfCnsts; i++)
		{
			changedStrings[i] = ChangeNameToIndex(optData->GetInequalCnstFunc()[i], optData);
		}

		return changedStrings;
	}
	std::vector<string> OptimizationCommand::ModifyGrad(const OptimizationData * optData)
	{
		int varNumber = optData->VarCount();

		////will be returned.
		std::vector<string> grad(varNumber);
		
		//int indexInx = 0;
		for (size_t i = 1; i <= varNumber; i++)
		{
			auto varData = optData->GetVarData(i);
			string modifiedGrad = varData.Grad();

			grad[i - 1] = ChangeNameToIndex(modifiedGrad, optData);
			//grad[i - 1] = modifiedGrad;
		}

		return grad;
	}

	std::vector<vector<string>> OptimizationCommand::ModifyGrad_Inequal(const OptimizationData * optData)
	{
		FunctionData funData = optData->GetFuncData();
		int inequalCnstNum = funData.InEqualConstrnFun().size();
		int varNumber = optData->VarCount();
		//will be returned
		std::vector<vector<string>> vecGrad(inequalCnstNum,vector<string>(varNumber));

		////all the grads for one constraint function
		//std::vector<string> grad(varNumber);


		////loop for each variable
		for (size_t i_grad = 1; i_grad <= varNumber; i_grad++)
		{
			auto varData = optData->GetVarData(i_grad);
			vector<string> modifiedGrad = varData.GradInequalCnstrt();

			//Loop for each inequality constraint function
			for (size_t i_cnstrtF = 0; i_cnstrtF < inequalCnstNum; i_cnstrtF++)
			{
				vecGrad[i_cnstrtF][i_grad-1] = ChangeNameToIndex(modifiedGrad[i_cnstrtF], optData);
			}
			
			//grad[i - 1] = modifiedGrad;
		}
		


		return vecGrad;
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
	string OptimizationCommand::ChangeNameToIndex(string  originString, const OptimizationData* optData)
	{

		int varNumber = optData->VarCount();
		int indexInx = 0;
		for (size_t i = 1; i <= varNumber; i++)
		{
			auto varData = optData->GetVarData(i);
			string value = varData.VarName();

			///find and replace the variable
			size_t pos = originString.find(value, 0);
			while (pos != string::npos)////if find the occurance
			{
				string replace = "x[" + std::to_string(indexInx) + "]";
				originString.replace(pos, value.length(), replace);

				pos = originString.find(value, 0);
			}
			indexInx++;

		}



		return originString;

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

		//int test = nlopt::LD_MMA;
		//nlopt::opt opt(nlopt::LD_MMA, x.size());//LD_MMA //GN_DIRECT//LD_AUGLAG_EQ
		nlopt::algorithm optMethod= optData->GetOptMethod().GetOptMethod();
		nlopt::opt opt(optMethod, x.size());//LD_MMA //GN_DIRECT//LD_AUGLAG_EQ
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

		
		size_t numInequalConst = optData->GetInequalCnstFunc().size();
		
		vector<vector<Grad*>> gradForInequalFUnc = nloptPara->GetGradDefineInequalFunc();
		for (size_t i = 0; i < numInequalConst; i++)
		{
			InequalCnstrntFunc* oneInequalDefine=nloptPara->GetOneInequCntrntDefine(i);
			NloptPara_OneInequalityConstraint* oneInequalFuncPara = new NloptPara_OneInequalityConstraint(oneInequalDefine, gradForInequalFUnc[i]);

			opt.add_inequality_constraint(InequalConstraintFuncExcute::InequalConstraintFunction, oneInequalFuncPara,1e-6);
		}

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

	void OptimizationCommand::CompileGrad(const string pathGrad, const string pathExcu, const OptimizationData* optData, NloptPara* nloptPara)
	{
		////Grad for the object function
		vector<string> grad = ModifyGrad(optData);
		//parse the gradient
		GradPasser gradPasser;
		vector<string> vecClassName(grad.size());
		for (size_t i = 0; i<grad.size(); i++)
		{
			string className = "";

			gradPasser.Parse(grad[i], pathGrad, i, className);
			vecClassName[i] = className;
		}

		///Grad for the inequality constraint function
		vector<vector<string>> grad_inequal = ModifyGrad_Inequal(optData);
		vector<string> vecClassNameInequalGrad;
		for (size_t i_inequalFun = 0; i_inequalFun<grad_inequal.size(); i_inequalFun++)
		{
			string className = "";
			for (size_t i_grad = 0; i_grad < grad_inequal[i_inequalFun].size(); i_grad++)
			{
				////the index start from 1. "Grad21" means 2nd inequality functin, and the grad for the 1st variable.
				int index = 10 * (i_inequalFun+1) + (i_grad+1);
				gradPasser.Parse(grad_inequal[i_inequalFun][i_grad], pathGrad, index, className);
				vecClassNameInequalGrad.push_back(className);
			}
			
			
		}

		//Compile grad.cpp
		IFunction* iFuncGrad = gradPasser.DynamicCompile("Grad");



		///////Push defination of grad to the vector. -Object function
		ExcuteGradParser excuPasser;
		excuPasser.Parse(pathExcu, vecClassName);

		////Push defination of grad to the vector. -Inequality constraint function
		excuPasser.ParseInequalGrad(pathExcu, vecClassNameInequalGrad);
	
		
		IFunction* iFunc = excuPasser.DynamicCompile("CompileGradExcut");

		CompileGradExcut* comPilExcu = dynamic_cast<CompileGradExcut*>(iFunc);
		////Push the run time defination of gradient of the object function 
		comPilExcu->PushGradPointer();
		////Push the run time defination of gradient of the inequality constraint function 

		comPilExcu->PushGradPointer_InequalfuncGrad();

		
		vector<vector<Grad*>> twoDimGrad = OneDToTwoD(optData->VarCount(),comPilExcu->GetTemGrad());
		comPilExcu->SetGradDefineVectorInequal(twoDimGrad);
			
		
		nloptPara->SetGradDefine(comPilExcu->GetGradDefineVector());

		nloptPara->SetGradDefineInequalFunc(comPilExcu->GetGradDefineVectorInequal());
	}

	vector<vector<Grad*>> OptimizationCommand::OneDToTwoD(int varNum, const vector<Grad*> oneDGrad)
	{
		vector<vector<Grad*>> twoDVec;
		vector<Grad*> temGrad;
		for (size_t i = 0; i < oneDGrad.size(); )
		{
			for (size_t j = 0; j < varNum; j++)
			{
				temGrad.push_back(oneDGrad[i]);
				i++;
			}
			
			twoDVec.push_back(temGrad);
			temGrad.clear();
			//i += varNum;
		}
		return twoDVec;
	}

	void OptimizationCommand::CompileInequalCnstFunc(const string pathIneqCnstfunc, const string pathExcu, const OptimizationData * optData, NloptPara * nloptPara)
	{
		vector<string> vecInequalCnstFuncs = ModifyInequalConstraints(optData);
		size_t length= vecInequalCnstFuncs.size();
		if (0!=length)
		{
			//parse the gradient
			InequalConstrtFunParser Passer;
			vector<string> vecClassName(length);
			for (size_t i = 0; i < length; i++)
			{
				string className = "";
				Passer.Parse(vecInequalCnstFuncs[i], pathIneqCnstfunc, i, className);
				vecClassName[i] = className;
			}
			IFunction* iFuncInequal = Passer.DynamicCompile("InequalCnstrntFunc");

			ExcuteInequalConstrtParser excuPasser;
			excuPasser.Parse(pathExcu, vecClassName);
			IFunction* iFuncInequalExc = excuPasser.DynamicCompile("CompileIneqlCnstFuncExcut");

			CompileIneqlCnstFuncExcut* comPilExcu = dynamic_cast<CompileIneqlCnstFuncExcut*>(iFuncInequalExc);
			comPilExcu->PushInequFuncPointer();


			nloptPara->SetInequCntrntDefine(comPilExcu->GetIneqFuncDefin());
		}
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

