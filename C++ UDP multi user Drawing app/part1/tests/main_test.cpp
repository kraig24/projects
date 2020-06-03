/**
 *  @file   main_test.cpp 
 *  @brief  Unit Tests for our program
 *  @author Mike and cache-me-if-you-can 
 *  @date   yyyy-dd-mm 
 ***********************************************/ 

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

// Include our Third-Party SFML header
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
// Include standard library C++ libraries.
#include <iostream>
#include <string>
// Project header files
// Include our Third-Party SFML header
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Network/UdpSocket.hpp>
#include <SFML/Network/IpAddress.hpp>
#include <SFML/Network.hpp>             
// Include standard library C++ libraries.
#include <iostream>
#include <string>
// Project header files
#include "Client.hpp"
#include "Server.hpp"
#include "Canvas.hpp"
#include "InputHandler.hpp"
#include "Command.hpp"
#include "GUIFrame.hpp"

// Testing Header
#include "NetworkTestManager.hpp"

//#include <SFML/OpenGL.hpp>
#include <SFML/Window.hpp>
#include <Constants.hpp>

using namespace std;


#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 400


//void initialization(App *appObj){
//    std::cout << "Starting the App" << std::endl;
//}
//
///*! \brief     Create and destroy App object, checking
//*                   the window dimensions and x, y coordinates.
// */
//TEST_CASE("Create and Destroy App Window"){
//    App* test_app = new App();
//    test_app->mouseX = 14;
//    test_app->mouseY = 233;
//    test_app->pmouseX = 63;
//    test_app->pmouseY = 84;
//
//    REQUIRE( test_app->mouseX == 14 );
//    REQUIRE( test_app->mouseY == 233 );
//    REQUIRE( test_app->pmouseX == 63 );
//    REQUIRE( test_app->pmouseY == 84 );
//    printf("Destroying App \n");
//    test_app->Destroy();
//}
//
//
///*! \brief     Create and delete Server object.
//*/
//TEST_CASE("Create/destroy a server object"){
//    sf::IpAddress testServerAddress = sf::IpAddress::getLocalAddress();
//    unsigned short testServerPort = 2002;
//    sf::UdpSocket testServerSocket;
//    sf::UdpSocket *testSSocketPointer;
//    testSSocketPointer = &testServerSocket;
//    sf::SocketSelector testServerSelector;
//    testServerSelector.add(testServerSocket);
//
//    // Create Server
//    Server testServer(testServerAddress, testServerPort);
//
//    //~testServer();
//}
//
//
// /*! \brief     Create and delete Client object.
// */
// TEST_CASE("Create/destroy a client object"){
//     sf::IpAddress testClientAddress = sf::IpAddress::getLocalAddress();
//     unsigned short testClientPort = 2001;
//     sf::UdpSocket testClientSocket;
//     sf::UdpSocket *testCSocketPointer;
//     testCSocketPointer = &testClientSocket;
//     sf::SocketSelector testClientSelector;
//     testClientSelector.add(testClientSocket);
//
//     // Crearte Client
//     Client testClient(testClientAddress, testClientPort);
//     //~testClient();
// }
//
///*! \brief     Check pixel color values in different parts of the drawing canvas.
//*
//*/
//TEST_CASE(" Checking Pixel color values "){
//    App *appObj = new App();
//    appObj->Init(&initialization);
//
//    appObj->mouseX  = 214;
//    appObj->mouseY  = 228;
//
//    sf::Color white  = sf::Color::White;
//    sf::Color blue   = sf::Color::Blue;
//
//    appObj->GetImage().setPixel(appObj->mouseX ,appObj->mouseY,sf::Color::Blue);
//
//    REQUIRE( appObj->GetImage().getPixel(0, 0) == white );
//    REQUIRE( appObj->GetImage().getPixel(appObj->mouseX ,appObj->mouseY) == blue );
//    REQUIRE( appObj->GetImage().getPixel(appObj->mouseX ,appObj->mouseY) != white );
//
//    appObj->Destroy();
//
//}
//
///*! \brief     Check pixel color values in after executing, undoing, and redoing.
//*
//*/
//TEST_CASE(" Undo and redo a pixel"){
//    sf::IpAddress testServerAddress = sf::IpAddress::getLocalAddress();
//    unsigned short testServerPort = 2003;
//    App *appObj = new App();
//    appObj->Init(&initialization);
//    sf::Vector2i coordinate;
//    sf::Color blue = BLUE;
//    sf::Color red = RED;
//    NetworkManager *network = new Server(testServerAddress, testServerPort);
//
//    appObj->mouseX  = 214;
//    appObj->mouseY  = 228;
//    coordinate.x = 214;
//    coordinate.y = 218;
//    Image* imageObj = appObj;
//    Command* drawObj = new Draw(*imageObj, coordinate, blue, red, network);
//
//
//    // TODO: Get undo and redo test on network to work
//    /*
//    appObj->AddCommand(drawObj);
//    REQUIRE( appObj->GetImage().getPixel(appObj->mouseX, appObj->mouseY) == sf::Color::Blue );
//    appObj->Undo();
//    REQUIRE( appObj->GetImage().getPixel(appObj->mouseX, appObj->mouseY) == sf::Color::White );
//    appObj->Redo();
//    REQUIRE( appObj->GetImage().getPixel(appObj->mouseX, appObj->mouseY) == sf::Color::Blue );
//
//    appObj->Destroy();
//    */
//
//}
//
///*! \brief     Set up network, have three clients join, test
// *          that they have successfully joined, and finally
// *          have them leave.
//*
//*/
TEST_CASE(" Setting up a network"){
    sf::IpAddress IPAddress = sf::IpAddress::getLocalAddress();

    sf::ContextSettings settings(24, 8, 4, 2, 2);

    sf::UdpSocket socket;
    sf::UdpSocket *socketPointer;
    socketPointer = &socket;

    sf::SocketSelector selector;
        selector.add(socket);

    sf::Packet bufferPacket;
    sf::IpAddress connectingIP;
    unsigned short connectingPort;
    std::string initString;

    // The server port
    unsigned short serverPort = 2005;
    unsigned short clientPort1 = 2006;
    unsigned short clientPort2 = 2007;
    unsigned short clientPort3 = 2008;

    /*
    // Set up server and clients
    Server udpServer(IPAddress, serverPort, socketPointer, selector);
    udpServer.Launch();
    NetworkManager networkObj = udpServer;

    Client udpClient1(IPAddress, clientPort1, socketPointer, selector, serverPort);
    udpClient1.Launch();
    NetworkManager networkObj1 = udpClient1;
    if(socket.receive(bufferPacket, connectingIP, connectingPort) == sf::Socket::Done) {
        bufferPacket >> initString;
    }
    REQUIRE(initString == "new client");

    Client udpClient2(IPAddress, clientPort2, socketPointer, selector, serverPort);
    udpClient2.Launch();
    NetworkManager networkObj2 = udpClient2;
    if(socket.receive(bufferPacket, connectingIP, connectingPort) == sf::Socket::Done) {
        bufferPacket >> initString;
    }
    REQUIRE(initString == "new client");

    Client udpClient3(IPAddress, clientPort3, socketPointer, selector, serverPort);
    udpClient3.Launch();
    NetworkManager networkObj3 = udpClient3;
    if(socket.receive(bufferPacket, connectingIP, connectingPort) == sf::Socket::Done) {
        bufferPacket >> initString;
    }
    REQUIRE(initString == "new client");

    // TODO: SYSTEM CALL that ALLOWS CLIENTS TO LEAVE.
     // This could be potentially exit(1), escape,
     // ctrl-c, etc.

     delete network;
    */


}
//
///*! \brief     Test network getters for client.
// */
//TEST_CASE("Server getters"){
//    // TODO: Create server. Check member variables.
//    // Getters provided below.
//    /*
//    virtual sf::UdpSocket* GetSocket() = 0;
//    virtual sf::IpAddress GetIP() = 0;
//    virtual unsigned short GetPort() = 0;
//    virtual sf::SocketSelector GetSelector() = 0;
//    virtual string GetType() = 0;
//    virtual sf::IpAddress GetServerIP() = 0;
//    virtual unsigned short GetServerPort() = 0;
//    */
//}
//
///*! \brief     Test network getters for server.
// */
//TEST_CASE("Client getters"){
//    // TODO: Create client. Check member variables.
//    // Getters provided below.
//    /*
//    virtual sf::UdpSocket* GetSocket() = 0;
//    virtual sf::IpAddress GetIP() = 0;
//    virtual unsigned short GetPort() = 0;
//    virtual sf::SocketSelector GetSelector() = 0;
//    virtual string GetType() = 0;
//    virtual sf::IpAddress GetServerIP() = 0;
//    virtual unsigned short GetServerPort() = 0;
//    */
//}

/*! \brief     This test uses our NetworkTestManager to
 *  launch a server with 3 clients and send a packet of data over
 *  the server (see NetworkTestManager.cpp for more details). For
 *  each client, if data is successfully received from the server, 1
 *  is returned, hence a successValue set to 3.
 */
TEST_CASE("Test SendData"){
    NetworkTestManager *networkTest1 = new NetworkTestManager();
    int test1, test2, test3, test4, successValue;
    successValue = 3;
    test1 = networkTest1->runTest("test1");
    REQUIRE( test1 == successValue );
    // TODO: Use system call to create a client and server.
    // TODO: More test cases should be produced for this.
    // Need to input a number for both client and server port.
    // Create a packet and send it. * Suggested to create a
    // TestPacketHeader.h *
    // TODO: Make sure to exit out of servers to stop processes
}

/*! \brief     Launch server with client, test that client can
*                   receive data from the server.
 */
TEST_CASE("Test Server ReceiveData"){
    // TODO: Use system call to create a client and server.
    // send packet from server to client
    // TODO: Make sure to exit out of servers to stop processes
}

/*! \brief     Launch server with client, test that server can
*                   receive data from the client.
 */
TEST_CASE("Test Client ReceiveData"){
    // TODO: Use system call to create a client and server.
    // send packet from client to server
    // TODO: Make sure to exit out of servers to stop processes
}

/*! \brief     Launch server with client, test that server can
*                   receive data from the client.
 */
TEST_CASE("Test ExecutePackage"){
    // TODO: Use system call to create a client and server.
    // TODO: More test cases should be produced for this.
    // Send pixel changes from client to server.
    // Test this with multiple clients
    // TODO: Make sure to exit out of servers to stop processes
}


