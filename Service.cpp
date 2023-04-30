#include "Service.h"

Service::Service(){
    //def constructor
}

void Service::HandleClient(boost::asio::ip::tcp::socket& sock){
    try{
        boost::asio::streambuf request;
        boost::asio::read_until(sock, request, "\n");

        //now we can process the received message

        std::string response = "badcode§\n";
        boost::asio::write(sock, boost::asio::buffer(response));
    }
    catch(boost::system::system_error& e){
        std::cout << "Error Occured" << e.what() << std::endl;
    }
}
