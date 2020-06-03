#ifndef CLEAR_COMMAND_HPP
#define CLEAR_COMMAND_HPP

#include "Command.hpp"

class ClearCommand : public Command
{
    private:
        Canvas *theCanvas;
        std::string receivedBrush;
        std::string inputMethod;

    public:
        ClearCommand(Canvas *canvasObj, std::string iMethod, std::string rString) 
                    : Command("CLEAR"), theCanvas(canvasObj), receivedBrush(rString), inputMethod(iMethod){}
        
        sf::Packet execute();
        std::string getDescription();
};

#endif