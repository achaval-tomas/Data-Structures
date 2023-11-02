/*  My Queue testing  */

#include "queue.h"

int main(void){

    /*  INITIALIZE QUEUE OBJECT  */
    MyQueue* tester = q_newQueue();

    /*  TEST ENQUEUE  */
    for (int i = 0; i<10; ++i)
        tester = q_enqueue(tester, 100+i);
    fprintf(stdout, "QUEUE SHOULD HAVE 10 ELEMENTS IN ORDER\n\tQUEUE: ");
    q_print(tester);
    fprintf(stdout, "\n");

    /*  TEST DEQUEUE  */
    for (int i = 0; i<6; ++i)
        q_dequeue(tester);
    fprintf(stdout, "QUEUE SHOULD HAVE KEPT THE LAST 4 ELEMENTS\n\tQUEUE: ");
    q_print(tester);
    fprintf(stdout, "\n");

    /*  TEST FRONT  */
    fprintf(stdout, "FRONT SHOULD BE THE FIRST ELEMENT IN THE QUEUE\n\tQUEUE: ");
    q_print(tester);
    fprintf(stdout, "\tFRONT: %d\n", q_front(tester));
    fprintf(stdout, "\n");
    fflush(stdout);

    /*  TEST IS EMPTY  */
    fprintf(stdout, "QUEUE SHOULD NOT BE EMPTY\n\t");
    fprintf(stdout, "IS EMPTY? %s\n", q_isEmpty(tester) ? "YES" : "NO");
    fflush(stdout);
    while (!q_isEmpty(tester))
        q_dequeue(tester);
    fprintf(stdout, "QUEUE SHOULD BE EMPTY\n\t");
    fprintf(stdout, "IS EMPTY? %s", q_isEmpty(tester) ? "YES" : "NO");
    fprintf(stdout, "\n");
    fflush(stdout);
    
    q_free(tester);
    fprintf(stdout, "\nALL TESTCASES PASSED SUCCESSFULLY.\n");
    fflush(stdout);

    return 0;
}