# Your CMakeLists.txt for the main App project
# This time what is new is I have added:
# 1.) another 'add_executable'
# 2.) another 'target_link_libraries'
#
# Observe now you will have two projects setup.
# As they stand, they will be identical.
####################################################
# The minimum required version of CMake to ouse
cmake_minimum_required(VERSION 3.10)

# Set the project name to your project name
project(Assignment4 LANGUAGES CXX C)

# Where are the include directories
# include_directories("/usr/local/include")
# include_directories("./include/")
# include_directories("/usr/local/Cellar/sfml/2.5.1/include/")

# Where are the libraries
# Hint: On linux you can grep for them: ldconfig -p | grep sfml
link_directories("./include/")
find_package(SFML 2.5 COMPONENTS system window graphics network REQUIRED)
find_package(OpenGL REQUIRED)
find_package(Catch2 REQUIRED)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE "Debug")

# Add the source code files to a specific project
# We can indeed have multiple executables generated from
# one CMakeLists.txt file.
# For example, we might have test files that we want
# to generate.
add_executable(App ./src/main.cpp ./src/Canvas.cpp ./src/GUIFrame.cpp ./src/Client.cpp ./src/Server.cpp ./src/InputHandler.cpp 
                    ./src/DrawCommand.cpp ./src/UndoCommand.cpp ./src/RedoCommand.cpp ./src/ClearCommand.cpp
                    ./src/SepiaCommand.cpp ./src/DitherCommand.cpp ./src/GreyscaleCommand.cpp ./src/BufferCommand.cpp)

add_executable(App_Test ./tests/main_test.cpp ./src/Canvas.cpp ./src/GUIFrame.cpp ./src/Client.cpp ./src/Server.cpp ./src/InputHandler.cpp 
                   ./src/DrawCommand.cpp ./src/UndoCommand.cpp ./src/RedoCommand.cpp ./src/ClearCommand.cpp
                   ./src/SepiaCommand.cpp ./src/DitherCommand.cpp ./src/GreyscaleCommand.cpp ./src/BufferCommand.cpp ./tests/NetworkTestManager)

add_executable(MockApp ./src/mockMain.cpp ./src/Canvas.cpp ./src/GUIFrame.cpp ./src/Client.cpp ./src/Server.cpp ./src/InputHandler.cpp 
                    ./src/DrawCommand.cpp ./src/UndoCommand.cpp ./src/RedoCommand.cpp ./src/ClearCommand.cpp
                    ./src/SepiaCommand.cpp ./src/DitherCommand.cpp ./src/GreyscaleCommand.cpp ./src/BufferCommand.cpp)

# Add any libraries
# On linux, you can use the handy 'apt-file' tool to find
# where exactly header files exist. See example below:
# 	sudo apt install apt-file
#   	sudo apt-file update
# 	apt-file find Texture.hpp
target_link_libraries(App sfml-graphics sfml-window sfml-system sfml-network OpenGL::GL)

target_link_libraries(App_Test sfml-graphics sfml-window sfml-system sfml-network OpenGL::GL)

target_link_libraries(MockApp sfml-graphics sfml-window sfml-system sfml-network OpenGL::GL)

target_include_directories(App
    PRIVATE
        include/
)

target_include_directories(App_Test
   PRIVATE
       include/
)

target_include_directories(MockApp
   PRIVATE
       include/
)
