// Program to find the number of nodes, edges and height of the tree.

#include <stdio.h>
#include <stdlib.h>

#define max(x, y) ((x > y) ? x : y)

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// To find height of a binary tree
int findHeight(struct Node *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(findHeight(root->left), findHeight(root->right));
}

// To count number of nodes in a binary tree
int countNodes(struct Node *root)
{
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
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

    int height = findHeight(root);
    printf("\nHeight of binary tree: %d", height);

    int numNodes = countNodes(root);
    printf("\nNumber of nodes: %d", numNodes);
    printf("\nNumber of edges: %d", numNodes - 1);
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
