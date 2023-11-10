/*
 * My implementation for linked lists.
 */
#include "linked-list.h"
#include <stdlib.h>
#include <assert.h>

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
    if (index<0 || index>size) {
        printf("\nINVALID INDEX.\n");
        return obj;
    }
    if (index == 0)
        return addElem(obj, elem);

    MyLinkedList* ret = obj;
    for (int i = 0; i<index-1 && obj->next; ++i)
        obj = obj->next;

    MyLinkedList* node = malloc(sizeof(*node));
    node->val = elem;
    node->next = obj->next;
    obj->next = node;

    return ret;
}

/* Removes all elements matching value */
MyLinkedList* removeElemByValue(MyLinkedList* obj, int value){
    if (!obj){
        printf("\nNOTHING TO REMOVE.\n");
        return obj;
    }
    MyLinkedList* ret = obj;
    while (ret && ret->val == value){
        MyLinkedList *killme = ret;
        ret = ret->next;
        free(killme);
    }
    obj = ret;
    while (obj && obj->next){
        while (obj && obj->next && obj->next->val == value){
            MyLinkedList* killme = obj->next;
            obj->next = obj->next->next;
            free(killme);
        }
        obj = obj->next;
    }
    return ret;
}

/* Removes element at position index (0-indexed) */
MyLinkedList* removeElemByIndex(MyLinkedList* obj, int index){
    if (index<0 || index>=listSize(obj)) {
        printf("\nINVALID INDEX.\n");
        return obj;
    }
    if (index == 0){
        MyLinkedList * ret = obj->next;
        free(obj);
        return ret;
    } else {
        MyLinkedList* node = obj;
        for (int i = 0; i<index-1 && node != NULL;++i){
            node = node->next;
        }
        MyLinkedList* killme = node->next;
        node->next = node->next ? node->next->next : NULL;
        free(killme);
    }
    return obj;
}

/* Adds all elements in group to the list */
MyLinkedList* addElemGroup(MyLinkedList* obj, int *group, int groupSize){
    MyLinkedList* ret = obj;
    for (int i = 0; i<groupSize; ++i)
        ret = addElem(ret, group[i]);
    return ret;
}

/* Removes all matches from each element in group */
MyLinkedList* removeGroup(MyLinkedList* obj, int *group, int groupSize){
    if (!obj) {
        printf("\nNOTHING TO REMOVE.\n");
        return obj;
    }
    MyLinkedList* ret = obj;
    for (int i = 0; i<groupSize; ++i)
        ret = removeElemByValue(ret, group[i]);
    return ret;
}

/* Returns a boolean value indicating whether the element is in the list */
bool elemExists(MyLinkedList* obj, int elem){
    while (obj != NULL){
        if(obj->val == elem)
            return true;
        obj = obj->next;
    }
    return false;
}

/* Returns the element at position index (0-indexed) */
int elemAtIndex(MyLinkedList* obj, int index){
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
void* freeList(MyLinkedList* obj){
    while (obj != NULL)
        obj = removeElemByIndex(obj, 0);
    assert(listSize(obj) == 0);
    return NULL;
}

/* Prints the linked list to STDOUT */
void printList(MyLinkedList* obj){
    printf("head ->");
    while (obj != NULL){
        printf(" %d ->", obj->val);
        obj = obj->next;
    }
    printf(" end\n");
    fflush(stdout);
}
