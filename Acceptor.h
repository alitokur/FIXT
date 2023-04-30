#include <boost/asio.hpp>
#include "Service.h"

class Acceptor{
    public:
        Acceptor(boost::asio::io_service& ios, unsigned short port):
            m_ios(ios), m_acceptor(
                    m_ios, 
                    boost::asio::ip::tcp::endpoint(boost::asio::ip::address_v4::any(),port)){
            m_acceptor.listen();
        }

        void Accept();

    private:
        boost::asio::io_service& m_ios;
        boost::asio::ip::tcp::acceptor m_acceptor;
};
