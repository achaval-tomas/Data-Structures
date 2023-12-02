/*
 * My implementation for linked lists.
 */
#include "doubly-linked-list.h"
#include <stdlib.h>
#include <assert.h>

struct s_dllist {
    int val;
    MyDoublyLinkedList *next;
    MyDoublyLinkedList *prev;
};

/* Initializes list object */
MyDoublyLinkedList* createList(){
    return (MyDoublyLinkedList*)NULL;
}

/* Returns the amount of elements in the list */
int listSize(MyDoublyLinkedList* obj){
    return (obj == NULL) ? 0 : 1 + listSize(obj->next);
}

/* Adds element elem to the list */
MyDoublyLinkedList* addElem(MyDoublyLinkedList* obj, int elem){
    MyDoublyLinkedList* node = (MyDoublyLinkedList*)malloc(sizeof(*node));

    node->val = elem;
    node->next = (MyDoublyLinkedList*)obj;

    if (obj)
        obj->prev = node;

    return node;
}

/* Adds element elem at index position (0-indexed) of the list (if valid) */
MyDoublyLinkedList* addElemAtIndex(MyDoublyLinkedList* obj, int elem, int index){
    int size = listSize(obj);
    if (index<0 || index>size) {
        printf("\nINVALID INDEX.\n");
        return obj;
    }
    if (index == 0)
        return addElem(obj, elem);

    MyDoublyLinkedList* ret = obj;
    for (int i = 0; i<index-1 && obj->next; ++i)
        obj = obj->next;

    MyDoublyLinkedList* node = malloc(sizeof(*node));
    node->val = elem;
    node->next = obj->next;
    node->prev = obj;
    obj->next = node;

    return ret;
}

/* Removes all elements matching value */
MyDoublyLinkedList* removeElemByValue(MyDoublyLinkedList* obj, int value){
    if (!obj){
        printf("\nNOTHING TO REMOVE.\n");
        return obj;
    }

    MyDoublyLinkedList* ret = obj;

    while (ret && ret->val == value) {
        MyDoublyLinkedList* killme = ret;

        ret = ret->next;

        free(killme);
    }

    if (!ret)
        return NULL;

    ret->prev = NULL;

    obj = ret->next;

    while (obj) {
        if (obj->val == value) {
            MyDoublyLinkedList* killme = obj;

            if (obj->prev)
                obj->prev->next = obj->next;

            if (obj->next)
                obj->next->prev = obj->prev;

            obj = obj->next;
            free(killme);
        } else {
            obj = obj->next;
        }
    }

    return ret;    
}

/* Removes element at position index (0-indexed) */
MyDoublyLinkedList* removeElemByIndex(MyDoublyLinkedList* obj, int index){
    if (index<0 || index>=listSize(obj)) {
        printf("\nINVALID INDEX.\n");
        return obj;
    }

    if (!index) {
        MyDoublyLinkedList* killme = obj;
        obj = obj->next;
        free(killme);
        
        return obj;
    }

    MyDoublyLinkedList* iter = obj;

    for (unsigned int i = 0; i < index; ++i) {
        iter = iter->next;
    }

    if (iter->prev)
        iter->prev->next = iter->next;

    if (iter->next)
        iter->next->prev = iter->prev;

    free(iter);

    return obj;
}

/* Adds all elements in group to the list */
MyDoublyLinkedList* addElemGroup(MyDoublyLinkedList* obj, int *group, int groupSize){
    MyDoublyLinkedList* ret = obj;
    for (int i = 0; i<groupSize; ++i)
        ret = addElem(ret, group[i]);
    return ret;
}

/* Removes all matches from each element in group */
MyDoublyLinkedList* removeGroup(MyDoublyLinkedList* obj, int *group, int groupSize){
    if (!obj) {
        printf("\nNOTHING TO REMOVE.\n");
        return obj;
    }
    MyDoublyLinkedList* ret = obj;
    for (int i = 0; i<groupSize; ++i)
        ret = removeElemByValue(ret, group[i]);
    return ret;
}

/* Returns a boolean value indicating whether the element is in the list */
bool elemExists(MyDoublyLinkedList* obj, int elem){
    while (obj != NULL){
        if(obj->val == elem)
            return true;
        obj = obj->next;
    }
    return false;
}

/* Returns the element at position index (0-indexed) */
int elemAtIndex(MyDoublyLinkedList* obj, int index){
    int size = listSize(obj);
    if (index<0 || index>=size) {
        printf("\nINVALID INDEX.\n");
        return 0;
    }
    for (int i = 0; i<index; ++i)
        obj = obj->next;
    return obj->val;
}

/* Frees all space used by the list, returns NULL if successfull */
void* freeList(MyDoublyLinkedList* obj){
    while (obj != NULL)
        obj = removeElemByIndex(obj, 0);
    assert(listSize(obj) == 0);
    return NULL;
}

/* Prints the linked list to STDOUT */
void printList(MyDoublyLinkedList* obj){
    printf("head ->");
    while (obj != NULL){
        printf(" %d ->", obj->val);
        obj = obj->next;
    }
    printf(" end\n");
    fflush(stdout);
}
