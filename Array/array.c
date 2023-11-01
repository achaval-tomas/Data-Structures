/* My Array Implementation */

#include "array.h"
#include <assert.h>

struct s_array {
    int* array;
    int size;
};

/*  INIT ARRAY OBJECT  */
MyArray* init(){
    MyArray* arr = malloc(sizeof(MyArray*));
    arr->size = 0;
    arr->array = NULL;
    return arr;
}

/*  RESIZE ARRAY TO newSize  */
void resize(MyArray* arr, int newSize){
    arr->size = newSize;
    arr->array = realloc((arr->array), newSize*sizeof(MyArray*));
}

/*  RETURNS CURRENT ELEM COUNT OF ARRAY  */
int arraySize(MyArray* arr){
    return arr->size;
}

/*  SETS EVERY ELEMENT IN THE ARRAY TO 0  */
void setZeroes(MyArray* arr){
    int size = arraySize(arr);
    for (int i = 0; i<size; ++i)
        (arr->array)[i] = 0;
}

/*  ADDS ELEMENT elem TO EVERY INDEX IN RANGE [start, end) */
void setInRange(MyArray* arr, int start, int end, int elem){
    assert(start >= 0);
    if (end > arraySize(arr))
        resize(arr, end);
    for (int i = start; i<end; ++i)
        (arr->array)[i] = elem;
}

/*  SWAPS ELEM AT INDEX i WITH ELEM AT INDEX j  */
void swap(MyArray* arr, int i, int j){
    int size = arraySize(arr);
    assert(0<=i && i<size && 0<=j && j<size);
    int aux = (arr->array)[i];
    (arr->array)[i] = (arr->array)[j];
    (arr->array)[j] = aux;
}

/*  REPLACES ELEM AT INDEX i WITH elem  */
void replaceAtIndex(MyArray* arr, int i, int elem){
    (arr->array)[i] = elem;
}

void removeAtIndex(MyArray* arr, int idx){
    int size = arraySize(arr);
    for (int i = idx; i<size-1; ++i)
        (arr->array)[i] = (arr->array)[i+1];
    resize(arr, size-1);
}

/*  REMOVES ALL INSTANCES OF elem IN ARRAY  */
void removeMatches(MyArray* arr, int elem){
    for (int i = 0; i<arr->size; ++i){
        if ((arr->array)[i] == elem)
            removeAtIndex(arr, i--);
    }
}

/*  FREES ALL SPACE USED BY ARRAY  */
void freeArray(MyArray* arr){
    free(arr->array);
    free(arr);
}

/*  PRINTS ARRAY TO STDOUT  */
void printArray(MyArray* arr){
    int size = arr->size;
    fprintf(stdout, "[ ");
    for (int i = 0; i<size; ++i)
        fprintf(stdout, "%d ", (arr->array)[i]);
    fprintf(stdout, "]\n");
    fflush(stdout);
}