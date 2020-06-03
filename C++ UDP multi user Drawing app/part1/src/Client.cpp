#include "Client.hpp"

/*! \brief  ClientCommand Constructor
*
*   Description
*/
Client::Client(sf::IpAddress address, unsigned short port){
	clientIP = address;
	clientPort = port;
	socket.bind(clientPort);
	socket.setBlocking(false);
} 


/*! \brief  Client Deconstructor
*
*/
Client::~Client(){
	std::cout << "Client destructor called" << std::endl;
}

bool Client::is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

/*! \brief  launch function
*
*/
void Client::launch(unsigned short sPort){

	bool server_port_flag = false;
	std::string serverPort_str;
    
    std::cout << "============Initiating UDP Client==========" << std::endl;
	
    if (sPort != 0){
        serverPort = sPort;
    }else{
        do
        {
            std::cout << "Insert server port: ";
            std::cin >> serverPort_str;
            if(is_number(serverPort_str)){
                    server_port_flag = true;
            }
            else{
                std::cout<<"Invalid Port!! Enter a valid port " <<std::endl;
            }
        }
        while (server_port_flag ==false);

        serverPort = std::stoi(serverPort_str);
    }
    std::cout << "Confirming server port number as: " << serverPort << std::endl;

    std::string serverIPAddress;
    std::cout << "Connecting server ip... \n";
    if (sPort != 0){
        sf::IpAddress serverIPAddress_ = sf::IpAddress::getLocalAddress();
        std::string serverIPAddress = serverIPAddress_.toString();
    }else{
        std::getline(std::cin,serverIPAddress);
    }
	sf::IpAddress sendIP(serverIPAddress);
	serverIP = sendIP;

	std::string tempString = "new client";
	sf::Packet bufferPacket;
	bufferPacket << tempString;

	if(socket.send(bufferPacket, serverIP, serverPort) != sf::Socket::Done){
		std::cout << "Client error? Wrong IP?" << std::endl;
	}
	else{
		std::cout << "Client connecting--awaiting server start" << std::endl;
	}

}

/*! \brief  sendData function
*
*/
bool Client::sendData(sf::Packet packet){
    if(socket.send(packet, serverIP, serverPort) != sf::Socket::Done){
		return false;
	}
	else {
		return true;
	}
}

/*! \brief	getSocket function
*			returns the pointer to the socket for the Network object.
*
*/
sf::UdpSocket* Client::getSocket(){
	return &socket;
}







/*! \brief  getType function
*			returns the type of network.
*
*/
//std::string Client::getType(){
//        return "client";
//}


/*! \brief  GetIP function
*			returns the IpAddress for the Network object.
*
*/
//sf::IpAddress Client::getIP(){
//        return clientIP;
//}


/*! \brief  getPort function
*			returns the port for the Network object.
*
*/
//unsigned short Client::getPort(){
 //       return clientPort;
//}


/*! \brief	getServerIP function
*			returns the client's server IPaddress.
*
*/
//sf::IpAddress Client::getServerIP(){
//	return serverIP;
//}


/*! \brief  getServerPort function
*			returns the client's server port.
*
*/
//unsigned short Client::getServerPort(){
//        return serverPort;
//}




