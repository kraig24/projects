#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include "Canvas.hpp"
#include <string>
#include <iostream>
#include <stack>

class Command
{
    private:
        std::string cDescription;
    public:
        Command(std::string description) : cDescription(description) {}
        ~Command(){};
        virtual sf::Packet execute() = 0;
        virtual std::string getDescription() = 0;

};

#endif
