include_directories(../include)
add_executable(run_server main.cpp FIXServer.cpp Service.cpp Acceptor.cpp)
target_link_libraries(run_server Boost::system)
