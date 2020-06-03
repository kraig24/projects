#include "BufferCommand.hpp"

/*! \brief  BufferCommand Constructor
*
*   Executes the BufferCommand object.
*   The BufferCommand is used as a buffer for commands that do not 
*   need to be immediately executed or sent.
*   For example, if a user clicks on the number 7 key to change their
*   brush color to Magenta, the command does not need to be sent to change
*   another user's brush color, so a BufferCommand is created to track which
*   commands actually need to be sent.
*/
sf::Packet BufferCommand::execute(){
    sf::Packet bufferPacket;
    return bufferPacket;
}

/*! \brief  ClearCommand's getDescription function
*
*   Returns the string description "BUFFER" for the Command object.
*/
std::string BufferCommand::getDescription(){
    return "BUFFER";
}
