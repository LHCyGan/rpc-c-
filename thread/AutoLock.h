#pragma once

#include "Mutex.h"

namespace rpc {
namespace thread {

class AutoLock
{
public:
    AutoLock(Mutex* mutex);
    ~AutoLock();

private:
    Mutex* m_mutex;
};

}}
