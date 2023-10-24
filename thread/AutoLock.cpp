#include "AutoLock.h"

using namespace rpc::thread;

AutoLock::AutoLock(Mutex* mutex)
{
    m_mutex = mutex;
    m_mutex->lock();
}

AutoLock::~AutoLock()
{
    m_mutex->unlock();
}
