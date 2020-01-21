
#include <zmq.hpp>
#include <iostream>
#include <sstream>
#include <thread>

int main( int argc, char** argv ){
    if ( argc < 2 ){
        std::cerr << "TCP Port was not specified" << std::endl;
        return 1;
    }
    
    std::stringstream portSs;
    portSs << argv[1];


    zmq::context_t context(1);
    zmq::socket_t publisher( context, zmq::socket_type::pub );
    std::string address = "tcp://*:" +  portSs.str();
    
    publisher.bind(address);

    while(true){
        
        const char* header = "topic1";
        zmq::message_t headerMessage( header, strlen(header) );
        
        const char* body = "hello world!";
        zmq::message_t bodyMessage( body, strlen(body));

        publisher.send(headerMessage, ZMQ_SNDMORE);
        publisher.send(bodyMessage);

        std::this_thread::sleep_for( std::chrono::seconds(1));

    }
    
    return 0;
}