#include "DrawCommand.hpp"

/*! \brief  DrawCommand's execute function
*
*   Executes the DrawCommand on the given Canvas object.
*   It gets the Canvas's Image and sets the pixel at the given X and Y value to
*   the given brush color.
*   
*   If the client is drawing, it will add the command to the Canva's command stack.
*   If the client just received this command from the server, it will only execute it,
*   since a clinet can only undo/redo commands they did themselves.
*   
*   It then creates and returns a new packet with DRAW as the command string and the
*   the rest of the parameters needed for another client to execute the DrawCommand.
*/
sf::Packet DrawCommand::execute(){
    
    sf::Image *canvasImage = theCanvas->getImage();
    canvasImage->setPixel(receivedX, receivedY, theCanvas->getColor(receivedBrush));

    sf::Packet commandPacket;
    commandPacket << "DRAW" << receivedX << receivedY << receivedBrush << receivedBG;

    if(inputMethod == "self"){
        theCanvas->commandPush(commandPacket);
        while(!theCanvas->undoEmptyStatus()){
            theCanvas->undoPop();
        }
    }
    return commandPacket;
    
}

/*! \brief  DrawCommand's getDescription function
*
*   Returns the string description "DRAW" for the Command object.
*/
std::string DrawCommand::getDescription(){
    return "DRAW";
}
