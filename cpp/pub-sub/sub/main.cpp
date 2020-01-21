
#include <zmq.hpp>
#include <iostream>
#include <sstream>
#include <thread>

int main( int argc, char** argv ){
    if ( argc < 3 ){
        std::cerr << "address> <port>" << std::endl;
        return 1;
    }
    
    std::string publisherAddress ( argv[1] );
    std::stringstream portSs;
    portSs << argv[2];

    zmq::context_t context(1);
    zmq::socket_t subscriber( context, zmq::socket_type::sub );
    std::string address = "tcp://" +   publisherAddress + ":" + portSs.str();
    
    subscriber.connect(address);
    const char* filter = "topic1";
    subscriber.setsockopt(ZMQ_SUBSCRIBE, filter, strlen(filter));

    while(true){
        
        zmq::message_t header;
        zmq::message_t body;

        subscriber.recv(&header);
        subscriber.recv(&body);

        std::cout << (char*)body.data() << std::endl;

    }
    
    return 0;
}