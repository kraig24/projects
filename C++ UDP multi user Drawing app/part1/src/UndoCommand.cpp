#include "UndoCommand.hpp"

/*! \brief  UndoCommand's execute function
*
*   Executes the UndoCommand on the given Canvas object.
*   It checks to see if the commandStack is empty. If it's not,
*   the top element from the commandStack is stored as the packet to be undone.
*   It is pushed to the undoStack and removed from the commandStack.
*   Then the Canvas' Image sets the pixel at the packet's X and Y value to the
*   color provided in the packet.
*   
*   It then creates and returns a new packet with DRAW as the command string and the
*   the rest of the parameters needed for another client to execute the UndoCommand.
*/
sf::Packet UndoCommand::execute(){
    if (!theCanvas->commandEmptyStatus()){
		sf::Packet ele = theCanvas->commandTop();
		theCanvas->undoPush(ele);
		theCanvas->commandPop();

        std::string eleBrushString;
        std::string eleBGString;
        std::string eleCommand;
        unsigned int eleX;
        unsigned int eleY;

        if(ele >> eleCommand >> eleX >> eleY >> eleBrushString >> eleBGString){
            theCanvas->getImage()->setPixel(eleX, eleY, theCanvas->getBrushColor());
            sf::Packet commandPacket;
            commandPacket << "DRAW" << eleX << eleY << theCanvas->getBrushString() << theCanvas->getBrushString();
            return commandPacket;
        }

	}
    sf::Packet bufferPacket;
    return bufferPacket;
}

/*! \brief  UndoCommand's getDescription function
*
*   Returns the string description "UNDO" for the Command object.
*/
std::string UndoCommand::getDescription(){
    return "UNDO";
}
