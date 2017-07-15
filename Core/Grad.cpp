#include "Grad.h"
#include "../Middleware/rcc/include/RuntimeObjectSystem/ObjectInterfacePerModule.h"

//Register the name of the class.
REGISTERCLASS(Grad);

//Grad::Grad()
//{
//}
// 
//
//Grad::~Grad()
//{
//}

double Grad::Compute(const std::vector<double>& x) const
{

	//insert grad here
	double gradValue = 0.0;

	return gradValue;
}




//Gradient Class CPP file-insert start
double	Grad0::Compute(const std::vector<double>& x) const
{
double gradValue=0;
return gradValue;
}
REGISTERCLASS(Grad0);
double	Grad1::Compute(const std::vector<double>& x) const
{
double gradValue=0.5/sqrt(x[1]);
return gradValue;
}
REGISTERCLASS(Grad1);
double	Grad11::Compute(const std::vector<double>& x) const
{
double gradValue=24*x[0]*x[0];
return gradValue;
}
REGISTERCLASS(Grad11);
double	Grad12::Compute(const std::vector<double>& x) const
{
double gradValue=-1;
return gradValue;
}
REGISTERCLASS(Grad12);
double	Grad21::Compute(const std::vector<double>& x) const
{
double gradValue=-10;
return gradValue;
}
REGISTERCLASS(Grad21);
double	Grad22::Compute(const std::vector<double>& x) const
{
double gradValue=-1;
return gradValue;
}
REGISTERCLASS(Grad22);

//Gradient Class CPP file-insert end


//REGISTERCLASS(InequalCnsrntGrad)
