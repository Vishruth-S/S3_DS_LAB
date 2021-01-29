//CSL201 DATA STRUCTURES LAB ----- VISHRUTH S, CS3A, 61
//CYCLE 7 QUESTION 2
//Program to perfom Breadth First Traversal on a graph 
//represented using the adjacency matrix

#include <stdio.h>
#include <stdbool.h>

#define V 15

// ===== Queue and its functions ===== //
const int qSize = 100;
int q[100];
int front = -1, rear = -1;

void qPush(int);
int qPop();
bool qEmpty();

// ============ BREADTH FIRST TRAVERSAL ============= //
// Time complexity: O(V*V) (when using adjacency matrix of V vertices)
void breadthFirstTraversal(int graph[][V], int numV, int u)
{
    int visited[V] = {0}; // initilaze visited array to keep track of visited nodes

    visited[u] = 1; // mark the starting node as visited
    qPush(u);       // and push it into the queue

    int curr_node;
    while (!qEmpty())
    {
        curr_node = qPop();          // get a node from the front of the queue
        printf("%d -> ", curr_node); // and print its value

        for (int i = 0; i <= numV; i++) // traverse through all nodes to get the adjacent vertices of current node
        {
            if (graph[curr_node][i] == 1 && visited[i] == 0) // if there is an edge connecting current node to another unvisited node
            {
                visited[i] = 1; // then visit that node
                qPush(i);       // and push it into the queue
            }
        }
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
    printf("\nAdjacency matrix\n");
    printAdjacencyMatrix(graph, numVertices);

    int startNode;
    printf("\nEnter the start vertex\n");
    scanf("%d", &startNode);
    printf("\nBreadth first traversal from node %d\n", startNode);
    breadthFirstTraversal(graph, numVertices, startNode);

    printf("\n");
    return 0;
}

// Function to add an edge between two vertices of an Undirected graph
void addEdge(int graph[][V], int u, int v)
{
    graph[u][v] = 1;
    graph[v][u] = 1;
}

// ====== Queue functions ====== //
void qPush(int data)
{
    if (rear == qSize - 1)
        return;
    if (front == -1)
        ++front;
    q[++rear] = data;
}

int qPop()
{
    if (qEmpty())
        return -1;
    int deleted = q[front];
    if (rear == front)
        front = rear = -1;
    else
        front++;
    return deleted;
}

bool qEmpty()
{
    return front == -1 && rear == -1;
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