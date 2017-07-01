#include "OptMthdParser.h"
#include "../Middleware/nlopt/include/nlopt.hpp"
#include "OptimizationData.h"

namespace Core
{
	OptMthdParser::OptMthdParser()
	{
		OptMethodClass mLDMMA (nlopt::LD_MMA,true);
		_optMthd["0"] = mLDMMA;

		OptMethodClass mLNCOBYLA(nlopt::LN_COBYLA, false);
		_optMthd["1"] = mLNCOBYLA ;
	}


	OptMthdParser::~OptMthdParser()
	{
	}

	OptMethodClass OptMthdParser::Parse(std::string val)
	{
		if (_optMthd.find(val) != _optMthd.end())
		{
			return _optMthd.at(val);
		}
		else
			throw;

	}

}


