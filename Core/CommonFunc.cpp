#include "CommonFunc.h"

#include "windows.h"  

namespace Core
{
	namespace CommonTool
	{

		double StringToDouble(const string str)
		{
			return atof(str.c_str());
		}

		string StringFormat(const char * format, ...)
		{
			va_list args;
			va_start(args, format);

			const int bufferSize = 1024;
			char buff[bufferSize];
			int result = vsnprintf(buff, bufferSize - 1, format, args);

			va_end(args);

			return buff;
		}
	}
}

