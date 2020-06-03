#include "Canvas.hpp"
#include <cassert>
#include "Constants.hpp"


/*! \brief  Canvas Constructor
*
*   Initializes a Convas object and creates the graphic objects the Canvas will need.
*   This includes a RenderWindow, Image, Texture and Sprite.
*/
Canvas::Canvas(){
    canvasHeight = 500;
    canvasWidth = 500;

    canvasWindow = new sf::RenderWindow(sf::VideoMode(canvasHeight,canvasHeight), "Canvas Window",sf::Style::Titlebar);
	canvasWindow->setVerticalSyncEnabled(true);
	canvasWindow->setActive(true);
	glViewport(0, 0, canvasWindow->getSize().x, canvasWindow->getSize().y);

	canvasImage = new sf::Image();
	canvasImage->create(canvasWidth,canvasHeight, sf::Color::White);
	assert(canvasImage != nullptr && "canvasImage != nullptr");

	canvasTexture = new sf::Texture();
	canvasTexture->loadFromImage(*canvasImage);
	assert(canvasTexture != nullptr && "canvasTexture != nullptr");

	canvasSprite = new sf::Sprite(*canvasTexture);
	assert(canvasSprite != nullptr && "canvasSprite != nullptr");
    
    commandStack = new std::stack<sf::Packet>;
    undoStack = new std::stack<sf::Packet>;

    bgColor = sf::Color::White;
    bgString = "WHITE";
    brushColor = sf::Color::Black;
    brushString = "BLACK";
    
    isServer =false;
    filter = NONE;
    running = false;
}

/*! \brief  Canvas Deconstructor
*   
*   Is called when the Canvas object is destroyed.
*/
Canvas::~Canvas(){
    //
}

/*! \brief  refreshCanvas function
*   
*   Reloads the updated canvasImage into the canvasTexture.
*/
void Canvas::refreshCanvas(){
    canvasTexture->loadFromImage(*canvasImage);
}

/*! \brief  setBrushColor function
*   
*   Sets the stored brushString to the given string color value,
*   and sets the stored brushColor to the sf::Color value of the string.
*/
void Canvas::setBrushColor(std::string setColor){
    brushString = setColor;
    brushColor = this->getColor(setColor);
}

/*! \brief  setBGColor function
*   
*   Sets the stored bgString to the given string color value,
*   and sets the stored bgColor to the sf::Color value of the string.
*/
void Canvas::setBGColor(std::string setColor){
    bgString = setColor;
    bgColor = this->getColor(setColor);
}

/*! \brief  setXCoordinate function
*   
*   Sets the stored oldX value to the current xCoord value,
*   and sets the new xCoord value to the given xVal.
*/
void Canvas::setXCoordinate(unsigned int xVal){
    oldX = xCoord;
    xCoord = xVal;
}

/*! \brief  setYCoordinate function
*   
*   Sets the stored oldY value to the current yCoord value,
*   and sets the new yCoord value to the given yVal.
*/
void Canvas::setYCoordinate(unsigned int yVal){
    oldY = yCoord;
    yCoord = yVal;
}

/*! \brief  getColor function
*   
*   Returns the correct sf::Color of the given string.
*/
sf::Color Canvas::getColor(std::string col){
    if(col == "BLACK"){
        return sf::Color::Black;
    }
    else if(col == "WHITE"){
        return sf::Color::White;
    }
    else if(col == "BLUE"){
        return sf::Color::Blue;
    }
    else if(col == "RED"){
        return sf::Color::Red;
    }
    else if(col == "GREEN"){
        return sf::Color::Green;
    }
    else if(col == "YELLOW"){
        return sf::Color::Yellow;
    }
    else if(col == "MAGENTA"){
        return sf::Color::Magenta;
    }
    else if(col == "CYAN"){
        return sf::Color::Cyan;
    }
    else{
        return sf::Color::Black;
    }
}

/*! \brief  getImage function
*   
*   Returns the stored canvasImage value, an sf::Image pointer.
*/
sf::Image* Canvas::getImage(){
    return canvasImage;
}

/*! \brief  getSprite function
*   
*   Returns the stored canvasSprite value, an sf::Sprite pointer.
*/
sf::Sprite* Canvas::getSprite(){
    return canvasSprite;
}

/*! \brief  getTexture function
*   
*   Returns the stored canvasTexture value, an sf::Texture pointer.
*/
sf::Texture* Canvas::getTexture(){
    return canvasTexture;
}

/*! \brief  getWindow function
*   
*   Returns the stored canvasWindow value, an sf::Window pointer.
*/
sf::RenderWindow* Canvas::getWindow(){
    return canvasWindow;
}

/*! \brief  getBrushColor function
*   
*   Returns the stored brushColor value, an sf::Color object.
*/
sf::Color Canvas::getBrushColor(){
    return brushColor;
}

/*! \brief  getBGColor function
*   
*   Returns the stored bgColor value, an sf::Color object.
*/
sf::Color Canvas::getBGColor(){
    return bgColor;
}

/*! \brief  getBrushString function
*   
*   Returns the stored brushString value, a string.
*/
std::string Canvas::getBrushString(){
    return brushString;
}

/*! \brief  getBGString function
*   
*   Returns the stored bgString value, a string.
*/
std::string Canvas::getBGString(){
    return bgString;
}

/*! \brief  getXCoord function
*   
*   Returns the stored xCoord value, an unsigned int.
*/
unsigned int Canvas::getXCoord(){
    return xCoord;
}

/*! \brief  getYCoord function
*   
*   Returns the stored yCoord value, an unsigned int.
*/
unsigned int Canvas::getYCoord(){
    return yCoord;
}

/*! \brief  getOldX function
*   
*   Returns the stored oldX value, an unsigned int.
*/
unsigned int Canvas::getOldX(){
    return oldX;
}

/*! \brief  getOldY function
*   
*   Returns the stored oldY value, an unsigned int.
*/
unsigned int Canvas::getOldY(){
    return oldY;
}

/*! \brief  commandPush function
*   
*   Pushes the given packet to the commandStack.
*/
void Canvas::commandPush(sf::Packet packet){
	commandStack->push(packet);
}

/*! \brief  undoPush function
*   
*   Pushes the given packet to the undoStack.
*/
void Canvas::undoPush(sf::Packet packet){
	undoStack->push(packet);
}

/*! \brief  commandPop function
*   
*   Pops the packet at the top of the commandStack off.
*/
void Canvas::commandPop(){
	commandStack->pop();
}

/*! \brief  undoPop function
*   
*   Pops the packet at the top of the undoStack off.
*/
void Canvas::undoPop(){
	undoStack->pop();
}

/*! \brief  commandTop function
*   
*   Returns the sf::Packet at the top of the commandStack.
*/
sf::Packet Canvas::commandTop(){
    return commandStack->top();
}

/*! \brief  undoTop function
*   
*   Returns the sf::Packet at the top of the undoStack.
*/
sf::Packet Canvas::undoTop(){
    return undoStack->top();
}

/*! \brief  commandEmptyStatus function
*   
*   Returns true if the commandStack is empty, 
*   and false otherwise.
*/
bool Canvas::commandEmptyStatus(){
    return commandStack->empty();
}

/*! \brief  undoEmptyStatus function
*   
*   Returns true if the undoStack is empty, 
*   and false otherwise.
*/
bool Canvas::undoEmptyStatus(){
    return undoStack->empty();
}

/*! \brief  clearStacks function
*   
*   Resets both the commandStack and the undoStack.
*/
void Canvas::clearStacks(){
    commandStack = new std::stack<sf::Packet>;
    undoStack = new std::stack<sf::Packet>;
}

/*! \brief  getWindowWidth function
*   
*   Returns the storedcanvasWidth value, an unsigned int.
*/
unsigned int Canvas::getWindowWidth(){
    return canvasWidth;
}

/*! \brief  getWindowHeight function
*   
*   Returns the storedcanvasHeight value, an unsigned int.
*/
unsigned int Canvas::getWindowHeight(){
    return canvasHeight;
}

/*! \brief  setServer function
*   
*   Sets the bool value to true for the stored isServer.
*/
void Canvas::setServer(){
    isServer = true;
}

/*! \brief  getServer function
*   
*   Returns the stored isServer value, a boolen.
*/
bool Canvas::getServer(){
    return isServer;
}

/*! \brief  setRunning function
*   
*   Sets the bool value for running to the given boolean value.
*/
void Canvas::setRunning(bool run){
    running = run;
}

/*! \brief  getRunning function
*   
*   Returns the stored running value, a boolen.
*/
bool Canvas::getRunning(){
    return running;
}

/*! \brief  setFilter function
*   
*   Sets the filter value to the given Filter value.
*/
void Canvas::setFilter(Filter filt){
    filter = filt;
}

/*! \brief  getFilter function
*   
*   Returns the stored filter value, an int.
*/
int Canvas::getFilter(){
    return filter;
}

/*! \brief  closeApp function
*   
*   Deletes the Image, Sprite, and Texture objects used by the Canvas.
*/
void Canvas::closeApp(){
    delete canvasImage;
    delete canvasSprite;
    delete canvasTexture;
}