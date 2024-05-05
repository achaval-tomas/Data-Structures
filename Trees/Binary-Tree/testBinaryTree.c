/*  My Binary Tree Testing  */

#include "binaryTree.h"

int main(void)
{

    MyTree* tester = newTree();

    /*  TESTING ADD NODE  */
    for (int i = 1; i <= 11; ++i)
        addNode(tester, i);

    /*  TESTING SIZE  */
    printf("SIZE: %d\n\n", treeSize(tester));

    /*  TESING ORDER TRAVERSALS AND TREE TO ARRAY*/
    printf("PREORDER TRAVERSAL:\n");
    printf("SHOULD BE [ 1 2 4 8 6 10 3 5 9 7 11 ]\n\tIT IS: ");
    printTree(tester, PREORDER);
    printf("\n");

    printf("INORDER TRAVERSAL:\n");
    printf("SHOULD BE [ 8 4 2 10 6 1 9 5 3 11 7 ]\n\tIT IS: ");
    printTree(tester, INORDER);
    printf("\n");

    printf("POSTORDER TRAVERSAL:\n");
    printf("SHOULD BE [ 8 4 10 6 2 9 5 11 7 3 1 ]\n\tIT IS: ");
    printTree(tester, POSTORDER);
    printf("\n");

    /*  TESTING IS EMPTY AND EXISTS  */
    printf("IS IT EMPTY? %d -> should be 0\n", isEmpty(tester));
    printf("DOES 11 EXIST? %d -> should be 1\n", isNode(tester, 11));
    printf("DOES 99 EXIST? %d -> should be 0\n", isNode(tester, 99));
    printf("\n");
    fflush(stdout);

    /*  TESTING REMOVE NODE  */
    printf("REMOVING NODES...\n");
    printf("\t");
    printTree(tester, INORDER);
    for (int i = 1; i <= 11; ++i) {
        removeNode(tester, i);
        printf("\t");
        printTree(tester, INORDER);
    }
    printf("\n");

    /*  TESTING IS EMPTY AGAIN  */
    printf("IS IT EMPTY? %d -> should now be 1\n", isEmpty(tester));
    printf("\n");
    fflush(stdout);

    /*  TESTING REMOVE ALL INSTANCES OF AN ELEMENT  */
    for (int i = 0; i < 10; ++i) {
        addNode(tester, 1);
        addNode(tester, 0);
    }

    printf("TREE SHOULD BE COMPOSED OF 0s AND 1s\n\tTREE: ");
    printTree(tester, INORDER);
    printf("IS IT EMPTY? %d -> should be 0, SIZE: %d\n", isEmpty(tester), treeSize(tester));
    printf("\n");

    removeNode(tester, 1);
    printf("TREE SHOULD BE COMPOSED OF ONLY 0s\n\tTREE: ");
    printTree(tester, INORDER);
    printf("IS IT EMPTY? %d -> should be 0, SIZE: %d\n", isEmpty(tester), treeSize(tester));
    printf("\n");

    removeNode(tester, 0);
    printf("TREE SHOULD BE EMPTY\n\tTREE: ");
    printTree(tester, INORDER);
    printf("IS IT EMPTY? %d -> should be 1, SIZE: %d\n", isEmpty(tester), treeSize(tester));
    printf("\n");

    freeTree(tester);
    printf("\nALL TESTCASES PASSED SUCCESSFULLY.\n");
    fflush(stdout);

    return 0;
}