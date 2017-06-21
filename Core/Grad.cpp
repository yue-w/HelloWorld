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
double gradValue=2*x[0]-2;
return gradValue;
}
REGISTERCLASS(Grad0);
double	Grad1::Compute(const std::vector<double>& x) const
{
double gradValue=2*x[1]-8;
return gradValue;
}
REGISTERCLASS(Grad1);

//Gradient Class CPP file-insert end
