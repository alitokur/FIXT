#include <boost/asio.hpp>
#include "Service.h"

class Acceptor{
    public:
        Acceptor(boost::asio::io_service& ios, unsigned short port);
        void Accept();

    private:
        boost::asio::io_service& m_ios;
        boost::asio::ip::tcp::acceptor m_acceptor;
};
