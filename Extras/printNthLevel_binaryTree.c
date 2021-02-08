// Given a binary tree and an integer n, print the nodes at the nth level

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Method 1 - Using Recursion
void printLevel(struct Node *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else
    {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}

// Method 2 - Using level order traversal
// ===== Queue and its functions ===== //
const int qSize = 100;
struct Node *q[100];
int front = -1, rear = -1;

void qPush(struct Node *);
struct Node *qPop();
bool qEmpty();

// In this approach, we can check if the current level is the required level. If yes, then print it.
// Time complexity: O(n)
void printLevel2(struct Node *root, int targetLevel)
{
    if (root == NULL)
        return;
    qPush(root);
    struct Node *curr;
    int level = 1;
    while (!qEmpty())
    {
        int size = rear - front + 1;
        for (int i = 0; i < size; i++)
        {
            curr = qPop();
            if (level == targetLevel)
                printf("%d ", curr->data);
            if (curr->left)
                qPush(curr->left);
            if (curr->right)
                qPush(curr->right);
        }
        level++;
        if (level > targetLevel)
            break;
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

    int level;
    printf("\nEnter level\n");
    scanf("%d", &level);
    printf("\nNodes at level %d\n", level);
    printLevel(root, level);
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
