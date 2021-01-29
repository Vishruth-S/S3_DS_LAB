// Program to perform Level order traversal on a binary tree

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

// Level order Traversal
void levelOrderTraversal(struct Node *root)
{
    if (root == NULL)
        return;

    qPush(root);
    while (!qEmpty())
    {
        struct Node *curr = qPop();
        printf("%d ", curr->data);
        if (curr->left)
            qPush(curr->left);
        if (curr->right)
            qPush(curr->right);
    }
}

struct Node *createNode(int);
struct Node *insertLeft(struct Node *, int);
struct Node *insertRight(struct Node *, int);

int main()
{
    struct Node *root = NULL;
    root = createNode(1);
    insertLeft(root, 2);
    insertRight(root, 3);
    insertLeft(root->left, 4);
    insertRight(root->left, 5);
    insertLeft(root->right, 6);
    insertRight(root->right, 7);

    //    For reference
    //          1
    //        /  \
    //       2    3
    //      / \  / \
    //     4   5 6  7

    printf("\nLevel Order traversal\n");
    levelOrderTraversal(root);
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
