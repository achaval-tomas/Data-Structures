#include "../Stack/stack.h"
#include "handlers.h"

/*  PRINT INFO OF STACK (size and current state)  */
void printStackInfo(MyStack* s)
{
    printf("\n\t\tCURRENT STACK: ");
    s_print(s);
    printf("\t\tSIZE: %d\n", s_size(s));
    fflush(stdout);
}

/*  PRINT STACK MENU  */
void printStackMenu(MyStack* s)
{
    printf("\n- MAIN MENU -> STACK MENU\n");
    printStackInfo(s);
    printf("\n\t\tPush to stack: 'P'\n"
           "\t\tPop stack: 'p'\n"
           "\t\tTop of stack: 't'\n"
           "\t\tPrint Stack: 's'\n"
           "\t\tExit: 'e'\n"
           "\t\tSelect Option: ");
    fflush(stdout);
}

void handleStack()
{
    MyStack* stack = s_newStack();
    char quit = 0, choice = 0;
    int in0 = 0;
    while (!quit) {

        clearConsole();
        printStackMenu(stack);
        scanf(" %c", &choice); // Get user input.

        switch (choice) {
            case 'P':
                printf("\n\t\t\tSelect element to push: ");
                scanf(" %d", &in0);

                // PUSH TO STACK
                stack = s_push(stack, in0);
                break;

            case 'p':
                printf("\n\t\t\tPOPPING: %d\n", s_top(stack));
                s_pop(stack);
                break;

            case 't':
                printf("\n\t\t\tTOP: %d\n", s_top(stack));
                break;

            case 's':
                printStackInfo(stack);
                break;

            case 'e':
                quit = 1;
                s_free(stack);
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
                    s_free(stack);
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