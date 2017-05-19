#pragma once
#include "PublicHeader.h"
#include <mutex> 

namespace Core
{
	class ThreadLocker
	{
		std::mutex &_mutex;
	public:
		ThreadLocker(mutex &m);
		~ThreadLocker();
	};
}


