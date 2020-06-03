// Include some standard libraries
// The 'C-based' libraries are needed for Nuklear GUI
#include <stdarg.h>
// Nuklear needs to call OpenGL functions
#include <SFML/OpenGL.hpp>
// NUKLEAR implementation
#define NK_INCLUDE_FIXED_TYPES
#define NK_INCLUDE_STANDARD_IO
#define NK_INCLUDE_STANDARD_VARARGS
#define NK_INCLUDE_DEFAULT_ALLOCATOR
#define NK_INCLUDE_VERTEX_BUFFER_OUTPUT
#define NK_INCLUDE_FONT_BAKING
#define NK_INCLUDE_DEFAULT_FONT
#define NK_IMPLEMENTATION
#define NK_SFML_GL2_IMPLEMENTATION


#include "nuklear.h"
#include "nuklear_sfml_gl2.h"

#include "GUIFrame.hpp"


/*! \brief  GUIFrame Constructor
*
*   
*/
GUIFrame::GUIFrame(Canvas *canvasAppObj)
{
    canvasObj = canvasAppObj;
    prev_filter = DEFAULT;
    cur_filter = NONE;
	sf::ContextSettings settings(24, 8, 4, 2, 2);
	gui_window = new sf::RenderWindow(sf::VideoMode(GUI_INIT_WIDTH,GUI_INIT_HEIGHT), "GUI Window",sf::Style::Default,settings);
    setGUIWindow(*gui_window);
	GUIInit();
}

/*! \brief  GUIFrame Deconstructor
*
*   
*/
GUIFrame::~GUIFrame() 
{
    std::cout << "GUI destructor called" << std::endl;
}

/*! \brief  GUIInit Function
*
*   
*/
void GUIFrame::GUIInit() 
{
	    getGUIWindow().setPosition(sf::Vector2i(canvasObj->getWindow()->getPosition().x - canvasObj->getWindowWidth(), canvasObj->getWindow()->getPosition().y));
	    getGUIWindow().setVerticalSyncEnabled(true);
	    getGUIWindow().setActive(true);

        ctx = nk_sfml_init(&getGUIWindow());
        // Load Fonts: if none of these are loaded a default font will be used
        //Load Cursor: if you uncomment cursor loading please hide the cursor
        struct nk_font_atlas *atlas;
        nk_sfml_font_stash_begin(&atlas);
        nk_sfml_font_stash_end();
        
	    // Capture input from the nuklear GUI
	    nk_input_begin(ctx);
  
}

 void GUIFrame::setGUIWindow(sf::RenderWindow &guiWindow)
 {
      gui_window = &guiWindow;
 }




sf::RenderWindow& GUIFrame::getGUIWindow()
{
    return *gui_window;
}


void GUIFrame::postEvent(NetworkManager *network, struct nk_colorf& bg, std::string method, sf::Packet cBufferPacket, sf::Event *canvasEvent)
{
            nk_input_end(ctx);
			drawLayout(network, bg,  method, cBufferPacket, canvasEvent);
			getGUIWindow().clear();
			glClearColor(bg.r, bg.g, bg.b, bg.a);
			glClear(GL_COLOR_BUFFER_BIT);
			nk_sfml_render(NK_ANTI_ALIASING_ON);
			getGUIWindow().display();
}


void GUIFrame::drawLayout(NetworkManager *network, struct nk_colorf& bg, std::string method, sf::Packet cBufferPacket, sf::Event *canvasEvent)
{
    /* GUI */
	if (nk_begin(ctx, "Paint", nk_rect(0, 0, 500, 600),
		 NK_WINDOW_BACKGROUND | NK_WINDOW_TITLE | NK_WINDOW_SCALABLE | NK_WINDOW_BORDER ))
	{
		static int property = 20;

		nk_layout_row_dynamic(ctx, 30, 2);
		if (nk_option_label(ctx, "RED", getBrushColor() == sf::Color::Red)){
			setBrushColor("RED");
            
		}
		if (nk_option_label(ctx, "BLACK", getBrushColor() == sf::Color::Black)){
			setBrushColor("BLACK");
		}
		if (nk_option_label(ctx, "GREEN", getBrushColor() == sf::Color::Green)){
			setBrushColor("GREEN");
		}
		if (nk_option_label(ctx, "BLUE", getBrushColor() == sf::Color::Blue)){
			setBrushColor("BLUE");
		}
		if (nk_option_label(ctx, "WHITE", getBrushColor() == sf::Color::White)){
			setBrushColor("WHITE");
		}
		if (nk_option_label(ctx, "YELLOW", getBrushColor() == sf::Color::Yellow)){
			setBrushColor("YELLOW");
		}
		if (nk_option_label(ctx, "MAGENTA", getBrushColor() == sf::Color::Magenta)){
			setBrushColor("MAGENTA");
		}
		if (nk_option_label(ctx, "CYAN", getBrushColor() == sf::Color::Cyan)){
			setBrushColor("CYAN");
		}


       
		nk_layout_row_dynamic(ctx, 20, 1);
		nk_label(ctx, "SFML Background Change with above selected color?", NK_TEXT_LEFT);

		nk_layout_row_dynamic(ctx, 25, 1);
		if (nk_button_label(ctx, "YES")) {
                canvasObj->setBGColor(canvasObj->getBrushString());
                ClearCommand *clearComObj = new ClearCommand(canvasObj, method, getBrushString());
                Command *command = clearComObj;
                if(command->getDescription() != "BUFFER"){
						sf::Packet mouseResult = command->execute();
						network->sendData(mouseResult);
						std::cout << "sent data" << std::endl;
				}
   		 }
        nk_layout_row_dynamic(ctx, 20, 1);
		nk_label(ctx, "Choose Filter: ", NK_TEXT_LEFT);
        nk_layout_row_dynamic(ctx, 20, 4);
        if (nk_option_label(ctx, "None", getFilter() == NONE)){
            setFilter(NONE); 
		}

		if (nk_option_label(ctx, "Dither", getFilter() == DITHER)){
            setFilter(DITHER);
            if(cur_filter==NONE && prev_filter==DEFAULT){
                cur_filter = DITHER;
                ditherHelper(network);
            }
            else if (cur_filter==GRAYSCALE || cur_filter==SEPIA ){
                prev_filter = cur_filter;
                cur_filter = DITHER;
                ditherHelper(network);
            }
		}
		if (nk_option_label(ctx, "Grayscale", getFilter() == GRAYSCALE)){
            setFilter(GRAYSCALE);
            if(cur_filter==NONE && prev_filter==DEFAULT){
                
                cur_filter = GRAYSCALE;
                grayscaleHelper(network);
            }else if (cur_filter==DITHER || cur_filter==SEPIA){
                prev_filter = cur_filter;
                cur_filter = GRAYSCALE;
                grayscaleHelper(network);
            }
		}
		if (nk_option_label(ctx, "Sepia", getFilter() ==  SEPIA)){
            setFilter(SEPIA);
            if(cur_filter==NONE && prev_filter==DEFAULT){
                cur_filter = SEPIA;
                sepiaHelper(network);
            }
            else if (cur_filter==DITHER || cur_filter==GRAYSCALE){
                prev_filter = cur_filter;
                cur_filter = SEPIA;
                sepiaHelper(network);
            }
		}

		nk_layout_row_dynamic(ctx, 20, 1);
		nk_label(ctx, "Align Canvas to GUI after moving GUI Window ?", NK_TEXT_LEFT);

		nk_layout_row_dynamic(ctx, 25, 1);
		if (nk_button_label(ctx, "YES")) {
				canvasObj->getWindow()->setPosition(sf::Vector2i(getGUIWindow().getPosition().x + GUI_INIT_WIDTH, getGUIWindow().getPosition().y));
   		 }
		
		nk_layout_row_dynamic(ctx, 20, 1);
		nk_label(ctx, "GUI Background:", NK_TEXT_LEFT);
		nk_layout_row_dynamic(ctx, 25, 1);
		
		if (nk_combo_begin_color(ctx, nk_rgb_cf(bg), nk_vec2(nk_widget_width(ctx),400))) {
			nk_layout_row_dynamic(ctx, 120, 1);
			bg = nk_color_picker(ctx, bg, NK_RGBA);
			nk_layout_row_dynamic(ctx, 25, 1);
			bg.r = nk_propertyf(ctx, "#R:", 0, bg.r, 1.0f, 0.01f,0.005f);
			bg.g = nk_propertyf(ctx, "#G:", 0, bg.g, 1.0f, 0.01f,0.005f);
			bg.b = nk_propertyf(ctx, "#B:", 0, bg.b, 1.0f, 0.01f,0.005f);
			bg.a = nk_propertyf(ctx, "#A:", 0, bg.a, 1.0f, 0.01f,0.005f);
			nk_combo_end(ctx);
		}
	}
	nk_end(ctx);
}


void GUIFrame::ditherHelper(NetworkManager *network)
{
    DitherCommand *ditherObj = new DitherCommand(canvasObj);
    Command *command = ditherObj;
    if(command->getDescription() != "BUFFER"){
		sf::Packet mouseResult = command->execute();
		network->sendData(mouseResult);
		std::cout << "sent data" << std::endl;
	}
}


void GUIFrame::sepiaHelper(NetworkManager *network)
{
    SepiaCommand *sepiaObj = new SepiaCommand(canvasObj);
    Command *command = sepiaObj;
    if(command->getDescription() != "BUFFER"){
		sf::Packet mouseResult = command->execute();
		network->sendData(mouseResult);
		std::cout << "sent data" << std::endl;
	}

}

void GUIFrame::grayscaleHelper(NetworkManager *network)
{
    GreyscaleCommand *greyObj = new GreyscaleCommand(canvasObj);
    Command *command = greyObj;
    if(command->getDescription() != "BUFFER"){
		sf::Packet mouseResult = command->execute();
		network->sendData(mouseResult);
		std::cout << "sent data" << std::endl;
	}
    
}






void GUIFrame::closeGUI() 
{
    nk_sfml_shutdown();
    delete gui_window;
}

void GUIFrame::guiEventHandler(sf::Event* canvasEvent)
{
    while(getGUIWindow().pollEvent(*canvasEvent)){
				if(canvasEvent->type == sf::Event::Closed){
					nk_sfml_shutdown();
					getGUIWindow().close();
					exit(EXIT_SUCCESS);
				}
				// Capture any keys that are released
				else if(canvasEvent->type == sf::Event::KeyReleased){
					std::cout << "Key Pressed" << std::endl;
					// Check if the escape key is pressed.
					if(canvasEvent->key.code == sf::Keyboard::Escape ){
						nk_sfml_shutdown();
						getGUIWindow().close();
						exit(EXIT_SUCCESS);
					}
					else if (canvasEvent->key.code == sf::Keyboard::Up)
					{
						canvasObj->getWindow()->setPosition(sf::Vector2i(getGUIWindow()
						.getPosition().x + GUI_INIT_WIDTH, getGUIWindow()
						.getPosition().y));
					}
				}
				nk_sfml_handle_event(canvasEvent);
			}

}

void GUIFrame::setBrushColor(std::string setColor) 
{
    canvasObj->setBrushColor(setColor);
    
}

void GUIFrame::setBGColor(std::string setColor) 
{
     canvasObj->setBGColor(setColor);
}


void GUIFrame::setXCoordinate(unsigned int xVal) 
{
    canvasObj->setXCoordinate(xVal);
}


void GUIFrame::setYCoordinate(unsigned int yVal) 
{
    canvasObj->setYCoordinate(yVal);
}

sf::Color GUIFrame::getBrushColor() 
{
    return canvasObj->getBrushColor();
}

sf::Color GUIFrame::getBGColor() 
{
    return canvasObj->getBGColor();
}

std::string GUIFrame::getBrushString() 
{
    return canvasObj->getBrushString();
}

std::string GUIFrame::getBGString() 
{
    return canvasObj->getBGString();
}

unsigned int GUIFrame::getXCoord() 
{
    return canvasObj->getXCoord();
} 

unsigned int GUIFrame::getYCoord() 
{
    return canvasObj->getYCoord();
}

int GUIFrame::getFilter()
{
    return canvasObj->getFilter();
}

void GUIFrame::setFilter(Filter filt)
{
    canvasObj->setFilter(filt);
}
