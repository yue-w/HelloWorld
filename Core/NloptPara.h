#pragma once
#include<vector>
#include<string>
using namespace std;
class Grad;
class ObjectFunction;

class NloptPara
{
public:
	NloptPara();
	~NloptPara();

	ObjectFunction* GetObjectFunction() { return _objFunDefin; };
	void SetObjectFunction(ObjectFunction* val) { _objFunDefin = val; }

	void SetGradDefine(const vector<Grad*> val);
	Grad* GetOneGradDefine(int index) { return _gradDefin[index]; }
private:

	////Object Defination
	ObjectFunction* _objFunDefin;

	////gradient from dynamic compilation
	vector<Grad*> _gradDefin;


};

