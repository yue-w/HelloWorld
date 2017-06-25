#pragma once
#include "PublicHeader.h"

namespace Core
{
	const double DEFAULT_DOUBLE = 1e10;
	const string DEFAULT_STRING = "~!@##RWEFSDF@#ED";


	namespace CommonTool
	{
		template <class Type>
		Type StringToNum(const string& str)
		{
			stringstream iss(str);
			Type num;
			iss >> num;
			return num;
		}

		double StringToDouble(const string str);

		template <class Type>
		string Num2String(const Type& val)
		{
			stringstream iss;
			iss << val;
			return iss.str();
		}

		//Return a string with format input.
		string StringFormat(const char * format, ...);
	}
}


