#include "Acceptor.h"

void Acceptor::Accept()
{
    boost::asio::ip::tcp::socket sock(m_ios);
    m_acceptor.accept(sock);
    Service svc;
    svc.HandleClient(sock);
}
