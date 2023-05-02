#include <iostream>
#include <boost/asio.hpp>

class SyncTcpClient{
    public:
        SyncTcpClient(const std::string& raw_ip_address,
                unsigned short port_num):
            m_ep(boost::asio::ip::address::from_string(raw_ip_address), port_num),
            m_sock(m_ios){
                m_sock.open(m_ep.protocol());
            }

        void connect(){
            m_sock.connect(m_ep);
        }

        void close(){
            m_sock.shutdown(boost::asio::ip::tcp::socket::shutdown_both);
            m_sock.close();
        }
        
        std::string test_computation(){
            std::string request = "emulate_long_comp_op\n";
            send_request(request);
            return receiveResponse();
        }




    private:
        
        boost::asio::io_service m_ios;
        boost::asio::ip::tcp::endpoint m_ep;
        boost::asio::ip::tcp::socket m_sock;
    
        void send_request(const std::string& request){
            boost::asio::write(m_sock, boost::asio::buffer(request));
        }

        std::string receiveResponse(){
            boost::asio::streambuf buf;
            boost::asio::read_until(m_sock, buf, '\n');
            std::istream input(&buf);
            std::string response;
            std::getline(input, response);
            return response;
        }
};

int main() {
    const std::string raw_ip_address = "127.0.0.1";
    const unsigned short port_num = 1234;
    try {
        SyncTcpClient client(raw_ip_address, port_num);
        client.connect();
        std::cout << "sending request to the server..." << std::endl;
        // Connect to the server
        std::string response = client.test_computation();
        std::cout << "response received: " << response << std::endl;
        client.close();
    }
  catch (boost::system::system_error &e) {
    std::cerr << "Exception: " << e.code()  << "what " << e.what() << std::endl;
  }

  return 0;
}

