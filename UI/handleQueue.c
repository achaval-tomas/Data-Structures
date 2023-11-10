#include "handlers.h"
#include "../Queue/queue.h"

/*  PRINT INFO OF QUEUE (size and current state)  */
void printQueueInfo(MyQueue* q){
    printf("\n\t\tCURRENT QUEUE: ");
    q_print(q);
    printf("\t\tSIZE: %d\n", q_size(q));
    fflush(stdout);
}

/*  PRINT QUEUE MENU  */
void printQueueMenu(MyQueue* q){
        printf("\n- MAIN MENU -> QUEUE MENU\n");
        printQueueInfo(q);
        printf("\n\t\tEnqueue: 'E'\n"
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
    int in0 = 0;
    while (!quit){

        clearConsole();
        printQueueMenu(q);
        scanf(" %c", &choice);  // Get user input.

        switch(choice){
            case 'E':
                printf("\n\t\t\tSelect element to enqueue: ");
                scanf(" %d", &in0);

                // ENQUEUE NEW ELEMENT
                q = q_enqueue(q, in0);
                break;
            
            case 'D':
                printf("\n\t\t\tDEQUEUED: %d\n", q_front(q));
                q_dequeue(q);
                break;

            case 'F':
                printf("\n\t\t\tELEMENT IN FRONT: %d\n", q_front(q));
                break;

            case 'P':
                printQueueInfo(q);
                break;

            case 'e':
                quit = 1;
                q_free(q);
                fflush(stdout);
                break;

            default:
                break;
        }

        if (!quit){
            printf("\n\t\t\tContinue? Y/n -> ");
            scanf(" %c", &choice);

            while (1) {
                if (choice == 'n' || choice == 'N'){
                    q_free(q);
                    fflush(stdout);
                    return;
                } else if (choice == 'y' || choice == 'Y'){
                    break;
                } else {
                    printf("\n\t\t\tInvalid Input. Continue? Y/n -> ");
                    scanf(" %c", &choice);
                }
            }
        }

    }
}