// Given a binary tree, Find the sum of all leaf nodes

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Time complexity: O(n)
int sumOfLeaves(struct Node *root)
{
    if (root == NULL) // base case
        return 0;
    if (root->left == NULL && root->right == NULL) // if it is a leaf node
        return root->data;
    return sumOfLeaves(root->left) + sumOfLeaves(root->right); // find for left and right sub-trees
}

struct Node *createNode(int);
struct Node *insertLeft(struct Node *, int);
struct Node *insertRight(struct Node *, int);

int main()
{
    struct Node *root = NULL;
    root = createNode(5);
    insertLeft(root, 4);
    insertRight(root, 8);
    insertLeft(root->left, 11);
    insertLeft(root->right, 13);
    insertRight(root->right, 4);
    insertLeft(root->left->left, 7);
    insertRight(root->left->left, 2);
    insertRight(root->right->right, 1);

    //    For reference
    //          5
    //         / \
    //        4   8
    //       /   / \
    //     11  13  4
    //    / \       \
    //   7  2       1

    int sum = sumOfLeaves(root);
    printf("\nSum of leaves: %d", sum);

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
