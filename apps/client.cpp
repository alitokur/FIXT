#include <iostream>
#include <boost/asio.hpp>

using namespace boost::asio;
using ip::tcp;

int main() {
  try {
    // Create a TCP socket
    io_context io_context;
    tcp::socket socket(io_context);

    // Connect to the server
    tcp::endpoint endpoint(ip::address::from_string("127.0.0.1"), 1234);
    socket.connect(endpoint);

    // Send a message to the server
    std::string message = "Hello, server!";
    boost::asio::write(socket, boost::asio::buffer(message));

    // Receive a response from the server
    boost::asio::streambuf receive_buffer;
    boost::system::error_code error;
    size_t len = boost::asio::read_until(socket, receive_buffer, "\n", error);

    if (error == boost::asio::error::eof) {
      // The connection was closed by the server
      std::cout << "Connection closed by server" << std::endl;
    }
    else if (error) {
      // Some other error occurred
      throw boost::system::system_error(error);
    }
    else {
      // Process the response from the server
      std::string response = boost::asio::buffer_cast<const char*>(receive_buffer.data());
      std::cout << "Response from server: " << response << std::endl;
    }
  }
  catch (std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  return 0;
}

