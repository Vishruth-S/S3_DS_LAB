// Invert a binary tree.
// Refer: https://leetcode.com/problems/invert-binary-tree/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// For level order display
struct Node *q[100];
int front = -1, rear = -1;
void qPush(struct Node *);
void qPop();
struct Node *qFront();
bool qEmpty();
void levelOrder(struct Node *);

// Inverting a binary Tree
struct Node *invertTree(struct Node *root)
{
    if (root == NULL)
        return root;

    struct Node *temp = root->left;
    root->left = root->right;
    root->right = temp;

    invertTree(root->left);
    invertTree(root->right);

    return root;
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
    //     4  5 6  7

    printf("\nBinary tree in level order\n");
    levelOrder(root);

    root = invertTree(root);

    printf("\nBinary tree after inversion\n");
    levelOrder(root);

    //    After inversion
    //          1
    //        /  \
    //       3    2
    //      / \  / \
    //     7  6 5  4

    return 0;
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

void qPush(struct Node *node)
{
    if (rear == 99)
        return;
    if (qEmpty())
        ++front;
    q[++rear] = node;
}

void qPop()
{
    if (!qEmpty())
    {
        if (front == rear)
            front = rear = -1;
        else
            ++front;
    }
}

struct Node *qFront()
{
    if (qEmpty())
        return NULL;
    return q[front];
}

bool qEmpty()
{
    return front == -1 && rear == -1;
}

void levelOrder(struct Node *root)
{
    if (root == NULL)
        return;
    qPush(root);
    struct Node *curr = NULL;
    while (!qEmpty())
    {
        curr = qFront();
        qPop();
        printf("%d ", curr->data);
        if (curr->left)
            qPush(curr->left);
        if (curr->right)
            qPush(curr->right);
    }
}
