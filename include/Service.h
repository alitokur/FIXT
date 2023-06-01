#include <boost/asio.hpp>

#include <thread>
#include <atomic>
#include <memory>
#include <iostream>

class Service{
    public:
        Service();
        void HandleClient(boost::asio::ip::tcp::socket& sock);
};
