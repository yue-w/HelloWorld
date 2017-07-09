#pragma once
#include<vector>
#include<string>
using namespace std;
class Grad;
class ObjectFunction;
class InequalCnstrntFunc;

class NloptPara
{
public:
	NloptPara();
	~NloptPara();

	ObjectFunction* GetObjectFunction() { return _objFunDefin; };
	void SetObjectFunction(ObjectFunction* val) { _objFunDefin = val; }

	void SetGradDefine(const vector<Grad*> val);
	Grad* GetOneGradDefine(int index) { return _gradDefin[index]; }

	void SetInequCntrntDefine(const vector<InequalCnstrntFunc*> val) { _inequalCnstrtDefine = val; }
	InequalCnstrntFunc* GetOneInequCntrntDefine(int index) {return _inequalCnstrtDefine[index];}

	void SetGradDefineInequalFunc(vector<vector<Grad*>>  val) { _gradDefine_InequalFunc = val; }
	vector<vector<Grad*>> GetGradDefineInequalFunc() { return _gradDefine_InequalFunc; }

private:

	////Object Defination
	ObjectFunction* _objFunDefin;

	////gradient from dynamic compilation
	vector<Grad*> _gradDefin;

	////Inequality constraint function from dynamic compilation
	vector<InequalCnstrntFunc*> _inequalCnstrtDefine;

	vector<vector<Grad*>> _gradDefine_InequalFunc;


};

//class OneInequalCnstFunAndGradDefin
//{
//public:
//	OneInequalCnstFunAndGradDefin() {};
//	~OneInequalCnstFunAndGradDefin() {};
//private:
//	InequalCnstrntFunc* _inequalFunc;
//
//};

class NloptPara_OneInequalityConstraint
{
public:
	//NloptPara_OneInequalityConstraint() {};
	NloptPara_OneInequalityConstraint(InequalCnstrntFunc* ineqFun, vector<Grad*> gradDefine);
	~NloptPara_OneInequalityConstraint() {};

private:
	InequalCnstrntFunc* _inequalityFunc;
	vector<Grad*> _gradDefine;

public:
	void SetOneInequalCnstFunAndGradDefin(InequalCnstrntFunc* val) { _inequalityFunc = val; }
	InequalCnstrntFunc* GetOneInequalCnstFunAndGradDefin() {	return _inequalityFunc;}

	void SetGrad(vector<Grad*> val) { _gradDefine = val; }
	vector<Grad*> GetGrad() { return _gradDefine; }
};