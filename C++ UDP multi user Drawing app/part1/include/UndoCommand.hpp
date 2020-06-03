#ifndef UNDO_COMMAND_HPP
#define UNDO_COMMAND_HPP

#include "Command.hpp"

class UndoCommand : public Command
{
    private:
        Canvas *theCanvas;

    public:
        UndoCommand(Canvas *canvasObj) : Command("UNDO"), theCanvas(canvasObj) {}
        
        sf::Packet execute();
        std::string getDescription();
        
};

#endif