#ifndef GUIFRAME_HPP
#define GUIFRAME_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Network.hpp>

#include <iostream>
#include "Constants.hpp"
#include "Canvas.hpp"
#include "NetworkManager.hpp"
#include "InputHandler.hpp"
#include "Command.hpp"
#include "ClearCommand.hpp"
#include "DitherCommand.hpp"
#include "GreyscaleCommand.hpp"
#include "SepiaCommand.hpp"


#define GUI_INIT_WIDTH 500
#define GUI_INIT_HEIGHT 600



/**
 * @brief GUI Frame class handles all the GUI Window dependencies.
 * 
 */
class GUIFrame {
    private:
        /**
         * @brief Canvas Object copy is maintained
         * 
         */
        Canvas *canvasObj;
        /**
         * @brief A gui window object.
         * 
         */
        sf::RenderWindow *gui_window;
        
        
    public:
        /**
         * @brief Construct a new GUIFrame object
         * 
         * @param canvasAppObj A Canvas object is maintained in the GUI Object.
         */
        GUIFrame(Canvas *canvasAppObj);
        /**
         * @brief Destroy the GUIFrame object
         * 
         */
        ~GUIFrame();
        /**
         * @brief Initializes a GUI and applies settings.
         * 
         */
        void GUIInit();
        
        void closeGUI();
        void drawLayout(NetworkManager *network, struct nk_colorf& bg, std::string method, sf::Packet cBufferPacket, sf::Event *canvasEvent);

        void setBrushColor(std::string setColor);
        void setBGColor(std::string setColor);
        void setXCoordinate(unsigned int xVal);
        void setYCoordinate(unsigned int yVal);
        sf::Packet clearCommand();
        
        sf::Color getBrushColor();
        sf::Color getBGColor();
        std::string getBrushString();
        std::string getBGString();
        unsigned int getXCoord();
        unsigned int getYCoord();
        sf::Color getColor(std::string col);

        struct nk_context *ctx;
        int prev_filter;
        int cur_filter;
        void setGUIWindow(sf::RenderWindow &);
        sf::RenderWindow& getGUIWindow();
        sf::Vector2i* guiWindowPosition;

        void ditherHelper(NetworkManager*);
        void sepiaHelper(NetworkManager*);
        void grayscaleHelper(NetworkManager*);

       int getFilter();
        void setFilter(Filter);
        void guiEventHandler(sf::Event*);
        void postEvent(NetworkManager*, struct nk_colorf& , std::string , sf::Packet , sf::Event*);

   
        
};





#endif // GUIHANDLER_HPP