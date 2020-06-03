/**
 *  @file   mockMain.cpp
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
        if(role != "" && (role == "s" || role == "S" || role == "c" || role == "C")){
                    ser_client_flag = true;
        }else
        {
                std::cout<<"Invalid Input!! Try a valid input " <<std::endl;
        }
    } while (ser_client_flag==false);

    return role;

}

NetworkManager* serverLaunch(NetworkManager *network, sf::IpAddress IPAddress, unsigned short serverPort)
{
        std::cout << "Confirming server port number as: " << serverPort << std::endl;
        network = new Server(IPAddress, serverPort);
        network->launch(2000);
        return network;
}

NetworkManager* clientLaunch(NetworkManager *network, sf::IpAddress IPAddress, unsigned short clientPort, unsigned short serverPort)
{
        std::cout << "Confirming client port number as: " << clientPort << std::endl;
        network = new Client(IPAddress, clientPort);
        network->launch(serverPort);
        return network;
}





int main(int argc, char *argv[]){
    sf::IpAddress IPAddress = sf::IpAddress::getPublicAddress();
    std::string role;
    // Input 's' or 'c'
    std::string inputRole = argv[0];
    role = getRole(inputRole);
    NetworkManager *network = nullptr;

    if(role[0] == 's'){
        unsigned short serverPort = stoi(argv[1]);
        network = serverLaunch(network, IPAddress, serverPort);
    }
    else if(role[0] == 'c'){
        unsigned short clientPort = stoi(argv[1]);
        unsigned short serverPort = stoi(argv[2]);
        network = clientLaunch(network, IPAddress, clientPort, serverPort);
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
        
        std::string inputTest = argv[3];

        if(inputTest == "test1"){
            std::cout << "**Starting Test 1**" << std::endl;
            Command* command = new DrawCommand(canvasApp, method, "BLACK", "WHITE", 100, 100);
            if(command->getDescription() != "BUFFER"){
                std::cout << command->getDescription() << std::endl;
                sf::Packet mouseResult = command->execute();
                network->sendData(mouseResult);
            }
        } else if(inputTest == "test2"){
            std::cout << "**Starting Test 1**" << std::endl;
            Command* command = new DrawCommand(canvasApp, method, "BLACK", "WHITE", 100, 100);
            if(command->getDescription() != "BUFFER"){
                std::cout << command->getDescription() << std::endl;
                sf::Packet mouseResult = command->execute();
                network->sendData(mouseResult);
            }
        }
        while(canvasWindow->isOpen() && guiObj->getGUIWindow().isOpen()){
            canvasWindow->clear();
            // the network receives data
            if(socket->receive(cBufferPacket, cIP, cPort) == sf::Socket::Done){
                std::cout << "sent data" << std::endl;
                InputHandler receiveAction = InputHandler(canvasEvent, canvasApp, "server", cBufferPacket);
                Command *command = receiveAction.handleReceive();
                //sf::Packet result = command->execute();
                // Destroy our app
                canvasApp->closeApp();
                guiObj->closeGUI();
                return 1;
            }
        }
    }
    return 0;
}
