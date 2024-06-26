/*  My Graphs Specification  */
/*
 *    Graphs are represented as an adjacency list between their
 *  vertices. If printed, [a, b] represents an edge connecting vertex
 *  a with vertex b.
 *
 */

#ifndef GRAPH_HEADER
#define GRAPH_HEADER

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_graph MyGraph;

/*  CREATE A NEW EMPTY GRAPH  */
MyGraph* newGraph(void);

/*  RETURNS THE AMOUNT OF EDGES IN THE GRAPH  */
int graphSize(MyGraph* graph);

/*  ADD EDGE [v1, v2] TO GRAPH  */
void addEdge(MyGraph* graph, int v1, int v2);

/*  REMOVE EDGE [v1, v2] FROM THE GRAPH  */
void removeEdge(MyGraph* graph, int v1, int v2);

/*  REMOVE THE VERTEX v (AND ALL OF ITS CONNECTIONS) FROM THE GRAPH  */
void removeVertex(MyGraph* graph, int v);

/*  RETURN ALL CONNECTIONS OF A VERTEX
 *  loads the number of connections into retSize.
 *  returned array must be freed by the caller.
 */
int* connections(MyGraph* graph, int vertex, int* retSize);

/*  RETURNS ALL VERTICES OF A GRAPH
 *  loads the number of vertices into *retSize.
 *  returned array must be freed by the caller.
 */
int* vertices(MyGraph* graph, int* retSize);

/*  DETERMINES IF [v1, v2] IS AN EDGE OF THE GRAPH  */
bool isEdge(MyGraph* graph, int v1, int v2);

/*  FREE ALL SPACE USED BY graph  */
void freeGraph(MyGraph* graph);

/*  PRINT GRAPH TO stdout  */
void printGraph(MyGraph* graph);

#endif /*  GRAPH_HEADER  */