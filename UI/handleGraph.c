#include "handlers.h"
#include "../Graphs/Normal-Graphs/graph.h"

/*  PRINT INFO OF GRAPH (size and current state)  */
void printGraphInfo(MyGraph* g){
    fprintf(stdout, "\n\t\tCURRENT EDGES: ");
    printGraph(g);
    fprintf(stdout, "\t\tSIZE: %d\n", graphSize(g));
    fflush(stdout);
}

/*  PRINT GRAPH MENU  */
void printGraphMenu(MyGraph* g){
        fprintf(stdout, "\n- MAIN MENU -> GRAPH MENU\n");
        printGraphInfo(g);
        fprintf(stdout, "\n\t\tAdd edge: 'A'\n"
                        "\t\tRemove edge: 'R'\n"
                        "\t\tRemove Vertex: 'V'\n"
                        "\t\tCheck if Edge exists: 'E'\n"
                        "\t\tGet Connections of a vertex: 'C'\n"
                        "\t\tPrint Graph: 'P'\n"
                        "\t\tExit: 'e'\n"
                        "\t\tSelect Option: ");
        fflush(stdout);
}

void handleGraph(){
    MyGraph* g = newGraph();
    char quit = 0, choice = 0;
    int v1 = 0, v2 = 0;
    while (!quit){

        printGraphMenu(g);
        fflush(stdin);
        fscanf(stdin, " %c", &choice);  // Get user input.

        switch(choice){
            case 'A':

                fprintf(stdout, "\n\t\t\tEdge to add \"v1, v2\": ");
                fflush(stdin);
                fscanf(stdin, " %d, %d", &v1, &v2);

                // ADD THE EDGE
                addEdge(g, v1, v2);
                break;
            
            case 'R':
                fprintf(stdout, "\n\t\t\tEdge to remove \"v1, v2\": ");
                fflush(stdin);
                fscanf(stdin, " %d, %d", &v1, &v2);

                // REMOVE THE CHOSEN EDGE
                removeEdge(g, v1, v2);
                break;

            case 'V':
                fprintf(stdout, "\n\t\t\tSelect Vertex to remove: ");
                fflush(stdin);
                fscanf(stdin, " %d", &v1);

                removeVertex(g, v1);
                break;

            case 'E':
                fprintf(stdout, "\n\t\t\tEdge to look for \"v1, v2\": ");
                fflush(stdin);
                fscanf(stdin, " %d, %d", &v1, &v2);

                // CHECK IF EXISTS
                fprintf(stdout, "\n\t\t\tEdge [%d, %d] %s exist in the graph.", v1, v2, isEdge(g, v1, v2) ? "DOES" : "DOES NOT");
                break;
            
            case 'C':
                fprintf(stdout, "\n\t\t\tSelect a Vertex: ");
                fflush(stdin);
                fscanf(stdin, " %d", &v1);

                int *arr = connections(g, v1, &v2); // Load array of connections.
                fprintf(stdout, "\n\t\t\tVertices connected to %d are: ", v1);
                for (int i = 0; i<v2;++i)
                    fprintf(stdout, "%d ", arr[i]);
                free(arr);
                fprintf(stdout, "\n");
                break;

            case 'P':
                printGraphInfo(g);
                break;

            case 'e':
                quit = 1;
                freeGraph(g);
                fflush(stdin);
                fflush(stdout);
                break;

            default:
                break;
        }

    }
}