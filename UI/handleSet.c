#include "../Set/set.h"
#include "handlers.h"

/*  PRINT INFO OF SET (size and current state)  */
void printSetInfo(MySet* s)
{
    printf("\n\t\tCURRENT SET: ");
    printSet(s);
    printf("\t\tSIZE: %d\n", setSize(s));
    fflush(stdout);
}

/*  PRINT SET MENU  */
void printSetMenu(MySet* s)
{
    printf("\n- MAIN MENU -> SET MENU\n");
    printSetInfo(s);
    printf("\n"
           MENUOPTION("Add element", "A")
           MENUOPTION("Remove element", "R")
           MENUOPTION("Check if element exists", "E")
           MENUOPTION("Print Set", "P")
           EXIT
           SELECT);
    fflush(stdout);
}

void handleSet()
{
    MySet* s = newSet();
    char quit = 0, choice = 0;
    int in0 = 0;
    while (!quit) {

        clearConsole();
        printSetMenu(s);
        scanf(" %c", &choice); // Get user input.

        switch (choice) {
            case 'A':
                printf("\n\t\t\tSelect element to add: ");
                scanf(" %d", &in0);

                // ADD NEW ELEMENT
                addTo(s, in0);
                break;

            case 'R':
                printf("\n\t\t\tSelect element to remove: ");
                scanf(" %d", &in0);

                // REMOVE ELEMENT
                removeFrom(s, in0);
                break;

            case 'E':
                printf("\n\t\t\tSelect element to look for: ");
                scanf(" %d", &in0);

                printf(
                    "\n\t\t\tElement %s exist in the set\n", exists(s, in0) ? "DOES" : "DOES NOT");
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

        if (!quit) {
            printf("\n\t\t\tContinue? Y/n -> ");
            scanf(" %c", &choice);

            while (1) {
                if (choice == 'n' || choice == 'N') {
                    freeSet(s);
                    fflush(stdout);
                    return;
                } else if (choice == 'y' || choice == 'Y') {
                    break;
                } else {
                    printf("\n\t\t\tInvalid Input. Continue? Y/n -> ");
                    scanf(" %c", &choice);
                }
            }
        }
    }
}