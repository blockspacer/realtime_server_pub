#ifndef COMMAND_DISPATCHER_H
#define COMMAND_DISPATCHER_H

#include "fw_env.h"
#include <vector>
#include <boost/asio.hpp>

BEGIN_NS

struct UdpCommandInfo : public SmartPtr<UdpCommandInfo>
{
    typedef boost::intrusive_ptr<UdpCommandInfo> ptr;
    
    std::vector<unsigned char> packet;
    boost::asio::ip::udp::endpoint ep;
    
    UdpCommandInfo()
    {
        //
    }
};

class CommandDispatcher
{
public:
    static bool bulkDispatchUDP(UdpCommandInfo::ptr command_info);
    static bool bulkDispatch(int64_t actor_key,
        const std::vector<unsigned char>& data);

private:
    static bool dispatchDataUDP(const boost::asio::ip::udp::endpoint& end_point, 
        int op_code, int start_index, int data_size, 
        const std::vector<unsigned char>& data);
    static bool dispatchData(int64_t actor_key,
        int op_code, int start_index, int data_size, 
        const std::vector<unsigned char>& data);
};

END_NS

#endif
