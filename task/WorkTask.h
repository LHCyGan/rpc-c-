#pragma once

#include "../thread/Task.h"
using namespace rpc::thread;

#include "../socket/Socket.h"
using namespace rpc::socket;

namespace rpc {
namespace task {

struct MsgHead {
    char flag[8];
    uint32_t cmd;
    uint32_t len;
};

const uint32_t recv_buff_size = 1024;


class WorkTask : public Task
{
public:
    WorkTask(Socket * socket);
    virtual ~WorkTask();

    virtual void run();
    virtual void destroy();
};

}}
