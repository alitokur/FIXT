#include "FIXServer.h"
#include <iostream>

FIXServer::FIXServer(int _port):port(_port), running(false)
{
    std::cout << "creating FIX Order Entry Server" << std::endl;
}

