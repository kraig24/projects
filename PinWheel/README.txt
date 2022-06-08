#####
Pip installs needed:

Requests:
pip3 install requests

BeautifulSoup
pip install beautifulsoup4
#####

This program Doesn't take command line arguments (I could add them with argc, argv if needed, but since it is so tiny,
I just got user input to get the information needed (prompt will ask for one for part 1 answer and 2 for part 2).
Make sure when running part one that you don't have any spaces between your files, just commas. The part one answer will
print out the JSON object it is going to send out for analysis, I had the it take in a dictionary with the needed values.
The index of the JSON tree is the index of the file given, in case it is needed later on.

For part 2, all one has to do is give the name of the file, as well as the range when asked. This will then download
the needed forms for you.

If there are any questions or issues running, let me know. I have it working on my machine but since this project isn't
in Docker or similar system, anything can happen :)

Enjoy!

Kraig Johnson
kraigjohnson24@gmail.com
585-354-3826

