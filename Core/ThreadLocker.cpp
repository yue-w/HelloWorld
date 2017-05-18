#include "ThreadLocker.h"


namespace Core
{
	ThreadLocker::ThreadLocker(mutex &m):_mutex(m)
	{
		_mutex.lock();
	}


	ThreadLocker::~ThreadLocker()
	{
		_mutex.unlock();
	}
}

