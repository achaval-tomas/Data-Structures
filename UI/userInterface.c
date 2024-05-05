/*
 *  This is a console interface to play around with
 *  the different data structures in the library.
 */
#include "handlers.h"
#include <stdio.h>

void printMenu()
{
    printf("\n- MAIN MENU\n"
           "SELECT AN OPTION:\n"
           "\tArray: 'a'\n"
           "\tLinked List: 'l'\n"
           "\tDoubly Linked List: 'd'\n"
           "\tSet: 's'\n"
           "\tQueue: 'q'\n"
           "\tStack: 'k'\n"
           "\tTree: 't'\n"
           "\tGraph: 'g'\n"
           "\tExit: 'e'\n"
           "\tSelect Option: ");
    fflush(stdout);
}

int main(int argc, char* argv[])
{
    char quit = 0;
    char choice = 0;
    while (!quit) {

        clearConsole();
        printMenu();
        scanf(" %c", &choice); // Get user input.

        switch (choice) {
            case 'a':
                handleArray();
                break;
            case 'l':
                handleLinkedList();
                break;
            case 'd':
                handleDoublyLinkedList();
                break;
            case 's':
                handleSet();
                break;
            case 'q':
                handleQueue();
                break;
            case 'k':
                handleStack();
                break;
            case 't':
                handleTree();
                break;
            case 'g':
                handleGraph();
                break;
            case 'e':
                fflush(stdout);
                quit = 1;
                break;
            default:
                break;
        }
    }
    clearConsole();
    return 0;
}
