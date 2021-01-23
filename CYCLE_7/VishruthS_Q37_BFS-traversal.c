//CSL201 DATA STRUCTURES LAB ----- VISHRUTH S, CS3A, 61
//CYCLE 7 QUESTION 2
//Program to perfom Breadth First Traversal on a graph 
//represented using the adjacency matrix

#include <stdio.h>
#include <stdbool.h>

#define V 11

// ===== Queue and its functions ===== //
const int qSize = 100;
int q[100];
int front = -1, rear = -1;

void qPush(int);
int qPop();
bool qEmpty();

// ============ BREADTH FIRST TRAVERSAL ============= //
// Time complexity: O(V*V) (when using adjacency matrix of V vertices)
void breadthFirstTraversal(int graph[][V], int u)
{
    int visited[V] = {0}; // initilaze visited array to keep track of visited nodes

    visited[u] = 1; // mark the starting node as visited
    qPush(u);       // and push it into the queue

    int curr_node;
    while (!qEmpty())
    {
        curr_node = qPop();          // get a node from the front of the queue
        printf("%d -> ", curr_node); // and print its value

        for (int i = 0; i < V; i++) // traverse through all nodes to get the adjacent vertices of current node
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
void printAdjacencyMatrix(int[][V]);

// === MAIN FUNCTION === //
int main()
{
    int graph[V][V] = {0}; // initiliazing Adjacency Matrix

    addEdge(graph, 1, 2); // adding edges between graph nodes
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 5);
    addEdge(graph, 2, 7);
    addEdge(graph, 2, 8);
    addEdge(graph, 3, 4);
    addEdge(graph, 3, 10);
    addEdge(graph, 3, 9);
    addEdge(graph, 5, 6);
    addEdge(graph, 5, 7);
    addEdge(graph, 5, 8);
    addEdge(graph, 7, 8);

    printf("\nAdjacency matrix\n");
    printAdjacencyMatrix(graph);

    printf("\nBreadth first traversal from node 1\n");
    breadthFirstTraversal(graph, 1);

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
void printAdjacencyMatrix(int graph[][V])
{
    for (int k = 0; k <= V; k++)
        printf("%3d ", k);
    printf("\n");
    for (int k = 0; k <= V; k++)
        printf("____");
    printf("\n");
    for (int i = 0; i < V; i++)
    {
        printf("%2d|", i + 1);
        for (int j = 0; j < V; j++)
            printf("%3d ", graph[i][j]);
        printf("\n");
    }
}