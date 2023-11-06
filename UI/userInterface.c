/*
 *  This is a console interface to play around with
 *  the different data structures in the library.
 */
#include <stdio.h>
#include "handlers.h"

void printMenu(){
    fprintf(stdout, "\n- MAIN MENU\n"
                    "SELECT AN OPTION:\n"
                    "\tArray: 'a'\n"
                    "\tSet: 's'\n"
                    "\tQueue: 'q'\n"
                    "\tStack: 'k'\n"
                    "\tTree: 't'\n"
                    "\tGraph: 'g'\n"
                    "\tExit: 'e'\n"
                    "\tSelect Option: ");
    fflush(stdout);
}

int main(int argc, char* argv[]){
    char quit = 0;
    char choice = 0;
    while (!quit){

        printMenu();
        fflush(stdin);
        fscanf(stdin, " %c", &choice);  // Get user input.

        switch(choice){
            case 'a':
                handleArray();
                break;
            case 'q':
                handleQueue();
                break;
            case 'k':
                handleStack();
                break;
            case 'e':
                fflush(stdin);
                fflush(stdout);
                quit = 1;
            default:
                break;
        }
    }

    return 0;
}