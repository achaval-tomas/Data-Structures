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
MyDoublyLinkedList* createList();

/* Returns the amount of elements in the list */
int listSize(MyDoublyLinkedList* obj);

/* Adds element elem to the list */
MyDoublyLinkedList* addElem(MyDoublyLinkedList* obj, int elem);

/* Adds element elem at index position (0-indexed) of the list (if valid) */
MyDoublyLinkedList* addElemAtIndex(MyDoublyLinkedList* obj, int elem, int index);

/* Removes all elements matching value */
MyDoublyLinkedList* removeElemByValue(MyDoublyLinkedList* obj, int value);

/* Removes element at position index (0-indexed) */
MyDoublyLinkedList* removeElemByIndex(MyDoublyLinkedList* obj, int index);

/* Adds all elements in group to the list */
MyDoublyLinkedList* addElemGroup(MyDoublyLinkedList* obj, int *group, int groupSize);

/* Removes all matches from each element in group */
MyDoublyLinkedList* removeGroup(MyDoublyLinkedList* obj, int *group, int groupSize);

/* Returns a boolean value indicating whether the element is in the list */
bool elemExists(MyDoublyLinkedList* obj, int elem);

/* Returns the element at position index (0-indexed) */
int elemAtIndex(MyDoublyLinkedList* obj, int index);

/* Frees all space used by the list, returns NULL if successfull */
void* freeList(MyDoublyLinkedList* obj);

/* Prints the linked list to STDOUT */
void printList(MyDoublyLinkedList* obj);

#endif /* DOUBLY_LIST_HEADER */
