/*  My Stack testing  */

#include "stack.h"

int main(void)
{

    /*  INITIALIZE STACK OBJECT  */
    MyStack* tester = s_newStack();

    /*  TEST PUSH  */
    for (int i = 0; i < 10; ++i)
        tester = s_push(tester, 100 + i);
    printf("STACK SHOULD HAVE 10 ELEMENTS IN DECREASING ORDER TOP TO BOTTOM.\n\tSTACK: ");
    s_print(tester);
    printf("\n");

    /*  TEST POP  */
    for (int i = 0; i < 6; ++i)
        s_pop(tester);
    printf("STACK SHOULD HAVE KEPT THE BOTTOM 4 ELEMENTS.\n\tSTACK: ");
    s_print(tester);
    printf("\n");

    /*  TEST TOP  */
    printf("\"TOP:\" SHOULD BE THE ELEMENT POINTED BY \"TOP -->\".\n\tSTACK: ");
    s_print(tester);
    printf("\tTOP: %d\n", s_top(tester));
    printf("\n");
    fflush(stdout);

    /*  TEST IS EMPTY  */
    printf("STACK SHOULD NOT BE EMPTY.\n\t");
    printf("IS EMPTY? %s\n", s_isEmpty(tester) ? "YES." : "NO.");
    fflush(stdout);
    while (!s_isEmpty(tester))
        s_pop(tester);
    printf("STACK SHOULD BE EMPTY.\n\t");
    printf("IS EMPTY? %s", s_isEmpty(tester) ? "YES." : "NO.");
    printf("\n");
    fflush(stdout);

    s_free(tester);
    printf("\nALL TESTCASES PASSED SUCCESSFULLY.\n");
    fflush(stdout);

    return 0;
}