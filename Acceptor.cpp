#include "Acceptor.h"

Acceptor::Acceptor(boost::asio::io_service& ios, unsigned short port):
    m_ios(ios), m_acceptor(
            m_ios, 
            boost::asio::ip::tcp::endpoint(boost::asio::ip::address_v4::any(),port)){
        m_acceptor.listen();
    }
void Acceptor::Accept()
{
    boost::asio::ip::tcp::socket sock(m_ios);
    m_acceptor.accept(sock);

    Service svc;
    svc.HandleClient(sock);
}
