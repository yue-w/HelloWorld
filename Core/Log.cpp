#include "Log.h"

#include "log4cpp/Category.hh"
#include "log4cpp/Appender.hh"
#include "log4cpp/FileAppender.hh"
#include "log4cpp/OstreamAppender.hh"
#include "log4cpp/Layout.hh"
#include "log4cpp/BasicLayout.hh"
#include "log4cpp/Priority.hh"
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/NDC.hh>

namespace Core
{
	namespace CommonTool
	{

		log4cpp::Category * Log::root = Log::InitializeLog();


		void Log::Info(const string format, const double arg /*= ""*/)
		{
			root->info(format.c_str(), arg);
		}


		void Log::PushNDC(const string content)
		{
			log4cpp::NDC::push(content);
		}

		void Log::PopNDC()
		{
			log4cpp::NDC::pop();
		}

		log4cpp::Category* Log::InitializeLog()
		{
			//Initialize me with log4cpp.Referenced from http://log4cpp.sourceforge.net.

			auto fileLayout1 = new log4cpp::PatternLayout();
			fileLayout1->setConversionPattern("%d [%p] [%x] %m%n");

			log4cpp::Appender *appender1 = new log4cpp::OstreamAppender("console", &std::cout);
			appender1->setLayout(fileLayout1);

			auto fileLayout2 = new log4cpp::PatternLayout();
			fileLayout2->setConversionPattern("%d [%p] [%x] %m%n");

			log4cpp::Appender *appender2 = new log4cpp::FileAppender("default", "loginfo.log");
			appender2->setLayout(fileLayout2);

			log4cpp::Category* root = &log4cpp::Category::getRoot();
			root->setPriority(log4cpp::Priority::DEBUG);
			root->addAppender(appender1);
			//root->addAppender(appender2);

			return root;
		}

	}
}


