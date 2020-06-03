#include "InputHandler.hpp"

InputHandler::InputHandler(sf::Event *ievent, Canvas *icanvas, std::string imethod, sf::Packet ipacket){
    inputEvent = ievent;
    inputCanvas = icanvas;
    inputWindow = inputCanvas->getWindow();
    inputMethod = imethod;
    inputPacket = ipacket;
    if(inputPacket >> receivedCommand >> receivedX >> receivedY >> receivedBrush >> receivedBG){
        std::cout << "received" << std::endl;
    }
}

InputHandler::~InputHandler(){
    //
}

Command* InputHandler::handleButton(){
    if(inputEvent->key.code == sf::Keyboard::Z){
        return new UndoCommand(inputCanvas);
    }
    else if(inputEvent->key.code == sf::Keyboard::Y){
        return new RedoCommand(inputCanvas);
    }
    else if(inputEvent->key.code == sf::Keyboard::Space){
        return new ClearCommand(inputCanvas, inputMethod, receivedBrush);
    }
    else if(inputEvent->key.code == sf::Keyboard::D){
        return new DitherCommand(inputCanvas);
    }
    else if(inputEvent->key.code == sf::Keyboard::S){
        return new SepiaCommand(inputCanvas);
    }
    else if(inputEvent->key.code == sf::Keyboard::G){
        return new GreyscaleCommand(inputCanvas);
    }
    else if(inputEvent->key.code == sf::Keyboard::Num1){
        inputCanvas->setBrushColor("BLACK");
        return new BufferCommand(inputCanvas);
    }
    else if(inputEvent->key.code == sf::Keyboard::Num2){
        inputCanvas->setBrushColor("WHITE");
        return new BufferCommand(inputCanvas);
    }
    else if(inputEvent->key.code == sf::Keyboard::Num3){
        inputCanvas->setBrushColor("RED");
        return new BufferCommand(inputCanvas);
    }
    else if(inputEvent->key.code == sf::Keyboard::Num4){
        inputCanvas->setBrushColor("GREEN");
        return new BufferCommand(inputCanvas);
    }
    else if(inputEvent->key.code == sf::Keyboard::Num5){
        inputCanvas->setBrushColor("BLUE");
        return new BufferCommand(inputCanvas);
    }
    else if(inputEvent->key.code == sf::Keyboard::Num6){
        inputCanvas->setBrushColor("YELLOW");
        return new BufferCommand(inputCanvas);
    }
    else if(inputEvent->key.code == sf::Keyboard::Num7){
        inputCanvas->setBrushColor("MAGENTA");
        return new BufferCommand(inputCanvas);
    }
    else if(inputEvent->key.code == sf::Keyboard::Num8){
        inputCanvas->setBrushColor("CYAN");
        return new BufferCommand(inputCanvas);
    }
    else{
        return new BufferCommand(inputCanvas);
    }
}


Command* InputHandler::handleMouse(){
    return new DrawCommand(inputCanvas, inputMethod, inputCanvas->getBrushString(), inputCanvas->getBGString(), 
                            inputCanvas->getXCoord(), inputCanvas->getYCoord());
}


Command* InputHandler::handleReceive(){
    if(receivedCommand == "DRAW"){
        return new DrawCommand(inputCanvas, inputMethod, receivedBrush, receivedBG, receivedX, receivedY);
    }
    else if(receivedCommand == "CLEAR"){
        return new ClearCommand(inputCanvas, inputMethod, receivedBrush);
    }
    else if(receivedCommand == "DITHER"){
        return new DitherCommand(inputCanvas);
    }
    else if(receivedCommand == "SEPIA"){
        return new SepiaCommand(inputCanvas);
    }
    else if(receivedCommand == "GREYSCALE"){
        return new GreyscaleCommand(inputCanvas);
    }
    else{
        return new BufferCommand(inputCanvas);
    }

}
