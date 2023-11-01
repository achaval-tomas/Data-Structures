/* My set Testing */

#include "set.h"

int main(void){

    /*  INITIALIZE SET OBJECT  */
    MySet* tester = newSet();

    /*  WARNING! TESTER SHOULD NEVER CONTAIN REPEATED NUMBERS  */
    fprintf(stdout, "\nMAKE SURE TESTER DOES NOT CONTAIN REPEATED NUMBERS\n\n");
    fflush(stdout);

    /*  TEST ADDING TO SET  */
    for (int i = 0; i<10; ++i)
        addTo(tester, 5);
    fprintf(stdout, "SET SHOULD ONLY CONTAIN ONE 5\n\tSET: ");
    printSet(tester);
    fprintf(stdout, "\n");

    /*  TEST REMOVING ELEMENTS AND SIZE  */
    for (int i = 0; i<6; ++i)
        addTo(tester, 3*i);
    removeFrom(tester, 5);
    fprintf(stdout, "SET SHOULD NOT CONTAIN THE NUMBER 5, AND SIZE SHOULD BE 6\n\tSET: ");
    printSet(tester);
    fprintf(stdout, "\tSET SIZE: %d\n", setSize(tester));
    fprintf(stdout, "\n");
    fflush(stdout);

    /*  TEST ELEM EXISTS  */
    fprintf(stdout, "SHOULD RETURN 001001\n\tRETURNS: ");
    for (int i = 1; i<=6; ++i)
        fprintf(stdout, "%d", exists(tester, 2*i));
    fprintf(stdout, "\n");
    fflush(stdout);

    fprintf(stdout, "\nALL TESTS COMPLETED SUCCESSFULLY.\n");
    fflush(stdout);
    
    freeSet(tester);

    return 0;
}