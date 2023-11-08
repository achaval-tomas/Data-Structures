#include "handlers.h"
#include "../Trees/Binary-Tree/binaryTree.h"

/*  PRINT INFO OF TREE (size and current state)  */
void printTreeInfo(MyTree* t){
    fprintf(stdout, "\n\t\tCURRENT TREE (INORDER TRAVERSAL): ");
    printTree(t, INORDER);
    fprintf(stdout, "\t\tSIZE: %d\n", treeSize(t));
    fflush(stdout);
}

/*  PRINT TREE MENU  */
void printTreeMenu(MyTree* t){
        fprintf(stdout, "\n- MAIN MENU -> TREE MENU\n");
        printTreeInfo(t);
        fprintf(stdout, "\n\t\tAdd Node: 'A'\n"
                        "\t\tRemove Node (all instances): 'R'\n"
                        "\t\tCheck if node exists: 'C'\n"
                        "\t\tPrint in a special order traversal: 'P'\n"
                        "\t\tPrint Tree: 'p'\n"
                        "\t\tExit: 'e'\n"
                        "\t\tSelect Option: ");
        fflush(stdout);
}

void handleTree(){
    MyTree* t = newTree();
    char quit = 0, choice = 0;
    int elem = 0;
    while (!quit){

        clearConsole();
        printTreeMenu(t);
        fflush(stdin);
        fscanf(stdin, " %c", &choice);  // Get user input.

        switch(choice){
            case 'A':

                fprintf(stdout, "\n\t\t\tSelect node to add: ");
                fflush(stdin);
                fscanf(stdin, " %d", &elem);

                // ADD THE NEW NODE
                addNode(t, elem);
                break;
            
            case 'R':
                fprintf(stdout, "\n\t\t\tSelect node to remove: ");
                fflush(stdin);
                fscanf(stdin, " %d", &elem);

                // REMOVE ALL INSTANCES OF THE CHOSEN NODE
                removeNode(t, elem);
                break;

            case 'C':
                fprintf(stdout, "\n\t\t\tSelect node to look for: ");
                fflush(stdin);
                fscanf(stdin, " %d", &elem);

                // CHECK IF CHOSEN NODE EXISTS
                fprintf(stdout, "\n\t\t\tThe node %d %s exist in the Tree.\n", elem, isNode(t, elem) ? "DOES": "DOES NOT");
                break;

            case 'P':
                fprintf(stdout, "\n"
                                "\t\t\tPREORDER TRAVERSAL -> '0'\n"
                                "\t\t\tINORDER TRAVERSAL -> '1'\n"
                                "\t\t\tPOSTORDER TRAVERSAL -> '2'\n"
                                "\n\t\t\tSelect an order: ");
                fflush(stdin);
                fscanf(stdin, " %d", &elem); // Save order selection in &elem.
                
                fprintf(stdout, "\n\t\t\t%sORDER TRAVERSAL IS: ", elem == 0 ? "PRE" : elem == 1 ? "IN" : "POST");
                printTree(t, elem);
                break;

            case 'p':
                printTreeInfo(t);
                break;

            case 'e':
                quit = 1;
                freeTree(t);
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
                    freeTree(t);
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