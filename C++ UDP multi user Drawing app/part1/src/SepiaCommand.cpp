#include "SepiaCommand.hpp"

/*! \brief  SepiaCommand's execute function
*
*   Executes the SepiaCommand on the given Canvas object.
*   It finds the ne RGB values for each pixel and applys it to the Canvas' Image.
*
*   It finds the new R value by multiplying the old R to 0.393, multiplying the old G by 0.769,
*   multiplying the old B by 0.189, and add the resulting numbers together.
*   It finds the new G value by multiplying the old R to 0.349, multiplying the old G by 0.686,
*   multiplying the old B by 0.168, and add the resulting numbers together.
*   It finds the new B value by multiplying the old R to 0.272, multiplying the old G by 0.534,
*   multiplying the old B by 0.131, and add the resulting numbers together.
*
*   If any of the new numbers are greater than 255, that value is set to 255. 
*   Otherwise, it is the new number.
*   
*   It then creates and returns a new packet with SEPIA as the command string and the
*   the rest of the parameters needed for another client to execute the SepiaCommand.
*
*   Like the ClearCommand, the SepiaCommand cannot be undo as it resets the entire frame.
*/
sf::Packet SepiaCommand::execute(){
    sf::Packet sepiaPacket;
    unsigned int tempNum = 0;
    sepiaPacket << "SEPIA" << tempNum << tempNum << theCanvas->getBrushString() << theCanvas->getBGString();

    int px, py;
    for(py=0; py < theCanvas->getWindowHeight(); py++){
        for(px=0; px < theCanvas->getWindowWidth(); px++){
            sf::Color pColor = theCanvas->getImage()->getPixel(px, py);
            int pR = pColor.r;
            int pG = pColor.g;
            int pB = pColor.b;
            int tR = ((0.393 * pR) + (0.769 * pG) + (0.189 * pB));
            int tG = ((0.349 * pR) + (0.686 * pG) + (0.168 * pB));
            int tB = ((0.272 * pR) + (0.534 * pG) + (0.131 * pB));
            int newRed = sepiaHelper(tR);
            int newGreen = sepiaHelper(tG);
            int newBlue = sepiaHelper(tB);
            sf::Color newColor = sf::Color(newRed, newGreen, newBlue);
            theCanvas->getImage()->setPixel(px, py, newColor);
        }
    }
    theCanvas->clearStacks();
    return sepiaPacket;
}

/*! \brief  SepiaCommand's sepiaHelper function
*
*   It is a small, helper function for the execute function.
*   It checks to see if a number is greater than 255.
*   If it is, it returns 255. If not, it returns the number itself.
*/
int SepiaCommand::sepiaHelper(int x){
    if(x > 225){
        return 255;
    }
    return x;
}

/*! \brief  SepiaCommand's getDescription function
*
*   Returns the string description "SEPIA" for the Command object.
*/
std::string SepiaCommand::getDescription(){
    return "SEPIA";
}
