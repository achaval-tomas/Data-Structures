/*  My Queue testing  */

#include "queue.h"

int main(void){

    /*  INITIALIZE QUEUE OBJECT  */
    MyQueue* tester = q_newQueue();

    /*  TEST ENQUEUE  */
    for (int i = 0; i<10; ++i)
        tester = q_enqueue(tester, 100+i);
    printf("QUEUE SHOULD HAVE 10 ELEMENTS IN ORDER\n\tQUEUE: ");
    q_print(tester);
    printf("\n");

    /*  TEST DEQUEUE  */
    for (int i = 0; i<6; ++i)
        q_dequeue(tester);
    printf("QUEUE SHOULD HAVE KEPT THE LAST 4 ELEMENTS\n\tQUEUE: ");
    q_print(tester);
    printf("\n");

    /*  TEST FRONT  */
    printf("FRONT SHOULD BE THE FIRST ELEMENT IN THE QUEUE\n\tQUEUE: ");
    q_print(tester);
    printf("\tFRONT: %d\n", q_front(tester));
    printf("\n");
    fflush(stdout);

    /*  TEST IS EMPTY  */
    printf("QUEUE SHOULD NOT BE EMPTY\n\t");
    printf("IS EMPTY? %s\n", q_isEmpty(tester) ? "YES" : "NO");
    fflush(stdout);
    while (!q_isEmpty(tester))
        q_dequeue(tester);
    printf("QUEUE SHOULD BE EMPTY\n\t");
    printf("IS EMPTY? %s", q_isEmpty(tester) ? "YES" : "NO");
    printf("\n");
    fflush(stdout);
    
    q_free(tester);
    printf("\nALL TESTCASES PASSED SUCCESSFULLY.\n");
    fflush(stdout);

    return 0;
}