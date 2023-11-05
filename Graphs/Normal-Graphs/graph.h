/*  My Graphs Specification  */

#ifndef GRAPH_HEADER
#define GRAPH_HEADER

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct s_graph MyGraph;

/*  CREATE A NEW EMPTY GRAPH  */
MyGraph* newGraph(void);

/*  ADD A VERTEX TO GRAPH  */
void addVertex(MyGraph* graph, int vertex, int* connections, int connectionsSize);

/*  REMOVE A VERTEX FROM THE GRAPH  */
void removeVertex(MyGraph* graph, int vertex);

/*  RETURN ALL CONNECTIONS OF A VERTEX  */
int* connections(MyGraph* graph, int vertex);

/*  FREE ALL SPACE USED BY graph  */
void freeGraph(MyGraph* graph);

/*  PRINT GRAPH TO stdout  */
void printGraph(MyGraph* graph);

#endif /*  GRAPH_HEADER  */