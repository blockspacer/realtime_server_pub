#ifndef ASYNC_SSL_SOCKET_H
#define ASYNC_SSL_SOCKET_H

#include "async_socket_inf.h"

#include <string>
#include <boost/asio/ssl.hpp>

class AsyncSSLSocket : public AsyncSocketInf
{
public:
    enum class VerifyMode {
        VERIFY_NODE = boost::asio::ssl::context::verify_none,
        VERIFY_PEER = boost::asio::ssl::context::verify_peer,
        VERIFY_CLIENT_ONCE = boost::asio::ssl::context::verify_client_once,
        VERIFY_PEER_FAIL_IF_NO_PEER_CERT = boost::asio::ssl::context::verify_fail_if_no_peer_cert
    };
    
    AsyncSSLSocket(boost::asio::io_service& _ios, 
        const std::string& _host, unsigned int _port, bool _server_mode = false);
    AsyncSSLSocket(boost::asio::io_service& _ios, 
        const std::string& _host, const std::string& _protocol, bool _server_mode = false);
    ~AsyncSSLSocket();
    
    void setVerifyMode(VerifyMode verify_mode);
    void loadCertificate(const ByteBuffer& buffer);
    void loadPrivateKey(const ByteBuffer& buffer);
    
    virtual void connect(boost::posix_time::time_duration timeout, 
        SocketConnectCallback callback) override;
    virtual void close() override;
    
    virtual bool isOpen() override;
    
    virtual void read(boost::posix_time::time_duration timeout, 
        SocketReadCallback callback) override;
    virtual void write(const ByteBuffer& buffer, boost::posix_time::time_duration timeout, 
        SocketWriteCallback callback) override;
    
    virtual std::string getHost() override;
    virtual std::string getProtocol() override;
    
    virtual void setConnectTimeoutCallback(SocketTimeoutCallback callback) override;
    virtual void setReadTimeoutCallback(SocketTimeoutCallback callback) override;
    virtual void setWriteTimeoutCallback(SocketTimeoutCallback callback) override;
    
private:
    void initTimer();
    void connectInternal(boost::system::error_code err,
        boost::asio::ip::tcp::resolver::iterator endpoint_it,
        boost::posix_time::time_duration timeout,
        SocketConnectCallback callback);
    
    void checkConnectDeadline();
    void checkReadDeadline();
    void checkWriteDeadline();
    
    void handshake(boost::posix_time::time_duration timeout,
        SocketConnectCallback callback);
    
    std::string passwordCallback() const;
    
    std::string host;
    std::string protocol;
    bool server_mode;

    boost::asio::io_service& ios;
    boost::asio::ssl::stream<boost::asio::ip::tcp::socket>* socket;
    boost::asio::ssl::context* ssl_context;
    
    boost::asio::deadline_timer connect_timer;
    boost::asio::deadline_timer read_timer;
    boost::asio::deadline_timer write_timer;
    
    SocketTimeoutCallback connect_timeout_func;
    SocketTimeoutCallback read_timeout_func;
    SocketTimeoutCallback write_timeout_func;

    enum { MAX_LENGTH = 8192 };
    char data[MAX_LENGTH];
};

#endif
