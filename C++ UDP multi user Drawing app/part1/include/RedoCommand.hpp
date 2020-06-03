#ifndef REDO_COMMAND_HPP
#define REDO_COMMAND_HPP

#include "Command.hpp"

class RedoCommand : public Command
{
    private:
        Canvas *theCanvas;

    public:
        RedoCommand(Canvas *canvasObj) : Command("REDO"), theCanvas(canvasObj) {}
        
        sf::Packet execute();
        std::string getDescription();
};

#endif
