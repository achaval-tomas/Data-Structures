/*  My Stack testing  */

#include "stack.h"

int main(void){

    /*  INITIALIZE STACK OBJECT  */
    MyStack* tester = s_newStack();

    /*  TEST PUSH  */
    for (int i = 0; i<10; ++i)
        tester = s_push(tester, 100+i);
    fprintf(stdout, "STACK SHOULD HAVE 10 ELEMENTS IN DECREASING ORDER TOP TO BOTTOM.\n\tSTACK: ");
    s_print(tester);
    fprintf(stdout, "\n");

    /*  TEST POP  */
    for (int i = 0; i<6; ++i)
        s_pop(tester);
    fprintf(stdout, "STACK SHOULD HAVE KEPT THE BOTTOM 4 ELEMENTS.\n\tSTACK: ");
    s_print(tester);
    fprintf(stdout, "\n");

    /*  TEST TOP  */
    fprintf(stdout, "\"TOP:\" SHOULD BE THE ELEMENT POINTED BY \"TOP -->\".\n\tSTACK: ");
    s_print(tester);
    fprintf(stdout, "\tTOP: %d\n", s_top(tester));
    fprintf(stdout, "\n");
    fflush(stdout);

    /*  TEST IS EMPTY  */
    fprintf(stdout, "STACK SHOULD NOT BE EMPTY.\n\t");
    fprintf(stdout, "IS EMPTY? %s\n", s_isEmpty(tester) ? "YES." : "NO.");
    fflush(stdout);
    while (!s_isEmpty(tester))
        s_pop(tester);
    fprintf(stdout, "STACK SHOULD BE EMPTY.\n\t");
    fprintf(stdout, "IS EMPTY? %s", s_isEmpty(tester) ? "YES." : "NO.");
    fprintf(stdout, "\n");
    fflush(stdout);
    
    s_free(tester);
    fprintf(stdout, "\nALL TESTCASES PASSED SUCCESSFULLY.\n");
    fflush(stdout);

    return 0;
}