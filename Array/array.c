/* My Array Implementation */

#include "array.h"
#include <assert.h>

struct s_array {
    int* array;
    int size;
};

/*  INIT ARRAY OBJECT  */
MyArray* init(){
    MyArray* arr = malloc(sizeof(*arr));
    arr->size = 0;
    arr->array = NULL;
    return arr;
}

/*  RESIZE ARRAY TO newSize  */
void resize(MyArray* arr, int newSize){
    int len = arr->size;
    arr->size = newSize;
    arr->array = realloc((arr->array), newSize*sizeof(*(arr->array)));
    if (len < newSize)
        setInRange(arr, len, newSize, 0); // If array increased in size, set new places to 0.
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
    if (i<0 || i>=size || j<0 || j>=size){
        printf("\nINVALID INDEX.\n");
        return;
    }
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
    if (idx < 0 || idx >= size){
        printf("\nINVALID INDEX.\n");
        return;
    }
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
    printf("[ ");
    for (int i = 0; i<size; ++i)
        printf("%d ", (arr->array)[i]);
    printf("]\n");
    fflush(stdout);
}

/*  AUXILIARY FUNCTION FOR QUICK SORT  */
void swapArr(int* arr, int i, int j){
    int aux = arr[i];
    arr[i] = arr[j];
    arr[j] = aux;
}


/*  AUXILIARY FUNCTION FOR QUICK SORT  */
int partition(int* arr, int lft, int rgt, bool cmp (int a, int b)){
    int piv = lft;
    int pive = arr[piv];
    for (int i = lft+1; i<rgt;++i){
        if (cmp(arr[i], pive)){
            piv++;
            swapArr(arr, i, piv);
        }
    }
    swapArr(arr, lft, piv);
    return piv;
}

/*  AUXILIARY FUNCTION FOR QUICK SORT  */
void sort(int* arr, int lft, int rgt, bool cmp (int a, int b)){
    if (lft<rgt){
        int ppiv = partition(arr, lft, rgt, cmp);
        sort(arr, lft, ppiv, cmp);
        sort(arr, ppiv+1, rgt, cmp);
    }
}

/*  Quick Sort the array  */
void quickSort(MyArray* arr, bool cmp (int a, int b)){
    sort(arr->array, 0, arr->size, cmp);
}
