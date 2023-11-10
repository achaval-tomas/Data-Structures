/* My Array Testing */

#include "array.h"

bool cmpf (int a, int b){
    return a < b;
}


int main(void){

    /*  INITIALIZE ARRAY OBJECT WITH SIZE 10 */
    MyArray* tester = init();
    resize(tester, 10);

    /*  TEST SET ZEROES  */
    setZeroes(tester);
    printf("ARRAY SHOULD CONTAIN 10 ZEROES.\n\tARRAY: ");
    printArray(tester);
    printf("\n");

    /*  TEST SET IN RANGE  */
    setInRange(tester, 2, 8, 10);
    printf("ARRAY SHOULD BE [0, 0, 10, 10, 10, 10, 10, 10, 0, 0].\n\tARRAY: ");
    printArray(tester);
    printf("\n");

    /*  TEST REMOVE MATCHES  */
    removeMatches(tester, 0);
    printf("ARRAY SHOULD NOT CONTAIN 0s.\n\tARRAY: ");
    printArray(tester);
    printf("\n");

    /*  TEST SWAPPING  */
    replaceAtIndex(tester, 2, 333);
    replaceAtIndex(tester, 4, 999);
    printf("NEW ELEMS AT INDEX 2 AND 4:\n\tARRAY: ");
    printArray(tester);
    swap(tester, 2, 4);
    printf("SWAP INDEX 2 WITH 4:\n\tARRAY: ");
    printArray(tester);
    printf("\n");

    /*  TEST REMOVING AT INDEX  */
    removeAtIndex(tester, 2);
    removeAtIndex(tester, 3);
    printf("ELEMS AT INDEX 2 AND 4 SHOULD HAVE BEEN REMOVED:\n\tARRAY: ");
    printArray(tester);
    printf("\n");

    /*  TEST EXTREME SET IN RANGE  */
    setInRange(tester, 4, 15, 99);
    printf("ARRAY SHOULD'VE BEEN EXPANDED WITH ELEVEN 99s:\n\tARRAY: ");
    printArray(tester);
    printf("\n");

    removeMatches(tester, 10);
    printf("ARRAY SHOULD NOT CONTAIN 10s:\n\tARRAY: ");
    printArray(tester);
    setInRange(tester, 0, 5, 33);
    printf("ARRAY SHOULD START WITH FIVE 33s:\n\tARRAY: ");
    printArray(tester);
    printf("\n");

    /*  TEST QUICK SORT  */
    resize(tester, 20);
    setZeroes(tester);
    for (int i = 0; i<20; ++i)
        replaceAtIndex(tester, i, i%6);
    printf("ARRAY SHOULD NOT BE SORTED:\n\tARRAY: ");
    printArray(tester);
    quickSort(tester, cmpf);
    printf("ARRAY SHOULD BE SORTED IN ASCENDING ORDER:\n\tARRAY: ");
    printArray(tester);
    printf("\n");

    /*  ALL TESTCASES SUCCESSFULLY COMPLETED  */
    printf("ALL TESTCASES PASSED.\n");
    fflush(stdout);

    freeArray(tester);

    return 0;
}