/* My Array Specification */
#ifndef ARRAY_HEADER
#define ARRAY_HEADER

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_array MyArray;

/*  INIT ARRAY OBJECT  */
MyArray* init();

/*  RESIZE ARRAY TO newSize  */
void resize(MyArray* arr, int newSize);

/*  RETURNS CURRENT ELEM COUNT OF ARRAY  */
int arraySize(MyArray* arr);

/*  SETS EVERY ELEMENT IN THE ARRAY TO 0  */
void setZeroes(MyArray* arr);

/*  ADDS ELEMENT elem TO EVERY INDEX IN RANGE [start, end) */
void setInRange(MyArray* arr, int start, int end, int elem);

/*  SWAPS ELEM AT INDEX i WITH ELEM AT INDEX j  */
void swap(MyArray* arr, int i, int j);

/*  REPLACES ELEM AT INDEX i WITH elem  */
void replaceAtIndex(MyArray* arr, int i, int elem);

/*  REMOVES ELEMENT AT INDEX i  */
void removeAtIndex(MyArray* arr, int i);

/*  REMOVES ALL INSTANCES OF elem IN ARRAY  */
void removeMatches(MyArray* arr, int elem);

/*  FREES ALL SPACE USED BY ARRAY  */
void freeArray(MyArray* arr);

/*  PRINTS ARRAY TO STDOUT  */
void printArray(MyArray* arr);

/*  Quick Sort the array
 *
 *  cmp should return true if a GOES BEFORE b
 *  Generally, O(nlog(n)) worst case O(n^2)
 *
 */
void quickSort(MyArray* arr, bool cmp(int a, int b));

#endif /* ARRAY_HEADER */