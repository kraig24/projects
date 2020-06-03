#ifndef DITHER_COMMAND_HPP
#define DITHER_COMMAND_HPP

#include "Command.hpp"

class DitherCommand : public Command
{
    private:
        Canvas *theCanvas;

    public:
        DitherCommand(Canvas *canvasObj) : Command("DITHER"), theCanvas(canvasObj) {}
        
        sf::Packet execute();
        int ditherHelper(int x);
        std::string getDescription();
};

#endif