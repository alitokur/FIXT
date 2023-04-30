#include <iostream>
#include <boost/asio.hpp>
#include "Acceptor.h"

class FIXServer{
    public:
        FIXServer(int);
        void launch(); 
        void stop();

    private:
        void run();
        int port;
        std::unique_ptr<std::thread>m_thread;
        std::atomic<bool>m_stop;
        boost::asio::io_service m_ios;
};

