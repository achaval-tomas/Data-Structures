/* My Array Testing */

#include "array.h"

int main(void){

    /*  INITIALIZE ARRAY OBJECT WITH SIZE 10 */
    MyArray* tester = init();
    resize(tester, 10);

    /*  TEST SET ZEROES  */
    setZeroes(tester);
    fprintf(stdout, "ARRAY SHOULD CONTAIN 10 ZEROES.\n\tARRAY: ");
    printArray(tester);
    fprintf(stdout, "\n");

    /*  TEST SET IN RANGE  */
    setInRange(tester, 2, 8, 10);
    fprintf(stdout, "ARRAY SHOULD BE [0, 0, 10, 10, 10, 10, 10, 10, 0, 0].\n\tARRAY: ");
    printArray(tester);
    fprintf(stdout, "\n");

    /*  TEST REMOVE MATCHES  */
    removeMatches(tester, 0);
    fprintf(stdout, "ARRAY SHOULD NOT CONTAIN 0s.\n\tARRAY: ");
    printArray(tester);
    fprintf(stdout, "\n");

    /*  TEST SWAPPING  */
    replaceAtIndex(tester, 2, 333);
    replaceAtIndex(tester, 4, 999);
    fprintf(stdout, "NEW ELEMS AT INDEX 2 AND 4:\n\t");
    printArray(tester);
    swap(tester, 2, 4);
    fprintf(stdout, "SWAP INDEX 2 WITH 4:\n\t");
    printArray(tester);
    fprintf(stdout, "\n");

    /*  TEST REMOVING AT INDEX  */
    removeAtIndex(tester, 2);
    removeAtIndex(tester, 3);
    fprintf(stdout, "ELEMS AT INDEX 2 AND 4 SHOULD HAVE BEEN REMOVED:\n\t");
    printArray(tester);
    fprintf(stdout, "\n");

    /*  TEST EXTREME SET IN RANGE  */
    setInRange(tester, 4, 15, 99);
    fprintf(stdout, "ARRAY SHOULD'VE BEEN EXPANDED WITH ELEVEN 99s:\n\t");
    printArray(tester);
    fprintf(stdout, "\n");

    removeMatches(tester, 10);
    fprintf(stdout, "ARRAY SHOULD NOT CONTAIN 10s:\n\t");
    printArray(tester);
    setInRange(tester, 0, 5, 33);
    fprintf(stdout, "ARRAY SHOULD START WITH FIVE 33s:\n\t");
    printArray(tester);
    fprintf(stdout, "\n");

    /*  ALL TESTCASES SUCCESSFULLY COMPLETED  */
    fprintf(stdout, "ALL TESTCASES PASSED.\n");
    fflush(stdout);

    freeArray(tester);

    return 0;
}