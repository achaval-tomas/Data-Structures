#include "doubly-linked-list.h"
#include <stdio.h>

int main()
{
    MyDoublyLinkedList* tester = createDList();

    printf("List should have nothing:\n");
    printDList(tester);

    tester = dListAddElem(tester, 17);
    tester = dListAddElem(tester, -2);
    printf("List should be [-2 , 17]:\n");
    printDList(tester);

    printf("List size: %d\n", dListSize(tester));

    tester = dListAddElemAtIndex(tester, 33, 1);
    printf("List should be [-2 , 33 , 17]:\n");
    printDList(tester);

    tester = dListRemoveElemByValue(tester, 33);
    printf("List should be [-2 , 17]:\n");
    printDList(tester);

    tester = dListAddElem(tester, 33);
    tester = dListAddElem(tester, 100);
    printf("List should be [100, 33 , -2 , 17]:\n");
    printDList(tester);

    tester = dListRemoveElemByIndex(tester, 3);
    printf("List should be [100 , 33, -2]:\n");
    printDList(tester);

    freeDList(tester);
}
