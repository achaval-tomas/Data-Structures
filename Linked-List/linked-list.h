/*
 *  My specification for linked lists.
 *  More functions might be added over time.
 */
#ifndef LIST_HEADER
#define LIST_HEADER

#include <stdbool.h>
#include <stdio.h>

typedef struct s_llist MyLinkedList;

/* Initializes list object */
MyLinkedList* createList();

/* Returns the amount of elements in the list */
int listSize(MyLinkedList* obj);

/* Adds element elem to the list */
void addElem(MyLinkedList* obj, int elem);

/* Adds element elem at index position (0-indexed) of the list (if valid) */
void addElemAtIndex(MyLinkedList* obj, int elem, int index);

/* Removes all elements matching value */
void removeElemByValue(MyLinkedList* obj, int value);

/* Removes element at position index (0-indexed) */
void removeElemByIndex(MyLinkedList* obj, int index);

/* Adds all elements in group to the list */
void addElemGroup(MyLinkedList* obj, int *group, int groupSize);

/* Removes all matches from each element in group */
void removeGroup(MyLinkedList* obj, int *group, int groupSize);

/* Returns a boolean value indicating whether the element is in the list */
bool elemExists(MyLinkedList* obj, int elem);

/* Returns the element at position index (0-indexed) */
int elemAtIndex(MyLinkedList* obj, int index);

/* Frees all space used by the list, returns NULL if successfull */
void* freeList(MyLinkedList* obj);

#endif /* LIST_HEADER */