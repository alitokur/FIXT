#include "FIXServer.h"
#include <iostream>
#include <boost/asio.hpp>

FIXServer::FIXServer(int _port):port(_port), running(false)
{
    std::cout << "creating FIX Order Entry Server" << std::endl;
    boost::asio::io_context io_context;
    boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::tcp::v4(), _port);
    boost::asio::ip::tcp::acceptor acceptor(io_context, endpoint); 
    while (true) {
        std::cout << "here we are" << std::endl; 
        boost::asio::ip::tcp::socket socket(io_context);
        acceptor.accept(socket);
        std::cout << "incoming connection from " << 
            socket.remote_endpoint().address().to_string() << std::endl;

        boost::system::error_code ec;

        //read data from socket
        char data[1024];
        size_t length = socket.read_some(boost::asio::buffer(data), ec);

        std::string ciao = "hello from server!";
        boost::asio::write(socket, boost::asio::buffer(ciao), ec);
    }
    std::cout << "END OF WHILE" << std::endl;
}

