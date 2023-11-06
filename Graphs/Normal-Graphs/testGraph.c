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
    removeEdge(g, 8, 4);
    removeEdge(g, 10, 20);
    removeEdge(g, 2, 1);
    fprintf(stdout, "\nSIZE: %d <- should be 7\nGRAPH: ", graphSize(g));
    printGraph(g);

    /*  TEST REMOVING VERTEX  */
    /*
    removeVertex(g, 6);
    fprintf(stdout, "\nNO EDGES SHOULD CONTAIN THE NUMBER 6\nGRAPH: ");
    printGraph(g);
    */

    freeGraph(g);

    return 0;
}