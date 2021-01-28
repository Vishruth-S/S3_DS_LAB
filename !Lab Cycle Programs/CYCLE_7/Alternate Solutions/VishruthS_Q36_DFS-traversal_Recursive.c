//CSL201 DATA STRUCTURES LAB ----- VISHRUTH S, CS3A, 61
//CYCLE 7 QUESTION 1
//Program to perfom Depth First Traversal on a graph 
//represented using the adjacency matrix
#include <stdio.h>
#include <stdbool.h>

#define V 12

int visited[V] = {0}; // to keep track of visited nodes

// ================ DEPTH FIRST TRAVERSAL ============== //
// Time complexity: O(V*V) (when using adjacency matrix of V vertices)
void depthFirstTraversal(int graph[][V], int numV, int u)
{
    visited[u] = 1;                 // mark current node as visited
    printf("%d ", u);               // and print its value
    for (int i = 0; i <= numV; i++) // for every node in the graph
    {
        if (graph[u][i] == 1 && visited[i] == 0) // if it is adjacent and not visited
            depthFirstTraversal(graph, numV, i); // then go to that node
    }
}

void addEdge(int[][V], int, int);
void printAdjacencyMatrix(int[][V], int);

// === MAIN FUNCTION === //
int main()
{

    int graph[V][V] = {0}; // initiliazing Adjacency Matrix
    int numVertices, numEdges, l;
    printf("Enter the number of vertices in the graph  ");
    scanf("%d", &numVertices);
    for (int i = 1; i <= numVertices; i++)
    {
        printf("\nEnter the number of edges from %d : ", i);
        scanf("%d", &numEdges);
        for (int j = 0; j < numEdges; j++)
        {
            printf("\nEnter the connection %d : ", j + 1);
            scanf("%d", &l);
            addEdge(graph, i, l);
        }
    }

    int startNode;
    printf("\nEnter the start vertex\n");
    scanf("%d", &startNode);

    printf("\nAdjacency matrix\n");
    printAdjacencyMatrix(graph, numVertices);
    
    printf("\nDepth first traversal from node %d\n", startNode);
    depthFirstTraversal(graph, numVertices, startNode);

    return 0;
}

// Function to add an edge between two vertices of an Undirected graph
void addEdge(int graph[][V], int u, int v)
{
    graph[u][v] = 1;
    graph[v][u] = 1;
}

// function to print adjacency matrix
void printAdjacencyMatrix(int graph[][V], int numV)
{
    int i, j;
    printf("   ");
    for (int k = 1; k <= numV; k++)
        printf("%3d ", k);
    printf("\n");
    for (int k = 0; k <= numV; k++)
        printf("____");
    printf("\n");
    for (i = 1; i <= numV; i++)
    {
        printf("%2d|", i);
        for (j = 1; j <= numV; j++)
        {
            printf("%3d ", graph[i][j]);
        }
        printf("\n");
    }
    printf("\n\n\n");
}