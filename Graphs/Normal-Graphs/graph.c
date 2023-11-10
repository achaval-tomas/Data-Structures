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

/*  RETURNS THE AMOUNT OF EDGES IN THE GRAPH  */
int graphSize(MyGraph* graph){
    return graph->size;
}

struct s_edge newEdge(int v1, int v2){
    struct s_edge edge;
    edge.v1 = v1;
    edge.v2 = v2;
    return edge;
}

/*  AUX FUNCTION  */
bool edgeIsEqual(struct s_edge e1, struct s_edge e2){
    return ((e1.v1 == e2.v1) && (e1.v2 == e2.v2)) || ((e1.v1 == e2.v2) && (e1.v2 == e2.v1));
}

/*  ADD EDGE [v1, v2] TO GRAPH, Time Complexity: O(n)  */
void addEdge(MyGraph* graph, int v1, int v2){
    if (!isEdge(graph, v1, v2)){
        graph->adjList = realloc(graph->adjList, (++graph->size)*sizeof(*(graph->adjList)));
        (graph->adjList)[graph->size-1] = newEdge(v1, v2);
    }
}

/*  REMOVE EDGE [v1, v2] FROM THE GRAPH, Time Complexity: O(n)  */
void removeEdge(MyGraph* graph, int v1, int v2){
    struct s_edge edge = newEdge(v1, v2);
    int i = 0;
    while (i<graph->size){
        if (edgeIsEqual(edge, (graph->adjList)[i]))
            break;
        ++i;
    }
    if (i==graph->size)
        return;

    for (int j = i; j<graph->size-1; ++j)
        (graph->adjList)[j] = (graph->adjList)[j+1];

    graph->adjList = realloc(graph->adjList, (--graph->size)*sizeof(*(graph->adjList)));
}

/*  REMOVE THE VERTEX v (AND ALL OF ITS CONNECTIONS) FROM THE GRAPH, Time Complexity: O(n) */
void removeVertex(MyGraph* graph, int v){
    int i = 0;
    while (i<graph->size) {
        if ((graph->adjList)[i].v1 == v)
            removeEdge(graph, v, (graph->adjList)[i].v2);
        else if ((graph->adjList)[i].v2 == v)
            removeEdge(graph, (graph->adjList)[i].v1, v);
        else 
            ++i;
    }
}

/*  AUX FUNCTION  */
int isInEdge(int v, struct s_edge e){
    return (v == e.v1) || (v == e.v2);
}

/*  RETURN ALL CONNECTIONS OF A VERTEX
 *  loads the number of connections into retSize.
 *  returned array must be freed by the caller.
 *  Time Complexity: O(n)
 */
int* connections(MyGraph* graph, int vertex, int* retSize){
    int size = 0;

    for (int i = 0; i<graph->size; ++i)
        size += isInEdge(vertex, (graph->adjList)[i]);

    *retSize = size;
    int* ret = NULL;
    if (!size)
        return ret;
        
    ret = malloc(size*sizeof(int));

    int idx = 0, i = 0;
    while (i<graph->size && idx < size){
        if ((graph->adjList)[i].v1 == vertex)
            ret[idx++] = (graph->adjList)[i].v2;
        else if ((graph->adjList)[i].v2 == vertex)
            ret[idx++] = (graph->adjList)[i].v1;
        ++i;
    }

    return ret;
}

/*  AUX FUNCTION FOR vertices  */
bool notInArr(int elem, int* arr, int size){
    for (int i = 0; i<size; ++i){
        if (arr[i] == elem)
            return false;
    }
    return true;
}


/*  RETURNS ALL VERTICES OF A GRAPH
 *  loads the number of vertices into *retSize.
 *  returned array must be freed by the caller.
 *  Very Slow Function
 */
int* vertices(MyGraph* graph, int* retSize){
    if (!graph->size)
        return NULL;
    int* ret = NULL;
    int cnt = 0;
    for (int i = 0; i<graph->size; ++i){
        if (notInArr((graph->adjList)[i].v1, ret, cnt) ){
            ret = realloc(ret, sizeof(*ret)*(++cnt)); // Make space and increase count.
            ret[cnt-1] = (graph->adjList)[i].v1;
        }
        if (notInArr((graph->adjList)[i].v2, ret, cnt) ){
            ret = realloc(ret, sizeof(*ret)*(++cnt)); // Make space and increase count.
            ret[cnt-1] = (graph->adjList)[i].v2;
        }
    }
    *retSize = cnt;
    return ret;
}

/*  DETERMINES IF [v1, v2] IS AN EDGE OF THE GRAPH, Time Complexity: O(n)  */
bool isEdge(MyGraph* graph, int v1, int v2){
    struct s_edge edge = newEdge(v1, v2);
    for (int i = 0; i<graph->size; ++i){
        if (edgeIsEqual(edge, (graph->adjList)[i]))
            return true;
    }
    return false;
}

/*  FREE ALL SPACE USED BY graph  */
void freeGraph(MyGraph* graph){
    if (graph->adjList)
        free(graph->adjList);
    free(graph);
}


/*  PRINT GRAPH TO stdout  */
void printGraph(MyGraph* graph){
    if (!graph->size)
        printf("[ ]");
    for (int i = 0; i<graph->size; ++i)
        printf("[%d, %d] ", (graph->adjList)[i].v1, (graph->adjList)[i].v2);
    printf("\n");
    fflush(stdout);
}