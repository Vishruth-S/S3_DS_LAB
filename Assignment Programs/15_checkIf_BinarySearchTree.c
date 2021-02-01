#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

bool isBST(struct Node *root)
{
    if (root == NULL)
        return true;
}

struct Node *createNode(int);
struct Node *insertLeft(struct Node *, int);
struct Node *insertRight(struct Node *, int);

int main()
{
    struct Node *root = NULL;
    // root = createNode(1);
    // insertLeft(root, 2);
    // insertRight(root, 3);
    // insertLeft(root->left, 4);
    // insertRight(root->left, 5);
    // insertLeft(root->right, 6);
    // insertRight(root->right, 7);
    //    For reference
    //          1
    //        /  \
    //       2    3
    //      / \  / \
    //     4   5 6  7
    root = createNode(10);
    insertLeft(root, 5);
    insertRight(root, 15);
    insertLeft(root->left, 2);
    insertRight(root->left, 7);
    insertLeft(root->right, 12);
    insertRight(root->right, 18);

    //    For reference
    //         10
    //        /  \
    //       5    15
    //      / \  / \
    //     2  7 12  18
    if (isBST(root))
        printf("\nGiven tree is a BST");
    else
        printf("\nNope");
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
