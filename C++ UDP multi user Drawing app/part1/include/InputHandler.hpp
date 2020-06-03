#ifndef INPUT_HANDLER_HPP
#define INPUT_HANDLER_HPP

#include <string>
#include <iostream>
#include <SFML/Network.hpp>
#include "Command.hpp"
#include "DrawCommand.hpp"
#include "UndoCommand.hpp"
#include "RedoCommand.hpp"
#include "ClearCommand.hpp"
#include "SepiaCommand.hpp"
#include "DitherCommand.hpp"
#include "GreyscaleCommand.hpp"
#include "BufferCommand.hpp"

using namespace std;

class InputHandler{
    private:
        sf::Event *inputEvent;
        Canvas *inputCanvas;
        sf::RenderWindow *inputWindow;
        std::string inputMethod;
        sf::Packet inputPacket;
        std::string receivedCommand;
        unsigned int receivedX;
        unsigned int receivedY;
        std::string receivedBrush;
        std::string receivedBG;
        
    public:
        InputHandler(sf::Event *ievent, Canvas *icanvas, std::string imethod, sf::Packet ipacket);
        ~InputHandler();

        Command* handleButton();
        Command* handleMouse();
        Command* handleReceive();

};


#endif