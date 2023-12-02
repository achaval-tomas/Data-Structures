#include "handlers.h"
#include "../Lists/Linked-List/linked-list.h"

/*  PRINT INFO OF LINKED LIST (size and current state)  */
void printListInfo(MyLinkedList* l){
    printf("\n\t\tCURRENT LINKED LIST: ");
    printList(l);
    printf("\t\tSIZE: %d\n", listSize(l));
    fflush(stdout);
}

/*  PRINT LINKED LIST MENU  */
void printListMenu(MyLinkedList* l){
        printf("\n- MAIN MENU -> LINKED LIST MENU\n");
        printListInfo(l);
        printf("\n\t\tAdd new element: 'A'\n"
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
        scanf(" %c", &choice);  // Get user input.

        switch(choice){
            case 'A':

                printf("\n\t\t\tSelect element to add: ");
                scanf(" %d", &in0);

                l = addElem(l, in0);
                break;

            case 'a':

                printf("\n\t\t\tSelect element: ");
                scanf(" %d", &in0);

                printf("\n\t\t\tSelect Index: ");
                scanf(" %d", &in1);

                // PLACE ELEM AT INDEX, IF VALID.
                l = addElemAtIndex(l, in0, in1);
                break;
            
            case 'R':

                printf("\n\t\t\tSelect element to remove: ");
                scanf(" %d", &in0);
                
                // REMOVE ALL INSTANCES OF SELECTED ELEMENT
                l = removeElemByValue(l, in0);
                break;
            
            case 'r':

                printf("\n\t\t\tSelect index to remove: ");
                scanf(" %d", &in1);
                
                // REMOVE ELEMENT BY INDEX
                l = removeElemByIndex(l, in1);
                break;

            case 'G':

                printf("\n\t\t\tSelect size of group: ");
                scanf(" %d", &in0);

                int* group = malloc(in0*sizeof(int));
                for (int i = 0; i<in0; ++i){
                    printf("\n\t\t\tgroup[%d]: ", i);
                    scanf(" %d", &group[i]);
                }
                l = addElemGroup(l, group, in0);
                free(group);
                break;
            
            case 'g':

                printf("\n\t\t\tSelect size of group: ");
                scanf(" %d", &in0);

                int* group2 = malloc(in0*sizeof(int));
                for (int i = 0; i<in0; ++i){
                    printf("\n\t\t\tgroup[%d]: ", i);
                    scanf(" %d", &group[i]);
                }
                l = removeGroup(l, group, in0);
                free(group2);
                break;

            case 'c':

                printf("\n\t\t\tSelect Element to look for: ");
                scanf(" %d", &in0);

                printf("\n\t\t\tThe element %d %s exist in the list.\n", in0, elemExists(l, in0) ? "DOES" : "DOES NOT");
                break;
            
            case 'i':

                printf("\n\t\t\tSelect Index to look at: ");
                scanf(" %d", &in1);

                if (in1<0 || in1>=listSize(l)) {
                    printf("\n\t\t\tINVALID INDEX.\n");
                    break;
                }

                printf("\n\t\t\tThe element at index %d is %d.\n", in1, elemAtIndex(l, in1));
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
            printf("\n\t\t\tContinue? Y/n -> ");
            scanf(" %c", &choice);

            while (1) {
                if (choice == 'n' || choice == 'N'){
                    freeList(l);
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
