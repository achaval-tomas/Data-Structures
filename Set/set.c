/* My set Implementation */

#include "set.h"

struct s_set {
    int* elements;
    unsigned int size;
};

/*  CREATE A NEW EMPTY SET  */
MySet* newSet(void)
{
    MySet* s = malloc(sizeof(*s));
    s->size = 0;
    s->elements = NULL;
    return s;
}

/*  RETURNS THE AMOUNT OF ELEMENTS IN THE SET  */
unsigned int setSize(MySet* set)
{
    return set->size;
}

/*  ADD ELEMENT TO THE SET  */
void addTo(MySet* set, int elem)
{
    if (!exists(set, elem)) {
        set->elements = realloc(set->elements, (++set->size) * sizeof(int));
        (set->elements)[set->size - 1] = elem;
    }
}

/*  REMOVE ELEMENT FROM THE SET  */
void removeFrom(MySet* set, int elem)
{
    char found = 0;
    for (unsigned int i = 0; i < set->size; ++i) {
        if (!found) {
            found = found || ((set->elements)[i] == elem);
        } else {
            (set->elements)[i - 1] = (set->elements)[i];
        }
    }
    if (found)
        set->elements = realloc(set->elements, (--set->size) * sizeof(int));
}

/*  CHECK IF elem EXISTS IN THE SET  */
bool exists(MySet* set, int elem)
{
    for (unsigned int i = 0; i < set->size; ++i) {
        if ((set->elements)[i] == elem)
            return true;
    }
    return false;
}

/*  FREE ALL SPACE USED BY SET  */
void freeSet(MySet* set)
{
    free(set->elements);
    free(set);
}

/*  PRINT THE SET TO stdout  */
void printSet(MySet* set)
{
    printf("{ ");
    for (unsigned int i = 0; i < set->size; ++i)
        printf("%d ", (set->elements)[i]);
    printf("}\n");
    fflush(stdout);
}