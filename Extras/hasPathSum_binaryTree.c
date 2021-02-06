// Given the root of a binary tree and an integer targetSum,
// return true if the tree has a root-to-leaf path such that
// adding up all the values along the path equals targetSum.
// Refer: https://leetcode.com/problems/path-sum/

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
bool hasPathSum(struct Node *root, int targetSum)
{
    if (root == NULL)
        return false;

    if (targetSum - root->data == 0 && root->left == NULL && root->right == NULL)
        return true;

    return hasPathSum(root->left, targetSum - root->data) ||
           hasPathSum(root->right, targetSum - root->data);
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

    int targetSum = 22;
    if (hasPathSum(root, targetSum))
        printf("\nYes");
    else
        printf("\nNo");

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
