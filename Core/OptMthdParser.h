#pragma once
#include "PublicHeader.h"
//#include "../Middleware/nlopt/include/nlopt.hpp"

namespace nlopt
{
	enum  algorithm;
}
namespace Core
{
	class OptMethodClass;
	class OptMthdParser
	{

	//unordered_map<string, nlopt::algorithm> _optMthd;
	unordered_map<string, OptMethodClass> _optMthd;
		
	public:
		OptMthdParser();
		~OptMthdParser();

		OptMethodClass Parse(std::string val);
	};
}


