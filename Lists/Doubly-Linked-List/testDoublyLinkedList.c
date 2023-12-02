#include <stdio.h>
#include "doubly-linked-list.h"

int main() {
    MyDoublyLinkedList* tester = createList();

    printf("List should have nothing:\n");
    printList(tester);

    tester = addElem(tester, 17);
    tester = addElem(tester, -2);
    printf("List should be [-2 , 17]:\n");
    printList(tester);

    printf("List size: %d\n", listSize(tester));

    tester = addElemAtIndex(tester, 33, 1);
    printf("List should be [-2 , 33 , 17]:\n");
    printList(tester);

    tester = removeElemByValue(tester, 33);
    printf("List should be [-2 , 17]:\n");
    printList(tester);

    tester = addElem(tester, 33);
    tester = addElem(tester, 100);
    printf("List should be [100, 33 , -2 , 17]:\n");
    printList(tester);

    tester = removeElemByIndex(tester, 3);
    printf("List should be [100 , 33, -2]:\n");
    printList(tester);

    freeList(tester);
}
