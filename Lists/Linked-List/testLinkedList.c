/* TO-DO, create main to test functions */
#include <stdio.h>
#include <stdlib.h>
#include "linked-list.h"

int main (void){

    /*  INITIALIZE TESTER LIST  */
    MyLinkedList* tester = createList();

    /*  TEST SINGLE ELEMENT ADDITION  */
    printf("TEST ADD ELEM:\n");
    tester = addElem(tester, 5);
    printList(tester);
    printf("\n");
    fflush(stdout);

    /*  TEST ADDING AT INDEX AND SIZE  */
    printf("TEST ADD AT INDEX:\n");
    for (int i = 0; i<5; ++i)
        tester = addElemAtIndex(tester, i, i);
    printf("Tester Size : %d (should be 6)\n", listSize(tester));
    printList(tester);
    printf("\n");
    fflush(stdout);

    /*  TEST REMOVING GROUP OF ELEMETNS  */
    printf("TEST REMOVING GROUP:\n");
    int* group = malloc(3*sizeof(*group));
    for (int i = 0; i<3; ++i)
        group[i] = i;
    tester = removeGroup(tester, group, 3);
    printf("Tester should be [3, 4, 5]\n\tTester: ");
    printList(tester);
    printf("\n");
    fflush(stdout);

    /*  TEST ADDING GROUP OF ELEMENTS  */
    printf("TEST ADDING GROUP:\n");
    tester = addElemGroup(tester, group, 3);
    printf("Tester should be [2, 1, 0, 3, 4, 5]\n\tTester: ");
    printList(tester);
    printf("\n");
    fflush(stdout);

    /*  TEST ELEM EXISTS  */
    printf("TEST ELEM EXISTS:\n exists(3): %d (should return 1)\n exists(7): %d (should return 0)\n", elemExists(tester, 3), elemExists(tester, 7));
    printf("\n");
    fflush(stdout);

    /*  TEST ELEM AT INDEX  */
    printf("TEST ELEM AT INDEX:\n");
    tester = addElemAtIndex(tester, 18, 6);
    tester = addElemAtIndex(tester, -1, 0);
    tester = addElemAtIndex(tester, 100, 3);
    printf("Tester should be [-1, 2, 1, 100, 0, 3, 4, 5, 18]\n\tTester: ");
    printList(tester);
    printf("\n");
    fflush(stdout);

    /*  TEST REMOVING AT INDEX  */
    printf("TEST REMOVE AT INDEX:\n");
    tester = removeElemByIndex(tester, 8);
    tester = removeElemByIndex(tester, 0);
    tester = removeElemByIndex(tester, 2);
    printf("Tester should be [ 2, 1, 0, 3, 4, 5 ]\n\tTester: ");
    printList(tester);
    printf("\n");
    fflush(stdout);

    /*  TEST REMOVING MANY INSTANCES OF ONE ELEMENT  */
    printf("TEST REMOVE ALL MATCHES:\n");
    tester = addElemAtIndex(tester, 111, 6);
    for (int i = 0; i<5; ++i)
        tester = addElem(tester, 111);

    printf("Tester SHOULD CONTAIN the number 111.\n\tTester: ");
    printList(tester);
    printf("\n");
    fflush(stdout);

    tester = removeElemByValue(tester, 111);
    printf("Tester SHOULD NOT CONTAIN the number 111.\n\tTester: ");
    printList(tester);
    printf("\n");
    fflush(stdout);

    /*  FREE ALL EXTRA MEMORY  */
    free(group);
    freeList(tester);

    return 0;
}