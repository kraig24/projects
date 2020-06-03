#ifndef BUFFER_COMMAND_HPP
#define BUFFER_COMMAND_HPP

#include "Command.hpp"

class BufferCommand : public Command
{
    private:
        Canvas *theCanvas;

    public:
        BufferCommand(Canvas *canvasObj) : Command("BUFFER"), theCanvas(canvasObj) {}
        
        sf::Packet execute();
        std::string getDescription();
};

#endif