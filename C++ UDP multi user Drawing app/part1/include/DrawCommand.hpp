#ifndef DRAW_COMMAND_HPP
#define DRAW_COMMAND_HPP

#include "Command.hpp"

class DrawCommand : public Command
{
    private:
        Canvas *theCanvas;
        std::string inputMethod;

        std::string receivedBrush;
        std::string receivedBG;
        unsigned int receivedX;
        unsigned int receivedY;

    public:
        DrawCommand(Canvas *canvasObj, std::string iMethod, std::string rBrush, std::string rBG, unsigned int rX, unsigned int rY) 
                    : Command("DRAW"), theCanvas(canvasObj), inputMethod(iMethod) , receivedBrush(rBrush), receivedBG(rBG), receivedX(rX), receivedY(rY) {}
        
        sf::Packet execute();
        std::string getDescription();
};

#endif
