#pragma once
#include "PublicHeader.h"
namespace Core
{
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

		template <class Type>
		string Num2String(const Type& val)
		{
			stringstream iss;
			iss << val;
			return iss.str();
		}
	}
}


