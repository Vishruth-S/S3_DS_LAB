//CSL201 DATA STRUCTURES LAB ----- VISHRUTH S, CS3A, 61
//CYCLE 7 QUESTION 2
//Program to perfom Breadth First Traversal on a graph 
//represented using the adjacency list

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *vertices[100], *temp, *head;

// ===== Queue and its functions ===== //
const int qSize = 100;
int q[100];
int front = -1, rear = -1;

void qPush(int);
int qPop();
bool qEmpty();

// ============ BREADTH FIRST TRAVERSAL ============= //
// Time complexity: O(V + E) (when using adjacency list of V vertices & E edges)
void breadthFirstTraversal(int u)
{
    int visited[100] = {0}; // initilaze visited array to keep track of visited nodes

    visited[u] = 1; // mark the starting node as visited
    qPush(u);       // and push it into the queue

    int curr_node;
    while (!qEmpty())
    {
        curr_node = qPop();          // get a node from the front of the queue
        printf("%d -> ", curr_node); // and print its value
        temp = vertices[curr_node];
        while (temp) // check the neighbouring nodes
        {
            if (!visited[temp->data]) // if there is an unvisited neighbouring node
            {
                visited[temp->data] = 1; // visit it
                qPush(temp->data);       // and push into the queue
            }
            temp = temp->next;
        }
    }
}
// === MAIN FUNCTION === //
int main()
{
    int n;
    printf("Enter number of nodes\n");
    scanf("%d", &n);
    int i, c;
    for (i = 1; i <= n; i++)
    {
        vertices[i] = (struct Node *)malloc(sizeof(struct Node));
        vertices[i]->data = i;
        vertices[i]->next = NULL;
        head = vertices[i];
        printf("Enter all adjacent nodes to vertex %d, enter 0 to go to next node\n", i);
        do
        {
            scanf("%d", &c);
            if (c != 0)
            {
                temp = (struct Node *)malloc(sizeof(struct Node));
                temp->data = c;
                temp->next = NULL;
                head->next = temp;
                head = temp;
            }

        } while (c != 0);
    }

    int startNode;
    printf("\nEnter the start vertex\n");
    scanf("%d", &startNode);
    printf("\nBreadth first traversal from node %d\n", startNode);
    breadthFirstTraversal(startNode);

    printf("\n");
    return 0;
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
