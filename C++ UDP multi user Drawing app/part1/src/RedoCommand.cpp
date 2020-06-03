#include "RedoCommand.hpp"

/*! \brief  RedoCommand's execute function
*
*   Executes the RedoCommand on the given Canvas object.
*   It checks to see if the undoStack for the given Canvas is empty.
*   If it's not, then it get's the top element (the most recent command),
*   pushes it to the commandStack, removes it from the undoStack, and 
*   sets the pixel to the top element's color and X and Y values.
*   
*   It then creates and returns a new packet with DRAW as the command string and the
*   the rest of the parameters needed for another client to execute the RedoCommand.
*/
sf::Packet RedoCommand::execute(){
    if (!theCanvas->undoEmptyStatus()){
		sf::Packet ele = theCanvas->undoTop();
		theCanvas->commandPush(ele);
		theCanvas->undoPop();

		std::string eleBrushString;
        std::string eleBGString;
        std::string eleCommand;
        unsigned int eleX;
        unsigned int eleY;

        sf::Image *canvasImage = theCanvas->getImage();
        if(ele >> eleCommand >> eleX >> eleY >> eleBrushString >> eleBGString){
            std::string newBrushString = eleBrushString;
            sf::Color newBrushColor = theCanvas->getColor(eleBrushString);

            canvasImage->setPixel(eleX, eleY, newBrushColor);

            sf::Packet commandPacket;
            commandPacket << "DRAW" << eleX << eleY << newBrushString << newBrushString;
            return commandPacket;
        }
	}
    sf::Packet bufferPacket;
    return bufferPacket;
}

/*! \brief  RedoCommand's getDescription function
*
*   Returns the string description "REDO" for the Command object.
*/
std::string RedoCommand::getDescription(){
    return "REDO";
}
