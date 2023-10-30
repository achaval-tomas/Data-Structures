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
MyLinkedList* addElem(MyLinkedList* obj, int elem){
    MyLinkedList* node = (MyLinkedList*)malloc(sizeof(*node));
    node->val = elem;
    node->next = (MyLinkedList*)obj;
    return node;
}

/* Adds element elem at index position (0-indexed) of the list (if valid) */
MyLinkedList* addElemAtIndex(MyLinkedList* obj, int elem, int index){
    int size = listSize(obj);
    if (index < 0 || index > size)
        return obj;

    MyLinkedList* ret = obj;
    for (int i = 0; i<index-1; ++i)
        obj = obj->next;

    MyLinkedList* node = (MyLinkedList*)malloc(sizeof(*node));
    node->val = elem;
    node->next = (MyLinkedList*)(index == 0 ? obj : obj->next);
    obj->next = index == 0 ? obj->next : node;

    return (index == 0) ? node : ret;
}

/* Removes all elements matching value */
void removeElemByValue(MyLinkedList* obj, int value){
    int size = listSize(obj);
    // TO-DO
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
