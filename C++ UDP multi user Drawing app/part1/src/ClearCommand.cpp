#include "ClearCommand.hpp"

/*! \brief  ClearCommand's execute function
*
*   It determines if the network executing was given the command from
*   the server or it's own Canvas.
*   If the command came from it's self, it gets the current brush color
*   from the Canvas, and has the Image associated with the Canvas "create"
*   a new Image filled wih the current brush color.
*   If the command
*   
*   It then creates a new packet with CLEAR as the command string and the
*   the rest of the parameters needed for another client to execute the ClearCommand.
*   
*   A user cannot undo an executed ClearCommand from themselfs or another user.
*   The ClearCommand clears the stacks holding the previous DrawCommands done.
*/
sf::Packet ClearCommand::execute(){

    if(inputMethod == "self"){
        sf::Color clearColor = theCanvas->getBrushColor();
        std::string clearString = theCanvas->getBrushString();
        theCanvas->getImage()->create(600, 400, clearColor);
        theCanvas->setBGColor(clearString);
        unsigned int tempX = 0;
        unsigned int tempY = 0;
        sf::Packet commandPacket;
        commandPacket << "CLEAR" << tempX << tempY << clearString << clearString;

        theCanvas->clearStacks();

        return commandPacket;
    }
    else {
        std::cout << receivedBrush << std::endl;
        theCanvas->setBGColor(receivedBrush);
        theCanvas->getImage()->create(600, 400, theCanvas->getBGColor());
        
        unsigned int tempNum = 0;
        sf::Packet commandPacket;
        commandPacket << "CLEAR" << tempNum << tempNum << theCanvas->getBrushString() << theCanvas->getBrushString();
        
        theCanvas->clearStacks();

        return commandPacket;
    }
}

/*! \brief  ClearCommand's getDescription function
*
*   Returns the string description "CLEAR" for the Command object.
*/
std::string ClearCommand::getDescription(){
    return "CLEAR";
}