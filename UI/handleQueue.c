#include "handlers.h"
#include "../Queue/queue.h"

/*  PRINT INFO OF QUEUE (size and current state)  */
void printQueueInfo(MyQueue* q){
    fprintf(stdout, "\n\t\tCURRENT QUEUE: ");
    q_print(q);
    fprintf(stdout, "\t\tSIZE: %d\n", q_size(q));
    fflush(stdout);
}

/*  PRINT QUEUE MENU  */
void printQueueMenu(MyQueue* q){
        fprintf(stdout, "\n- MAIN MENU -> QUEUE MENU\n");
        printQueueInfo(q);
        fprintf(stdout, "\n\t\tEnqueue: 'E'\n"
                        "\t\tDequeue: 'D'\n"
                        "\t\tFront of queue: 'F'\n"
                        "\t\tPrint Queue: 'P'\n"
                        "\t\tExit: 'e'\n"
                        "\t\tSelect Option: ");
        fflush(stdout);
}

void handleQueue(){
    MyQueue* q = q_newQueue();
    char quit = 0, choice = 0;
    int elem = 0;
    while (!quit){

        clearConsole();
        printQueueMenu(q);
        fflush(stdin);
        fscanf(stdin, " %c", &choice);  // Get user input.

        switch(choice){
            case 'E':

                fprintf(stdout, "\n\t\t\tSelect elem to enqueue: ");
                fflush(stdin);
                fscanf(stdin, " %d", &elem);

                // ENQUEUE NEW ELEMENT
                q = q_enqueue(q, elem);
                break;
            
            case 'D':
                fprintf(stdout, "\n\t\t\tDEQUEUED: %d\n", q_front(q));
                q_dequeue(q);
                break;

            case 'F':
                fprintf(stdout, "\n\t\t\tELEMENT IN FRONT: %d\n", q_front(q));
                break;

            case 'P':
                printQueueInfo(q);
                break;

            case 'e':
                quit = 1;
                q_free(q);
                fflush(stdin);
                fflush(stdout);
                break;

            default:
                break;
        }

        if (!quit){
            fprintf(stdout, "\n\t\t\tContinue? Y/n -> ");
            fflush(stdin);
            fscanf(stdin, " %c", &choice);
            while (1) {
                if (choice == 'n' || choice == 'N'){
                    q_free(q);
                    fflush(stdin);
                    fflush(stdout);
                    return;
                } else if (choice == 'y' || choice == 'Y'){
                    break;
                } else {
                    fprintf(stdout, "\n\t\t\tInvalid Input. Continue? Y/n -> ");
                    fflush(stdin);
                    fscanf(stdin, " %c", &choice);
                }
            }
        }

    }
}