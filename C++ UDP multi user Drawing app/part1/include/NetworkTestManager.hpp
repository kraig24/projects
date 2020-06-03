#ifndef NetworkTestManager_hpp
#define NetworkTestManager_hpp

#include <stdio.h>
#include <string>
#include <SFML/Network.hpp>
#include "Command.hpp"
#include <Constants.hpp>

using namespace std;

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 400

// Anytime we want to implement a new command in our paint tool,
// we have to inherit from the command class.
// This forces us to implement an 'execute' and 'undo' command.
class NetworkTestManager
{
public:
    NetworkTestManager();
    int runTest(char* testNumber);
};
#endif
