#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <SFML/Graphics/Color.hpp>
#include "NetworkManager.hpp"

using namespace std;


class Client : public NetworkManager
{
private:
	sf::IpAddress clientIP;
	unsigned short clientPort;
	sf::IpAddress serverIP;
	unsigned short serverPort;
	sf::UdpSocket socket;
	std::map<unsigned short, sf::IpAddress> connections;
	
public:
	Client(sf::IpAddress IP, unsigned short port);
	~Client();
	
	void launch(unsigned short sPort);
	bool sendData(sf::Packet packet);
	sf::UdpSocket* getSocket();
	bool is_number(const std::string& s);

	//std::string getType();
	//sf::IpAddress getIP();
	//unsigned short getPort();
	//sf::IpAddress getServerIP();
	//unsigned short getServerPort();
	
	
};

#endif
