/*
 *  My specification for doubly linked lists.
 *  More functions might be added over time.
 */
#ifndef DOUBLY_LIST_HEADER
#define DOUBLY_LIST_HEADER

#include <stdbool.h>
#include <stdio.h>

typedef struct s_dllist MyDoublyLinkedList;

/* Initializes list object */
MyDoublyLinkedList* createDList();

/* Returns the amount of elements in the list */
int dListSize(MyDoublyLinkedList* obj);

/* Adds element elem to the list */
MyDoublyLinkedList* dListAddElem(MyDoublyLinkedList* obj, int elem);

/* Adds element elem at index position (0-indexed) of the list (if valid) */
MyDoublyLinkedList* dListAddElemAtIndex(MyDoublyLinkedList* obj, int elem, int index);

/* Removes all elements matching value */
MyDoublyLinkedList* dListRemoveElemByValue(MyDoublyLinkedList* obj, int value);

/* Removes element at position index (0-indexed) */
MyDoublyLinkedList* dListRemoveElemByIndex(MyDoublyLinkedList* obj, int index);

/* Adds all elements in group to the list */
MyDoublyLinkedList* dListAddElemGroup(MyDoublyLinkedList* obj, int* group, int groupSize);

/* Removes all matches from each element in group */
MyDoublyLinkedList* dListRemoveGroup(MyDoublyLinkedList* obj, int* group, int groupSize);

/* Returns a boolean value indicating whether the element is in the list */
bool dListElemExists(MyDoublyLinkedList* obj, int elem);

/* Returns a 2-element array of left and right neighbors at index 0 and 1 respectively
 * Returned array must be freed by the caller.
 */
int* dListGetNeighbors(MyDoublyLinkedList* obj, int elem);

/* Returns the element at position index (0-indexed) */
int dListElemAtIndex(MyDoublyLinkedList* obj, int index);

/* Frees all space used by the list, returns NULL if successfull */
void* freeDList(MyDoublyLinkedList* obj);

/* Prints the linked list to STDOUT */
void printDList(MyDoublyLinkedList* obj);

#endif /* DOUBLY_LIST_HEADER */
