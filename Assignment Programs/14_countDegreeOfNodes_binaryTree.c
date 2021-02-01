// Given a binary tree, count the
// Number of nodes with degree 2
// Number of nodes with degree 1
// Number of nodes with degree 0

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

int count0 = 0, count1 = 0, count2 = 0;
void countDegreeOfNodes(struct Node *root)
{
    if (root == NULL)
        return;
    if (root->left && root->right)
        count2++;
    else if (root->left || root->right)
        count1++;
    else
        count0++;

    countDegreeOfNodes(root->left);
    countDegreeOfNodes(root->right);
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
    insertLeft(root->left->left, 8);
    insertRight(root->right->left, 9);

    //    For reference
    //          1
    //        /  \
    //       2    3
    //      / \  / \
    //     4  5 6  7
    //    /      \
    //   8       9

    countDegreeOfNodes(root);
    printf("\nCount of nodes with degree 0: %d", count0);
    printf("\nCount of nodes with degree 1: %d", count1);
    printf("\nCount of nodes with degree 2: %d", count2);
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
