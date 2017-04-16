#pragma once
#include <string>

using namespace std;

namespace log4cpp
{
	class Category;
}

namespace CommonTool
{
	class Log
	{
		static log4cpp::Category *root;

	public:

		//Log information.
		static void Info(const string format, const double arg = 0);

		static void PushNDC(const string content);
		static void PopNDC();

	private:

		static log4cpp::Category* InitializeLog();
	};
}


