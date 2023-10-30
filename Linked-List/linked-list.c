/*
 * My implementation for linked lists.
 */
#include "linked-list.h"

struct s_llist {
    int val;
    MyLinkedList *next;
};

/* Initializes list object */
MyLinkedList* createList(){
    return (MyLinkedList*)NULL;
}

/* Returns the amount of elements in the list */
int listSize(MyLinkedList* obj){
    return (obj == NULL) ? 0 : 1 + listSize(obj->next);
}

/* Adds element elem to the list */
void addElem(MyLinkedList* obj, int elem){

}

/* Adds element elem at index position (0-indexed) of the list (if valid) */
void addElemAtIndex(MyLinkedList* obj, int elem, int index){

}

/* Removes all elements matching value */
void removeElemByValue(MyLinkedList* obj, int value){

}

/* Removes element at position index (0-indexed) */
void removeElemByIndex(MyLinkedList* obj, int index){

}

/* Adds all elements in group to the list */
void addElemGroup(MyLinkedList* obj, int *group, int groupSize){

}

/* Removes all matches from each element in group */
void removeGroup(MyLinkedList* obj, int *group, int groupSize){

}

/* Returns a boolean value indicating whether the element is in the list */
bool elemExists(MyLinkedList* obj, int elem){
    return false;
}

/* Returns the element at position index (0-indexed) */
int elemAtIndex(MyLinkedList* obj, int index){
    return 0;
}

/* Frees all space used by the list, returns NULL if successfull */
void* freeList(MyLinkedList* obj){
    return NULL;
}
