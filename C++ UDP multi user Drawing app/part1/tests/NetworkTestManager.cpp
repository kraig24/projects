#include "NetworkTestManager.hpp"
#include "Command.hpp"
#include "Client.hpp"
#include "Server.hpp"

// Exec header
#include <unistd.h>

/**
 * @brief Construct a new TestManager object
 */
NetworkTestManager::NetworkTestManager(){}

/**
 * @brief Function that launches our Network tests. It spawns
 *  a server and three clients. The server is bound to port 2000,
 *  and the clients, 2001, 2002, and 2010. The third flag that's called
 *  in the char* list of args is a flag that initiates a client sending a
 *  a command simulating a user interacting with the canvas. The "testNumber"
 *  is a string in the form "test[int]" that flags a conditional in the mockMain
 *  that builds a command to be sent to the server, and subsequently the
 *  clients. The test will return 3 if all three clients have received the packet
 *  sent from the third client, and a number less than 3 otherwise.
*/
int NetworkTestManager::runTest(char* testNumber){
    char *args1[] = {"s", "2000", "Empty", "receiver", NULL};
    char *args2[] = {"c", "2001", "2000", "receiver", NULL};
    char *args3[] = {"c", "2002", "2000", "receiver", NULL};
    char *args4[] = {"c", "2010", "2000", testNumber, NULL};
    int result, success1, success2, success3;
    int pid;
    
    // Catch forking error
    pid = fork();
    if(pid < 0){
        perror("fork() error");
        exit(-1);
    }
    // Launch server
    if(pid == 0){
        execv("./MockApp", args1);
    }
    
    // Launch clients under same parent
    else {
        sleep(3);
        for(int i=0;i<=2;i++){
            if(fork() == 0){
                switch (i) {
                    case 0:
                        execv("./MockApp", args2);
                        break;
                    case 1:
                        sleep(1);
                        execv("./MockApp", args3);
                        break;
                    case 2:
                        sleep(2);
                        execv("./MockApp", args4);
                        break;
                    default:
                        exit(0);
                }
            }
        }
    }
    // WAIT FOR CHILDREN
    int waitstatus1;
    wait(&waitstatus1);
    success1 = WEXITSTATUS(waitstatus1);
    int waitstatus2;
    wait(&waitstatus2);
    success2 = WEXITSTATUS(waitstatus2);
    int waitstatus3;
    wait(&waitstatus3);
    
    success3 = WEXITSTATUS(waitstatus3);
    
    // Parent Process Ended
    result = success1 + success2 + success3;
    return result;
}

