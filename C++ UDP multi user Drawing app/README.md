C++ UDP multi-user Drawing app


This is a project that utilizes several well known C++ libraries (SFML, Nuklear Catch2) to make a drawing application.
There is a server object that is connected via UDP connection to anyone with proper port ID and IP address for the server. Then, the program will launch and allow users to each paint on a single canvas, seeing each other's work. The program works by sending packets of data containing pixel RGB values to the server, and then the server sends this using the command pattern to each of the users connected.

There are an infinite amount of connections available, so long as the server connection is strong enough to run it. I also created a front end menu using Nuklear which can change the paint colors, as well as add different kinds of filters to the drawing (e.g. Sepia, greyscale)

If a user presses the z button, they can undo any drawing that they have done. This is done by continually saving the data in a stack, popping a command off when the key is pressed.

I chose a UDP connection for this project because, though UDP is unreliable in packet delivery, it is faster and scales better with more users. A TCP connection would have been too choppy to create a well-rounded user experience.
