/*  My Graphs Implementation  */

#include "graph.h"

struct s_edge {
    int v1, v2;
};

struct s_graph {
    int size;
    struct s_edge* adjList;
};

/*  CREATE A NEW EMPTY GRAPH  */
MyGraph* newGraph(void){
    MyGraph* g = malloc(sizeof(*g));
    g->size = 0;
    g->adjList = NULL;
    return g;
}

struct s_edge newEdge(int v1, int v2){
    struct s_edge edge;
    edge.v1 = v1;
    edge.v2 = v2;
    return edge;
}

/*  ADD EDGE [v1, v2] TO GRAPH  */
void addEdge(MyGraph* graph, int v1, int v2){
    if (!isEdge(graph, v1, v2)){
        graph->adjList = realloc(graph->adjList, (++graph->size));
        (graph->adjList)[graph->size-1] = newEdge(v1, v2);
    }
}