#ifndef SERVER_HPP
#define SERVER_HPP

#include <SFML/Graphics/Color.hpp>
#include "NetworkManager.hpp"
#include <vector>
using namespace std;


class Server : public NetworkManager 
{
private:
	sf::IpAddress clientIP;
	unsigned short clientPort;
	sf::IpAddress serverIP;
	unsigned short serverPort;
	sf::UdpSocket socket;
	std::map<unsigned short, sf::IpAddress> connections;
	vector<sf::Packet> serverCommands;
	
public:
	Server(sf::IpAddress IP, unsigned short port);
	~Server();
	
	void launch(unsigned short sPort);
	sf::UdpSocket* getSocket();
	bool sendData(sf::Packet packet);
	bool validPacket(sf::Packet tempPacket);
	bool sendState(unsigned short port, sf::IpAddress address);
	void addClient(unsigned short port, sf::IpAddress address);
	void removeClient(unsigned short port, sf::IpAddress address);
	bool sendToClients(sf::Packet packet, unsigned int tPort, sf::IpAddress tIP);
	
	

	//std::string getType();
	//sf::IpAddress getIP();
	//unsigned short getPort();
	//sf::IpAddress getServerIP();
	//unsigned short getServerPort();
	//void addCommand(sf::Packet packet);
	
	
};

#endif
