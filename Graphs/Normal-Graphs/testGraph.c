/*  My Graphs Testing  */

#include "graph.h"

int main(void){

    /*  CREATE NEW GRAPH  */
    MyGraph* g = newGraph();

    /*  TEST ADDING EDGES AND SIZE */
    fprintf(stdout, "ADDING NODES..\n");
    for (int i = 0; ++i<=10;){
        printGraph(g);
        addEdge(g, 2*i, i);
    }
    fprintf(stdout, "\nFINAL SIZE: %d <- should be 10\nGRAPH: ", graphSize(g));
    printGraph(g);
    

    /*  TEST REMOVING EDGES  */
    fprintf(stdout, "\nREMOVING EDGES [8, 4], [10, 20] and [2, 1]...");
    removeEdge(g, 8, 4);
    removeEdge(g, 10, 20);
    removeEdge(g, 2, 1);
    fprintf(stdout, "\nSIZE: %d <- should be 7\nGRAPH: ", graphSize(g));
    printGraph(g);

    /*  TEST REMOVING VERTEX  */
    removeVertex(g, 6);
    fprintf(stdout, "\nNO EDGES SHOULD CONTAIN THE VERTEX 6");
    fprintf(stdout, "\nSIZE: %d <- should be 5\nGRAPH: ", graphSize(g));
    printGraph(g);

    /*  TEST CONNECTIONS OF NODE  */
    addEdge(g, 0, 1);
    for (int i = 0; ++i<=5;)
        addEdge(g, 1, i*15);
    fprintf(stdout, "\nNEW GRAPH: ");
    printGraph(g);

    int size = 0;
    int* cons = connections(g, 1, &size);
    fprintf(stdout, "VERTICES CONNECTED TO VERTEX 1: ");
    for (int i = 0; i<size; ++i)
        fprintf(stdout, "%d ", cons[i]);
    fprintf(stdout, "\n");

    /*  TEST REMOVING VERTEX  */
    removeVertex(g, 1);
    fprintf(stdout, "\nNO EDGES SHOULD CONTAIN THE VERTEX 1");
    fprintf(stdout, "\nSIZE: %d <- should be 5\nGRAPH: ", graphSize(g));
    printGraph(g);

    /*  FREE SPACE USED IN TESTS  */
    freeGraph(g);
    free(cons);

    /*  ALL TESTCASES SUCCESSFULLY COMPLETED  */
    fprintf(stdout, "\nALL TESTCASES PASSED SUCCESSFULLY.\n");
    fflush(stdout);

    return 0;
}