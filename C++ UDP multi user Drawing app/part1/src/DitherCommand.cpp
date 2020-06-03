#include "DitherCommand.hpp"

/*! \brief  DitherCommand's execute function
*
*   Executes the DitherCommand on the given Canvas object.
*   It sets the new RGB values for a pixel to it's current value minus
*   the value from the ditherHelper
*   
*   It then creates and returns a new packet with DITHER as the command string and the
*   the rest of the parameters needed for another client to execute the DitherCommand.
*   
*   Like the ClearCommand, the DitherCommand cannot be undo as it resets the entire frame.
*/
sf::Packet DitherCommand::execute(){
    sf::Packet ditherPacket;
    unsigned int tempNum = 0;
    ditherPacket << "DITHER" << tempNum << tempNum << theCanvas->getBrushString() << theCanvas->getBGString();

    int px, py;
    for(py=0; py < theCanvas->getWindowHeight(); py++){
        for(px=0; px < theCanvas->getWindowWidth(); px++){
            sf::Color pColor = theCanvas->getImage()->getPixel(px, py);
            int pR = pColor.r;
            int pG = pColor.g;
            int pB = pColor.b;
            int tR = ditherHelper(pR);
            int tG = ditherHelper(pG);
            int tB = ditherHelper(pB);
            int newRed = pR - tR;
            int newGreen = pG - tG;
            int newBlue = pB - tB;
            sf::Color newColor = sf::Color(newRed, newGreen, newBlue);
            theCanvas->getImage()->setPixel(px, py, newColor);
        }
    }
    theCanvas->clearStacks();
    return ditherPacket;
}

/*! \brief  DitherCommand's ditherHelper function
*
*   It is a small, helper function for the execute function.
*   It checks to see if a number is less than 255 minus itself.
*   If it is, it returns 0. If it's not, it returns 255.
*/
int DitherCommand::ditherHelper(int x){
    if(x < 255 - x){
        return 0;
    }
    return 255;
}

/*! \brief  DitherCommand's getDescription function
*
*   Returns the string description "DITHER" for the Command object.
*/
std::string DitherCommand::getDescription(){
    return "DITHER";
}
