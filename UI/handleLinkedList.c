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
    int elem = 0, idx = 0;
    while (!quit){

        clearConsole();
        printListMenu(l);
        fflush(stdin);
        fscanf(stdin, " %c", &choice);  // Get user input.

        switch(choice){
            case 'A':

                fprintf(stdout, "\n\t\t\tSelect element to add: ");
                fflush(stdin);
                fscanf(stdin, " %d", &elem);

                l = addElem(l, elem);
                break;

            case 'a':

                fprintf(stdout, "\n\t\t\tSelect elem: ");
                fflush(stdin);
                fscanf(stdin, " %d", &elem);

                fprintf(stdout, "\n\t\t\tSelect Index: ");
                fflush(stdin);
                fscanf(stdin, " %d", &idx);

                // PLACE ELEM AT INDEX, IF VALID.
                l = addElemAtIndex(l, elem, idx);
                break;
            
            case 'R':

                fprintf(stdout, "\n\t\t\tSelect elem to remove: ");
                fflush(stdin);
                fscanf(stdin, " %d", &elem);
                
                // REMOVE ALL INSTANCES OF SELECTED ELEMENT
                l = removeElemByValue(l, elem);
                break;
            
            case 'r':

                fprintf(stdout, "\n\t\t\tSelect index to remove: ");
                fflush(stdin);
                fscanf(stdin, " %d", &idx);
                
                // REMOVE ELEMENT BY INDEX
                l = removeElemByIndex(l, idx);
                break;

            case 'G':

                fprintf(stdout, "\n\t\t\tSelect size of group: ");
                fflush(stdin);
                fscanf(stdin, " %d", &elem);

                int* group = malloc(elem*sizeof(int));
                for (int i = 0; i<elem; ++i){
                    fprintf(stdout, "\n\t\t\tgroup[%d]: ", i);
                    fscanf(stdin, " %d", &group[i]);
                }
                l = addElemGroup(l, group, elem);
                free(group);
                break;
            
            case 'g':

                fprintf(stdout, "\n\t\t\tSelect size of group: ");
                fflush(stdin);
                fscanf(stdin, " %d", &elem);

                int* group2 = malloc(elem*sizeof(int));
                for (int i = 0; i<elem; ++i){
                    fprintf(stdout, "\n\t\t\tgroup[%d]: ", i);
                    fscanf(stdin, " %d", &group[i]);
                }
                l = removeGroup(l, group, elem);
                free(group2);
                break;

            case 'c':

                fprintf(stdout, "\n\t\t\tSelect Element to look for: ");
                fflush(stdin);
                fscanf(stdin, " %d", &elem);

                fprintf(stdout, "\n\t\t\tThe element %d %s exist in the list.\n", elem, elemExists(l, elem) ? "DOES" : "DOES NOT");
                break;
            
            case 'i':

                fprintf(stdout, "\n\t\t\tSelect Index to look at: ");
                fflush(stdin);
                fscanf(stdin, " %d", &idx);
                if (idx<0 || idx>=listSize(l)) {
                    fprintf(stdout, "\n\t\t\tINVALID INDEX.\n");
                    break;
                }
                fprintf(stdout, "\n\t\t\tThe element at index %d is %d.\n", idx, elemAtIndex(l, idx));
                break;

            case 'p':
                printListInfo(l);
                break;

            case 'e':
                quit = 1;
                freeList(l);
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
                    freeList(l);
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