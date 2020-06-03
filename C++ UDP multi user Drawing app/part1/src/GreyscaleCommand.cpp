#include "GreyscaleCommand.hpp"

/*! \brief  GreyscaleCommand's execute function
*
*   Executes the GreyscaleCommand on the given Canvas object.
*   It gets the RGB values for a pixel and multiplies the 
*   R by 0.2126, the G by 0.7152, and the B by 0.0722 and adds the
*   resulting numbers together to get the newRGB value. 
*   Then it sets the pixels RGB values to the newRGB value to create the greyscale.
*   
*   It then creates and returns a new packet with GREYSCALE as the command string and the
*   the rest of the parameters needed for another client to execute the GreyscaleCommand.
*
*   Like the ClearCommand, the GreyscaleCommand cannot be undo as it resets the entire frame.
*/
sf::Packet GreyscaleCommand::execute(){
    sf::Packet greyPacket;
    unsigned int tempNum = 0;
    greyPacket << "GREYSCALE" << tempNum << tempNum << theCanvas->getBrushString() << theCanvas->getBGString();

    int px, py;
    for(py=0; py < theCanvas->getWindowHeight(); py++){
        for(px=0; px < theCanvas->getWindowWidth(); px++){
            sf::Color pColor = theCanvas->getImage()->getPixel(px, py);
            int pR = pColor.r;
            int pG = pColor.g;
            int pB = pColor.b;
            int newRGB = ((0.2126 * pR) + (0.7152 * pG) + (0.0722 * pB));
            sf::Color newColor = sf::Color(newRGB, newRGB, newRGB);
            theCanvas->getImage()->setPixel(px, py, newColor);
        }
    }

    theCanvas->clearStacks();

    return greyPacket;
}

/*! \brief  GreyscaleCommand's getDescription function
*
*   Returns the string description "GREYSCALE" for the Command object.
*/
std::string GreyscaleCommand::getDescription(){
    return "GREYSCALE";
}
