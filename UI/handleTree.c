#include "../Trees/Binary-Tree/binaryTree.h"
#include "handlers.h"

/*  PRINT INFO OF TREE (size and current state)  */
void printTreeInfo(MyTree* t)
{
    printf("\n\t\tCURRENT TREE (INORDER TRAVERSAL): ");
    printTree(t, INORDER);
    printf("\t\tSIZE: %d\n", treeSize(t));
    fflush(stdout);
}

/*  PRINT TREE MENU  */
void printTreeMenu(MyTree* t)
{
    printf("\n- MAIN MENU -> TREE MENU\n");
    printTreeInfo(t);
    printf("\n"
           MENUOPTION("Add Node", "A")
           MENUOPTION("Remove Node (all instances)", "R")
           MENUOPTION("Check if node exists", "C")
           MENUOPTION("Print in a special order traversal", "P")
           MENUOPTION("Print Tree", "p")
           MENUOPTION("Visualize Tree", "v")
           EXIT
           SELECT);
    fflush(stdout);
}

void handleTree()
{
    MyTree* t = newTree();
    char quit = 0, choice = 0;
    int in0 = 0;
    while (!quit) {

        clearConsole();
        printTreeMenu(t);
        scanf(" %c", &choice); // Get user input.

        switch (choice) {
            case 'A':
                printf("\n\t\t\tSelect node to add: ");
                scanf(" %d", &in0);

                // ADD THE NEW NODE
                addNode(t, in0);
                break;

            case 'R':
                printf("\n\t\t\tSelect node to remove: ");
                scanf(" %d", &in0);

                // REMOVE ALL INSTANCES OF THE CHOSEN NODE
                removeNode(t, in0);
                break;

            case 'C':
                printf("\n\t\t\tSelect node to look for: ");
                scanf(" %d", &in0);

                // CHECK IF CHOSEN NODE EXISTS
                printf("\n\t\t\tThe node %d %s exist in the Tree.\n", in0,
                    isNode(t, in0) ? "DOES" : "DOES NOT");
                break;

            case 'P':
                printf("\n"
                       "\t\t\tPREORDER TRAVERSAL -> '0'\n"
                       "\t\t\tINORDER TRAVERSAL -> '1'\n"
                       "\t\t\tPOSTORDER TRAVERSAL -> '2'\n"
                       "\n\t\t\tSelect an order: ");

                scanf(" %d", &in0); // Save order selection in &in0.

                printf("\n\t\t\t%sORDER TRAVERSAL IS: ",
                    in0 == 0       ? "PRE"
                        : in0 == 1 ? "IN"
                                   : "POST");
                printTree(t, in0);
                break;

            case 'p':
                printTreeInfo(t);
                break;

            case 'v':
                clearConsole();
                visualizeTree(t, 12); // Print tree visualization with offset.
                break;

            case 'e':
                quit = 1;
                freeTree(t);

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
                    freeTree(t);
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
