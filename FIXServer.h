
#include <algorithm>
#include <iostream>
class FIXServer{
    public:
        FIXServer(int _port);
    private:
        int port;
        bool running;
};

