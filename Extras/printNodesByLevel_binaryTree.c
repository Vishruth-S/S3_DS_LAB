// Program to print each level of a binary tree

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// ===== Queue and its functions ===== //
const int qSize = 100;
struct Node *q[100];
int front = -1, rear = -1;

void qPush(struct Node *);
struct Node *qPop();
bool qEmpty();

// To print nodes at each level
void nodesByLevel(struct Node *root)
{
    if (root == NULL)
        return;
    qPush(root);
    struct Node *curr;
    int level = 1;
    while (!qEmpty())
    {
        int size = rear - front + 1;
        printf("\nLevel %d: ", level);
        for (int i = 0; i < size; i++)
        {
            curr = qPop();
            printf("%d ", curr->data);
            if (curr->left)
                qPush(curr->left);
            if (curr->right)
                qPush(curr->right);
        }
        level++;
    }
}

struct Node *createNode(int);
struct Node *insertLeft(struct Node *, int);
struct Node *insertRight(struct Node *, int);

int main()
{
    struct Node *root = NULL;
    root = createNode(7);
    insertLeft(root, 5);
    insertRight(root, 10);
    insertLeft(root->left, 2);
    insertRight(root->left, 6);
    insertLeft(root->right, 8);
    insertRight(root->right, 14);

    //    For reference
    //          7
    //        /  \
    //       5    10
    //      / \  / \
    //     2  6 8  14

    printf("\nNodes at each level\n");
    nodesByLevel(root);

    return 0;
}

// ====== Queue functions ====== //
void qPush(struct Node *node)
{
    if (rear == qSize - 1)
        return;
    if (front == -1)
        ++front;
    q[++rear] = node;
}

struct Node *qPop()
{
    if (qEmpty())
        return NULL;
    struct Node *deleted = q[front];
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

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node *insertLeft(struct Node *root, int data)
{
    root->left = createNode(data);
    return root->left;
}

struct Node *insertRight(struct Node *root, int data)
{
    root->right = createNode(data);
    return root->right;
}
