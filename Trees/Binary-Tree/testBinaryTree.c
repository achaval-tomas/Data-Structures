/*  My Binary Tree Testing  */

#include "binaryTree.h"

int main(void){

    MyTree* tester = newTree();

    /*  TESTING ADD NODE  */
    for (int i = 1; i<=11; ++i)
        addNode(tester, i);

    /*  TESTING SIZE  */
    fprintf(stdout, "SIZE: %d\n\n", treeSize(tester));

    /*  TESING ORDER TRAVERSALS AND TREE TO ARRAY*/
    fprintf(stdout, "PREORDER TRAVERSAL:\n");
    fprintf(stdout, "SHOULD BE [ 1 2 4 8 6 10 3 5 9 7 11 ]\n\tIT IS: ");
    printTree(tester, PREORDER);
    fprintf(stdout, "\n");

    fprintf(stdout, "INORDER TRAVERSAL:\n");
    fprintf(stdout, "SHOULD BE [ 8 4 2 10 6 1 9 5 3 11 7 ]\n\tIT IS: ");
    printTree(tester, INORDER);
    fprintf(stdout, "\n");

    fprintf(stdout, "POSTORDER TRAVERSAL:\n");
    fprintf(stdout, "SHOULD BE [ 8 4 10 6 2 9 5 11 7 3 1 ]\n\tIT IS: ");
    printTree(tester, POSTORDER);
    fprintf(stdout, "\n");

    /*  TESTING IS EMPTY AND EXISTS  */
    fprintf(stdout, "IS IT EMPTY? %d -> should be 0\n", isEmpty(tester));
    fprintf(stdout, "DOES 11 EXIST? %d -> should be 1\n", isNode(tester, 11));
    fprintf(stdout, "DOES 99 EXIST? %d -> should be 0\n", isNode(tester, 99));
    fprintf(stdout, "\n");
    fflush(stdout);

    /*  TESTING REMOVE NODE  */
    fprintf(stdout, "REMOVING NODES...\n");
    fprintf(stdout, "\t");
    printTree(tester, INORDER);
    for (int i = 1; i<=11; ++i){
        removeNode(tester, i);
        fprintf(stdout, "\t");
        printTree(tester, INORDER);
    }
    fprintf(stdout, "\n");

    /*  TESTING IS EMPTY AGAIN  */
    fprintf(stdout, "IS IT EMPTY? %d -> should now be 1\n", isEmpty(tester));
    fprintf(stdout, "\n");
    fflush(stdout);

    /*  TESTING REMOVE ALL INSTANCES OF AN ELEMENT  */
    for (int i = 0; i<10; ++i){
        addNode(tester, 1);
        addNode(tester, 0);
    }

    fprintf(stdout, "TREE SHOULD BE COMPOSED OF 0s AND 1s\n\tTREE: ");
    printTree(tester, INORDER);
    fprintf(stdout, "IS IT EMPTY? %d -> should be 0, SIZE: %d\n", isEmpty(tester), treeSize(tester));
    fprintf(stdout, "\n");

    removeNode(tester, 1);
    fprintf(stdout, "TREE SHOULD BE COMPOSED OF ONLY 0s\n\tTREE: ");
    printTree(tester, INORDER);
    fprintf(stdout, "IS IT EMPTY? %d -> should be 0, SIZE: %d\n", isEmpty(tester), treeSize(tester));
    fprintf(stdout, "\n");

    removeNode(tester, 0);
    fprintf(stdout, "TREE SHOULD BE EMPTY\n\tTREE: ");
    printTree(tester, INORDER);
    fprintf(stdout, "IS IT EMPTY? %d -> should be 1, SIZE: %d\n", isEmpty(tester), treeSize(tester));
    fprintf(stdout, "\n");

    freeTree(tester);
    fprintf(stdout, "\nALL TESTCASES PASSED SUCCESSFULLY.\n");
    fflush(stdout);

    return 0;
}