#include "handlers.h"
#include "../Linked-List/linked-list.h"

/*  PRINT INFO OF LINKED LIST (size and current state)  */
void printListInfo(MyLinkedList* l){
    fprintf(stdout, "\n\t\tCURRENT LINKED LIST: ");
    printList(l);
    fprintf(stdout, "\t\tSIZE: %d\n", listSize(l));
    fflush(stdout);
}

/*  PRINT LINKED LIST MENU  */
void printListMenu(MyLinkedList* l){
        fprintf(stdout, "\n- MAIN MENU -> LINKED LIST MENU\n");
        printListInfo(l);
        fprintf(stdout, "\n\t\tAdd new element: 'A'\n"
                        "\t\tAdd at index: 'a'\n"
                        "\t\tRemove element: 'R'\n"
                        "\t\tRemove at Index: 'r'\n"
                        "\t\tAdd a group of elements: 'G'\n"
                        "\t\tRemove a group of elements: 'g'\n"
                        "\t\tCheck if an element exists: 'c'\n"
                        "\t\tGet element at index: 'i'\n"
                        "\t\tPrint List: 'p'\n"
                        "\t\tExit: 'e'\n"
                        "\t\tSelect Option: ");
        fflush(stdout);
}

void handleLinkedList(){
    MyLinkedList* l = createList();
    char quit = 0, choice = 0;
    int in0 = 0, in1 = 0;
    while (!quit){

        clearConsole();
        printListMenu(l);
        fscanf(stdin, " %c", &choice);  // Get user input.

        switch(choice){
            case 'A':

                fprintf(stdout, "\n\t\t\tSelect element to add: ");
                fscanf(stdin, " %d", &in0);

                l = addElem(l, in0);
                break;

            case 'a':

                fprintf(stdout, "\n\t\t\tSelect element: ");
                fscanf(stdin, " %d", &in0);

                fprintf(stdout, "\n\t\t\tSelect Index: ");
                fscanf(stdin, " %d", &in1);

                // PLACE ELEM AT INDEX, IF VALID.
                l = addElemAtIndex(l, in0, in1);
                break;
            
            case 'R':

                fprintf(stdout, "\n\t\t\tSelect element to remove: ");
                fscanf(stdin, " %d", &in0);
                
                // REMOVE ALL INSTANCES OF SELECTED ELEMENT
                l = removeElemByValue(l, in0);
                break;
            
            case 'r':

                fprintf(stdout, "\n\t\t\tSelect index to remove: ");
                fscanf(stdin, " %d", &in1);
                
                // REMOVE ELEMENT BY INDEX
                l = removeElemByIndex(l, in1);
                break;

            case 'G':

                fprintf(stdout, "\n\t\t\tSelect size of group: ");
                fscanf(stdin, " %d", &in0);

                int* group = malloc(in0*sizeof(int));
                for (int i = 0; i<in0; ++i){
                    fprintf(stdout, "\n\t\t\tgroup[%d]: ", i);
                    fscanf(stdin, " %d", &group[i]);
                }
                l = addElemGroup(l, group, in0);
                free(group);
                break;
            
            case 'g':

                fprintf(stdout, "\n\t\t\tSelect size of group: ");
                fscanf(stdin, " %d", &in0);

                int* group2 = malloc(in0*sizeof(int));
                for (int i = 0; i<in0; ++i){
                    fprintf(stdout, "\n\t\t\tgroup[%d]: ", i);
                    fscanf(stdin, " %d", &group[i]);
                }
                l = removeGroup(l, group, in0);
                free(group2);
                break;

            case 'c':

                fprintf(stdout, "\n\t\t\tSelect Element to look for: ");
                fscanf(stdin, " %d", &in0);

                fprintf(stdout, "\n\t\t\tThe element %d %s exist in the list.\n", in0, elemExists(l, in0) ? "DOES" : "DOES NOT");
                break;
            
            case 'i':

                fprintf(stdout, "\n\t\t\tSelect Index to look at: ");
                fscanf(stdin, " %d", &in1);

                if (in1<0 || in1>=listSize(l)) {
                    fprintf(stdout, "\n\t\t\tINVALID INDEX.\n");
                    break;
                }

                fprintf(stdout, "\n\t\t\tThe element at index %d is %d.\n", in1, elemAtIndex(l, in1));
                break;

            case 'p':
                printListInfo(l);
                break;

            case 'e':
                quit = 1;
                freeList(l);
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
                    freeList(l);
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