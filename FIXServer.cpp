#include "FIXServer.h"
#include <iostream>
#include <boost/asio.hpp>

FIXServer::FIXServer(int _port):port(_port),m_stop(false)
{
    std::cout << "creating FIX Order Entry Server" << std::endl;
}

void FIXServer::launch(){
    m_thread.reset(new std::thread([this](){
                run();
                }));
}

void FIXServer::stop(){
    m_stop.store(true);
    m_thread->join();
}

void FIXServer::run(){
    Acceptor acc(m_ios, port);
    while(!m_stop.load()){
        acc.Accept();
    }
}
