/* My set Testing */

#include "set.h"

int main(void){

    /*  INITIALIZE SET OBJECT  */
    MySet* tester = newSet();

    /*  WARNING! TESTER SHOULD NEVER CONTAIN REPEATED NUMBERS  */
    printf("\nMAKE SURE TESTER DOES NOT CONTAIN REPEATED NUMBERS\n\n");
    fflush(stdout);

    /*  TEST ADDING TO SET  */
    for (int i = 0; i<10; ++i)
        addTo(tester, 5);
    printf("SET SHOULD ONLY CONTAIN ONE 5\n\tSET: ");
    printSet(tester);
    printf("\n");

    /*  TEST REMOVING ELEMENTS AND SIZE  */
    for (int i = 0; i<6; ++i)
        addTo(tester, 3*i);
    removeFrom(tester, 5);
    printf("SET SHOULD NOT CONTAIN THE NUMBER 5, AND SIZE SHOULD BE 6\n\tSET: ");
    printSet(tester);
    printf("\tSET SIZE: %d\n", setSize(tester));
    printf("\n");
    fflush(stdout);

    /*  TEST ELEM EXISTS  */
    printf("SHOULD RETURN 001001\n\tRETURNS: ");
    for (int i = 1; i<=6; ++i)
        printf("%d", exists(tester, 2*i));
    printf("\n");
    fflush(stdout);

    printf("\nALL TESTS COMPLETED SUCCESSFULLY.\n");
    fflush(stdout);
    
    freeSet(tester);

    return 0;
}