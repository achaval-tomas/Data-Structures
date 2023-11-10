/*  My Graphs Testing  */

#include "graph.h"

int main(void){

    /*  CREATE NEW GRAPH  */
    MyGraph* g = newGraph();

    /*  TEST ADDING EDGES AND SIZE */
    printf("ADDING NODES..\n");
    for (int i = 0; ++i<=10;){
        printGraph(g);
        addEdge(g, 2*i, i);
    }
    printf("\nFINAL SIZE: %d <- should be 10\nGRAPH: ", graphSize(g));
    printGraph(g);
    

    /*  TEST REMOVING EDGES  */
    printf("\nREMOVING EDGES [8, 4], [10, 20] and [2, 1]...");
    removeEdge(g, 8, 4);
    removeEdge(g, 10, 20);
    removeEdge(g, 2, 1);
    printf("\nSIZE: %d <- should be 7\nGRAPH: ", graphSize(g));
    printGraph(g);

    /*  TEST REMOVING VERTEX  */
    removeVertex(g, 6);
    printf("\nNO EDGES SHOULD CONTAIN THE VERTEX 6");
    printf("\nSIZE: %d <- should be 5\nGRAPH: ", graphSize(g));
    printGraph(g);

    /*  TEST CONNECTIONS OF NODE  */
    addEdge(g, 0, 1);
    for (int i = 0; ++i<=5;)
        addEdge(g, 1, i*15);
    printf("\nNEW GRAPH: ");
    printGraph(g);

    int size = 0;
    int* cons = connections(g, 1, &size);
    printf("VERTICES CONNECTED TO VERTEX 1: ");
    for (int i = 0; i<size; ++i)
        printf("%d ", cons[i]);
    printf("\n");

    /*  TEST REMOVING VERTEX  */
    removeVertex(g, 1);
    printf("\nNO EDGES SHOULD CONTAIN THE VERTEX 1");
    printf("\nSIZE: %d <- should be 5\nGRAPH: ", graphSize(g));
    printGraph(g);

    /*  FREE SPACE USED IN TESTS  */
    freeGraph(g);
    free(cons);

    /*  ALL TESTCASES SUCCESSFULLY COMPLETED  */
    printf("\nALL TESTCASES PASSED SUCCESSFULLY.\n");
    fflush(stdout);

    return 0;
}