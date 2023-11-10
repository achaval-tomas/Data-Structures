#include "handlers.h"
#include "../Set/set.h"

/*  PRINT INFO OF SET (size and current state)  */
void printSetInfo(MySet* s){
    fprintf(stdout, "\n\t\tCURRENT SET: ");
    printSet(s);
    fprintf(stdout, "\t\tSIZE: %d\n", setSize(s));
    fflush(stdout);
}

/*  PRINT SET MENU  */
void printSetMenu(MySet* s){
        fprintf(stdout, "\n- MAIN MENU -> SET MENU\n");
        printSetInfo(s);
        fprintf(stdout, "\n\t\tAdd element: 'A'\n"
                        "\t\tRemove element: 'R'\n"
                        "\t\tCheck if element exists: 'E'\n"
                        "\t\tPrint Set: 'P'\n"
                        "\t\tExit: 'e'\n"
                        "\t\tSelect Option: ");
        fflush(stdout);
}

void handleSet(){
    MySet* s = newSet();
    char quit = 0, choice = 0;
    int elem = 0;
    while (!quit){

        clearConsole();
        printSetMenu(s);
        fscanf(stdin, " %c", &choice);  // Get user input.

        switch(choice){
            case 'A':
                fprintf(stdout, "\n\t\t\tSelect element to add: ");
                fscanf(stdin, " %d", &elem);

                // ADD NEW ELEMENT
                addTo(s, elem);
                break;
            
            case 'R':
                fprintf(stdout, "\n\t\t\tSelect element to remove: ");
                fscanf(stdin, " %d", &elem);

                // REMOVE ELEMENT
                removeFrom(s, elem);
                break;

            case 'E':
                fprintf(stdout, "\n\t\t\tSelect element to look for: ");
                fscanf(stdin, " %d", &elem);

                fprintf(stdout, "\n\t\t\tElement %s exist in the set\n", exists(s, elem) ? "DOES" : "DOES NOT");
                break;

            case 'P':
                printSetInfo(s);
                break;

            case 'e':
                quit = 1;
                freeSet(s);
                fflush(stdout);
                break;

            default:
                break;
        }

        if (!quit){
            fprintf(stdout, "\n\t\t\tContinue? Y/n -> ");
            fscanf(stdin, " %c", &choice);
            
            while (1) {
                if (choice == 'n' || choice == 'N'){
                    freeSet(s);
                    fflush(stdout);
                    return;
                } else if (choice == 'y' || choice == 'Y'){
                    break;
                } else {
                    fprintf(stdout, "\n\t\t\tInvalid Input. Continue? Y/n -> ");
                    fscanf(stdin, " %c", &choice);
                }
            }
        }

    }
}