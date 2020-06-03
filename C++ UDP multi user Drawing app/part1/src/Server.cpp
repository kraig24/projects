#include "Server.hpp"

/*! \brief  Server Constructor
*
*/
Server::Server(sf::IpAddress address, unsigned short sPort){
	serverIP = address;
	serverPort = sPort;
	socket.bind(serverPort);
	socket.setBlocking(false);
}

/*! \brief  Server Destructor
*
*/
Server::~Server(){
	//
}

/*! \brief  launch function
*
*/
void Server::launch(unsigned short sPort){
	std::cout << "============Starting UDP Server==========" << std::endl;
	sf::IpAddress tempIP;
    unsigned short tempPort;
	sf::Packet bufferPacket;
	std::string tempString;

	while(true){
		// the network receives data
		if(socket.receive(bufferPacket, tempIP, tempPort) == sf::Socket::Done){
			if(this->validPacket(bufferPacket)){
                // for test case
                if (sPort != 0) {
                    this->sendData(bufferPacket);
                    exit(1);
                } else if(this->sendToClients(bufferPacket, tempPort, tempIP)){
					//std::cout << "server received + sent command" << std::endl;
				}
			}
			else if (bufferPacket >> tempString){
				if(tempString == "new client"){
					this->addClient(tempPort, tempIP);
					this->sendState(tempPort, tempIP);
				}
			}
			else if (bufferPacket >> tempString){
				if(tempString == "leaving"){
					this->removeClient(tempPort, tempIP);
				}
			}
			else{
				this->addClient(tempPort, tempIP);
				this->sendState(tempPort, tempIP);
			}
		}
	}
}


/*! \brief  sendData function
*
*/
bool Server::sendData(sf::Packet packet){
	for(std::map<unsigned short, sf::IpAddress>::const_iterator it = connections.begin(); it != connections.end(); ++it){
		if(socket.send(packet, it->second, it->first) != sf::Socket::Done){
			return false;
		}
	}
	return true;
}

/*! \brief  sendData function
*
*/
bool Server::sendToClients(sf::Packet packet, unsigned int tPort, sf::IpAddress tIP){
	std::string tempCommand;
	unsigned int tempX;
	unsigned int tempY;
	std::string tempBrush;
	std::string tempBG;
	if(packet >> tempCommand >> tempX >> tempY >> tempBrush >> tempBG){
		if(tempCommand == "CLEAR"){
			serverCommands.clear();
			packet << tempCommand << tempX << tempY << tempBrush << tempBG;
		}
	}

	for(std::map<unsigned short, sf::IpAddress>::const_iterator it = connections.begin(); it != connections.end(); ++it){
		if(tPort == it->first && tIP == it->second){
			continue;
		}
		else{
			if(socket.send(packet, it->second, it->first) != sf::Socket::Done){
				return false;
			}
		}
	}
	return true;
}




/*! \brief  SendState function
*
*/
bool Server::sendState(unsigned short senderPort, sf::IpAddress senderIP){
	std::vector<sf::Packet>::iterator it;
	for(it = serverCommands.begin(); it != serverCommands.end(); ++it){
		if(socket.send(*it, senderIP, senderPort) != sf::Socket::Done){
			return false;
		}
	}
	return true;

}

/*! \brief	getSocket function
*			returns the pointer to the socket for the Network object.
*
*/
sf::UdpSocket* Server::getSocket(){
	return &socket;
}

/*! \brief  AddClient function
*			
*	Adds a new client to the map, connections, which stores
*	a cient's IP address and prort number.
*/
bool Server::validPacket(sf::Packet tempPacket){
	std::string tempCommand;
	unsigned int tempX;
	unsigned int tempY;
	std::string tempBrush;
	std::string tempBG;
	if(tempPacket >> tempCommand >> tempX >> tempY >> tempBrush >> tempBG){
		sf::Packet updatedPacket;
		updatedPacket << tempCommand << tempX << tempY << tempBrush << tempBG;
		serverCommands.push_back(updatedPacket);
		return true;
	}
	return false;
}

/*! \brief  AddClient function
*			
*	Adds a new client to the map, connections, which stores
*	a cient's IP address and prort number.
*/
void Server::addClient(unsigned short port, sf::IpAddress address)
{
	std::cout << "Client joining:" << address << " : " << port << std::endl;
	connections[port] = address;
	
}

/*! \brief  removeClient function
*			adds a new client to the map of cconnections
*
*/
void Server::removeClient(unsigned short port, sf::IpAddress address)
{
	std::cout << "Client leaving:" << address << " : " << port << std::endl;
	connections.erase(port);
}







/*! \brief  AddCommand function
*
*/
//void Server::addCommand(sf::Packet packet){
//	serverCommands.push_back(packet);
//}



/*! \brief  getType function
*			returns the type of network.
*
*/
//std::string Server::getType(){
  //      return "server";
//}


/*! \brief  getIP function
*			returns the IpAddress for the Network object.
*
*/
//sf::IpAddress Server::getIP(){
//        return serverIP;
//}

/*! \brief  getPort function
*			returns the port for the Network object.
*
*/
//unsigned short Server::getPort(){
//        return serverPort;
//}


/*! \brief	getServerIP function
*			returns the client's server IPaddress.
*
*/
//sf::IpAddress Server::getServerIP(){
//	return serverIP;
//}


/*! \brief  getServerPort function
*			returns the client's server port.
*
*/
//unsigned short Server::getServerPort(){
//        return serverPort;
//}



