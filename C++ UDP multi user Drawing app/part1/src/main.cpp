/** 
 *  @file   main.cpp 
 *  @brief  Entry point into the program.
 *  @author Mike and cache-me-if-you-can 
 *  @date   2020-08-04 
 ***********************************************/

#include <iostream>
#include <string>
#include <SFML/OpenGL.hpp>
#include <SFML/Window.hpp>
#include "Client.hpp"
#include "Server.hpp"
#include "Canvas.hpp"
#include "InputHandler.hpp"
#include "Command.hpp"
#include "GUIFrame.hpp"

#include "nuklear.h"
#include "nuklear_sfml_gl2.h"

#define GUI_INIT_WIDTH 500
#define GUI_INIT_HEIGHT 600
#define CANVAS_INIT_WIDTH 500
#define CANVAS_INIT_HEIGHT 500

using namespace std;

bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

std::string getRole(std::string role)
{
	bool ser_client_flag = false;
	do
	{
	// Stores a role of either a server or client user.
	std::cout << "Enter (s) for Server, Enter (c) for client: " << std::endl;
	std::cin >> role;
		if(role != "" && (role == "s" || role == "S" || role == "c" || role == "C")){	
					ser_client_flag = true;
		}else
		{
				std::cout<<"Invalid Input!! Try a valid input " <<std::endl;
		}	
	} while (ser_client_flag==false);

	return role;

}

NetworkManager* serverLaunch(NetworkManager *network, sf::IpAddress IPAddress)
{

		bool server_port_flag = false;
		unsigned short serverPort;
		std::string serverPort_str;
		do
		{
			std::cout << "Set server port number: ";
			std::cin >> serverPort_str;

			if(is_number(serverPort_str)){
						server_port_flag = true;
				}
			else{
				std::cout<<"Invalid Port!! Enter a valid port " <<std::endl;
			}
		} while (server_port_flag ==false);
		serverPort = std::stoi(serverPort_str);

		std::cout << "Confirming server port number as: " << serverPort << std::endl;
		network = new Server(IPAddress, serverPort);
		network->launch();
		return network;
}

NetworkManager* clientLaunch(NetworkManager *network, sf::IpAddress IPAddress)
{
		bool client_port_flag = false;
		std::string clientPort_str;
		unsigned short clientPort;
		do
		{
			std::cout << "Set client port number: ";
			std::cin >> clientPort_str;
			if(is_number(clientPort_str)){
					client_port_flag = true;
			}
			else{
				std::cout<<"Invalid Port!! Enter a valid port " <<std::endl;
			}
		} while (client_port_flag ==false);

		clientPort = std::stoi(clientPort_str);

        std::cout << "Confirming client port number as: " << clientPort << std::endl;
		network = new Client(IPAddress, clientPort);
		network->launch();

		return network;
}





int main(){
	sf::IpAddress IPAddress = sf::IpAddress::getPublicAddress();
	std::string role;
	role = getRole(role);
	NetworkManager *network = nullptr;

	if(role[0] == 's'){
		network = serverLaunch(network, IPAddress);
	}
	else if(role[0] == 'c'){
        network = clientLaunch(network, IPAddress);
		sf::UdpSocket *socket = network->getSocket();
		sf::IpAddress cIP;
    	unsigned short cPort;
		sf::Packet cBufferPacket;

		// initialize canvas
		Canvas *canvasApp = new Canvas();
		sf::RenderWindow *canvasWindow = canvasApp->getWindow();
		sf::Texture *canvasTexture = canvasApp->getTexture();
		sf::Sprite *canvasSprite = canvasApp->getSprite();
		sf::Image *canvasImage = canvasApp->getImage();

		// set up GUI
		GUIFrame *guiObj = new GUIFrame(canvasApp);
		struct nk_colorf bg;
		bg.r = 0.10f, bg.g = 0.18f, bg.b = 0.24f, bg.a = 1.0f;

		sf::Event *canvasEvent = new sf::Event();
		std::string method = "self";
		canvasApp->setRunning(true);
		
		while(canvasWindow->isOpen() && guiObj->getGUIWindow().isOpen()){
			canvasWindow->clear();
			// the network receives data
			if(socket->receive(cBufferPacket, cIP, cPort) == sf::Socket::Done){
				std::cout << "sent data" << std::endl;
				InputHandler receiveAction = InputHandler(canvasEvent, canvasApp, "server", cBufferPacket);
				Command *command = receiveAction.handleReceive();
				sf::Packet result = command->execute();
			}
			while(canvasWindow->pollEvent(*canvasEvent)){
				if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
					int xPosition = sf::Mouse::getPosition().x;
					int yPosition = sf::Mouse::getPosition().y;
					if(canvasWindow->getViewport(canvasWindow->getView()).contains(sf::Mouse::getPosition(*canvasWindow).x, sf::Mouse::getPosition(*canvasWindow).y)){
						canvasApp->setXCoordinate(sf::Mouse::getPosition(*canvasWindow).x);
						canvasApp->setYCoordinate(sf::Mouse::getPosition(*canvasWindow).y);
						if((canvasApp->getOldX() != canvasApp->getXCoord()) || (canvasApp->getOldY() != canvasApp->getYCoord())){
							InputHandler mouseAction = InputHandler(canvasEvent, canvasApp, method, cBufferPacket);
							Command *command = mouseAction.handleMouse();
							if(command->getDescription() != "BUFFER"){
								std::cout << command->getDescription() << std::endl;
								sf::Packet mouseResult = command->execute();
								network->sendData(mouseResult);
							}
						}
						if(canvasEvent->type == sf::Event::MouseMoved){
							canvasApp->setXCoordinate(sf::Mouse::getPosition(*canvasWindow).x);
							canvasApp->setYCoordinate(sf::Mouse::getPosition(*canvasWindow).y);
							if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
								if((canvasApp->getOldX() != canvasApp->getXCoord()) 
								|| (canvasApp->getOldY() != canvasApp->getYCoord())){
									InputHandler mouseAction = InputHandler(canvasEvent, canvasApp, method, cBufferPacket);
									Command *command = mouseAction.handleMouse();
									if(command->getDescription() != "BUFFER"){
										sf::Packet mouseResult = command->execute();
										network->sendData(mouseResult);
									}
								}
							}
						}
					}
				}
				else if(canvasEvent->type == sf::Event::KeyReleased){
					if(canvasEvent->key.code == sf::Keyboard::Escape){
							canvasApp->setRunning(false);
					}
					InputHandler buttonAction =  InputHandler(canvasEvent, canvasApp, method, cBufferPacket);
					Command *command = buttonAction.handleButton();
					if(command->getDescription() != "BUFFER"){
						sf::Packet mouseResult = command->execute();
						network->sendData(mouseResult);
					}
				}
			}
			canvasTexture->loadFromImage(*canvasImage);
			canvasWindow->draw(*canvasSprite);
			canvasWindow->display();

			//--------GUI Event Listener -------------- //

			guiObj->guiEventHandler(canvasEvent);
			guiObj->postEvent(network, bg,  method, cBufferPacket, canvasEvent);
			
		}

		// Destroy our app
		canvasApp->closeApp();
		guiObj->closeGUI();

	}
	delete network;

	return 0;
}



