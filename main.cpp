#include <iostream>
#include <ostream>
#include <thread>
#include "FIXServer.h"

int main(){
    unsigned short port = 1234;
    try{
        FIXServer order_entry_point{ port };
        order_entry_point.launch();
        std::this_thread::sleep_for(std::chrono::seconds(60));
        order_entry_point.stop();
    }
    catch(boost::system::system_error &e){
        std::cout << "Server can't launch" << std::endl;
        std::cout << "Error Code: " << e.what() << std::endl;
    }
    return 0;
}
