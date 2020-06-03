#ifndef GREYSCALE_COMMAND_HPP
#define GREYSCALE_COMMAND_HPP

#include "Command.hpp"

class GreyscaleCommand : public Command
{
    private:
        Canvas *theCanvas;

    public:
        GreyscaleCommand(Canvas *canvasObj) : Command("GREYSCALE"), theCanvas(canvasObj) {}
        
        sf::Packet execute();
        std::string getDescription();
};

#endif