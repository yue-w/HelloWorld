#pragma once
#include<vector>
#include<string>
using namespace std;
class Grad;

class NloptPara
{
public:
	NloptPara();
	~NloptPara();

	void SetGradDefine(const vector<Grad*> val);
	Grad* GetOneGradDefine(int index) { return _gradDefin[index]; }
private:

	////gradient from dynamic compilation
	vector<Grad*> _gradDefin;

};

