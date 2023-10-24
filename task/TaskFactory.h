#pragma once

#include "../socket/Socket.h"
using namespace rpc::socket;

#include "../thread/Task.h"
using namespace rpc::thread;

#include "../task/WorkTask.h"
using namespace rpc::task;

namespace rpc {
namespace task {

class TaskFactory
{
public:
    static Task * create(Socket * socket)
    {
        return new WorkTask(socket);
    }
};

}}