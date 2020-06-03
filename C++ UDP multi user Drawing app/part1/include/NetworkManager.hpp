#ifndef NETWORK_MGMT_HPP
#define NETWORK_MGMT_HPP

#include <string>
#include <iostream>
#include <SFML/Network.hpp>
#include <SFML/System/Time.hpp>

using namespace std;

class NetworkManager
{
public:
	NetworkManager() {};
	virtual ~NetworkManager() {};
	
	virtual void launch(unsigned short sPort=0) = 0;
	virtual bool sendData(sf::Packet packet) = 0;
	virtual sf::UdpSocket* getSocket() = 0;
	
};

#endif
