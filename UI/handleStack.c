#include "handlers.h"
#include "../Stack/stack.h"

/*  PRINT INFO OF STACK (size and current state)  */
void printStackInfo(MyStack* s){
    fprintf(stdout, "\n\t\tCURRENT STACK: ");
    s_print(s);
    fprintf(stdout, "\t\tSIZE: %d\n", s_size(s));
    fflush(stdout);
}

/*  PRINT STACK MENU  */
void printStackMenu(MyStack* s){
        fprintf(stdout, "\n- MAIN MENU -> STACK MENU\n");
        printStackInfo(s);
        fprintf(stdout, "\n\t\tPush to stack: 'P'\n"
                        "\t\tPop stack: 'p'\n"
                        "\t\tTop of stack: 't'\n"
                        "\t\tPrint Stack: 's'\n"
                        "\t\tExit: 'e'\n"
                        "\t\tSelect Option: ");
        fflush(stdout);
}

void handleStack(){
    MyStack* stack = s_newStack();
    char quit = 0, choice = 0;
    int elem = 0;
    while (!quit){

        clearConsole();
        printStackMenu(stack);
        fscanf(stdin, " %c", &choice);  // Get user input.

        switch(choice){
            case 'P':
                fprintf(stdout, "\n\t\t\tSelect elem to push: ");
                fscanf(stdin, " %d", &elem);

                // PUSH TO STACK
                stack = s_push(stack, elem);
                break;
            
            case 'p':
                fprintf(stdout, "\n\t\t\tPOPPING: %d\n", s_top(stack));
                s_pop(stack);
                break;

            case 't':
                fprintf(stdout, "\n\t\t\tTOP: %d\n", s_top(stack));
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

        if (!quit){
            fprintf(stdout, "\n\t\t\tContinue? Y/n -> ");
            fscanf(stdin, " %c", &choice);
            
            while (1) {
                if (choice == 'n' || choice == 'N'){
                    s_free(stack);
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