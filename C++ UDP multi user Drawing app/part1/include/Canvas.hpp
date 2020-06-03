#ifndef CANVAS_HPP
#define CANVAS_HPP


#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Window.hpp>
#include <cassert>
#include <string>
#include <iostream>
#include <stack>
#include "Constants.hpp"
#include "NetworkManager.hpp"
#include "Command.hpp"

#define CANVAS_INIT_WIDTH 500
#define CANVAS_INIT_HEIGHT 500


using namespace std;

class Canvas
{
    private:
        sf::Color brushColor;
        sf::Color bgColor;
        std::string brushString;
        std::string bgString;
        unsigned int xCoord;
        unsigned int yCoord;
        unsigned int oldX;
        unsigned int oldY;
        unsigned int canvasHeight;
        unsigned int canvasWidth;

        bool isServer;
        int filter;
        bool running;

        std::stack<sf::Packet> *commandStack;
        std::stack<sf::Packet> *undoStack;

        sf::RenderWindow *canvasWindow;
        sf::Texture *canvasTexture;
        sf::Sprite *canvasSprite;
        sf::Image *canvasImage;
    
    public:
        Canvas();
        ~Canvas();
        
        void refreshCanvas();
        void addCommand(sf::Packet);

        void setBrushColor(std::string setColor);
        void setBGColor(std::string setColor);
        void setXCoordinate(unsigned int xVal);
        void setYCoordinate(unsigned int yVal);
        
        sf::Color getColor(std::string col);
        sf::Image* getImage();
        sf::Sprite* getSprite();
        sf::Texture* getTexture();
        sf::RenderWindow* getWindow();
        sf::Color getBrushColor();
        sf::Color getBGColor();
        std::string getBrushString();
        std::string getBGString();
        unsigned int getXCoord();
        unsigned int getYCoord();
        unsigned int getOldX();
        unsigned int getOldY();
        
        void commandPop();
        void undoPop();
        void undoPush(sf::Packet packet);
        void commandPush(sf::Packet packet);
        bool commandEmptyStatus();
        bool undoEmptyStatus();
        sf::Packet commandTop();
        sf::Packet undoTop();
        void clearStacks();


        //Window Size Getter
        unsigned int getWindowWidth();
        unsigned int getWindowHeight();
        void setServer();
        bool getServer();

        int getFilter();
        void setFilter(Filter);
        void closeApp();
        bool getRunning();
        void setRunning(bool);



};


#endif 