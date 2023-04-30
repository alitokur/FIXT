#include "FIXServer.h"
#include <iostream>
#include <boost/asio.hpp>

FIXServer::FIXServer(int _port):port(_port)
{
    std::cout << "creating FIX Order Entry Server" << std::endl;
}

void FIXServer::launch(){
    m_thread.reset(new std::thread([this](){
                run();
                }));
}

void FIXServer::run(){
    Acceptor acc(m_ios, port);
    while(!m_stop){
        acc.Accept();
    }
}
