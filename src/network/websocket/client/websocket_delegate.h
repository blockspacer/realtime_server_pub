#ifndef WEBSOCKET_DELEGATE_H
#define WEBSOCKET_DELEGATE_H

#include "fw_env.h"

#include "../packet.h"
#include <boost/system/error_code.hpp>

#include <functional>

BEGIN_NS

namespace client {

class WebsocketAsync;

class WebsocketDelegate
{
public:
    enum class Operation {
        CONNECT,
        WRITE,
        READ
    };
    
    virtual ~WebsocketDelegate() {}

    virtual void onStart(WebsocketAsync* ws) = 0;

    virtual void onReceive(WebsocketAsync* ws,
        PacketData::ptr) = 0;
    virtual void onReceiveFinish(WebsocketAsync* ws,
        boost::system::error_code ec) = 0;
    virtual void onSendFinish(WebsocketAsync* ws,
        boost::system::error_code ec) = 0;

    virtual void onError(WebsocketAsync* ws,
        Operation operation, boost::system::error_code ec) = 0;
};

};

END_NS

#endif
