This is a popular project used by UC Berkley's AI class in order to teach foundational AI algorithms such as Alpha Beta Pruning,
Min-Max, and various local search algorithms.

In this project, the goal is to write an AI algorithm that will lead PACMAN to collect all of the dots without being touched
by the ghosts. The faster the program is solved, th ebetter your program. For this, I used a combination of min-max and local
search algorithms to find the fastest results. Essentially, Pacman can only every move in four directions (North, West, South,
East). By turning these choices into a tree structure, I used pruning to figure out which choices should. never be chosen, and in
aggregate their children never needed to be checked. I then utilized local search to make sure my program would not got stuck in
in a false success thinking no fruit were left when in reality they were just outside of the scope of the AI player.


Avoiding the ghosts was the most difficult part. In order to do this, I? added a heuristic to each position. The AI was trained
to go towards a move if it had the highest heuristic value, being eaten by a ghost would result in a -9999 heauristic. By doing
this, Pacman would almost always avoid the ghost's direction because her would analyze their possible movements in the state
tree above. 

Overall, this was a very fun project to build and learn more about the foundations of artificial intelligence. 
