#ifndef SEPIA_COMMAND_HPP
#define SEPIA_COMMAND_HPP

#include "Command.hpp"

class SepiaCommand : public Command
{
    private:
        Canvas *theCanvas;

    public:
        SepiaCommand(Canvas *canvasObj) : Command("SEPIA"), theCanvas(canvasObj) {}
        
        sf::Packet execute();
        int sepiaHelper(int x);
        std::string getDescription();
};

#endif
