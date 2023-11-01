/* My set Specification */

#ifndef SET_HEADER
#define SET_HEADER

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct s_set MySet;

/*  CREATE A NEW EMPTY SET  */
MySet* newSet(void);

/*  RETURNS THE AMOUNT OF ELEMENTS IN THE SET  */
unsigned int setSize(MySet* set);

/*  ADD ELEMENT TO THE SET  */
void addTo(MySet* set, int elem);

/*  REMOVE ELEMENT FROM THE SET  */
void removeFrom(MySet* set, int elem);

/*  CHECK IF elem EXISTS IN THE SET  */
bool exists(MySet* set, int elem);

/*  FREE ALL SPACE USED BY SET  */
void freeSet(MySet* set);

/*  PRINT THE SET TO stdout  */
void printSet(MySet* set);


#endif /* SET_HEADER */