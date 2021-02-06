// Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
// Refer: https://leetcode.com/problems/symmetric-tree/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
bool isReflection(struct Node *, struct Node *);

// Time complexity: O(n)
bool isSymetricTree(struct Node *root)
{
    return isReflection(root, root); // check if left and right are reflection
}

bool isReflection(struct Node *tree1, struct Node *tree2)
{
    if (!tree1 && !tree2) // if both are null
        return true;
    if (!tree1 || !tree2) // if one is empty and other is not
        return false;

    return tree1->data == tree2->data &&              //check if same values
           isReflection(tree1->left, tree2->right) && // and recursively check for left and right sub-trees
           isReflection(tree1->right, tree2->left);
}

struct Node *createNode(int);
struct Node *insertLeft(struct Node *, int);
struct Node *insertRight(struct Node *, int);

int main()
{
    struct Node *root = NULL;
    root = createNode(1);
    insertLeft(root, 2);
    insertRight(root, 2);
    insertLeft(root->left, 3);
    insertRight(root->left, 4);
    insertLeft(root->right, 4);
    insertRight(root->right, 3);

    //    For reference
    //          1
    //         / \
    //        2   2
    //       / \ / \
    //      3  4 4  3

    if (isSymetricTree(root))
        printf("\nTree is symetric\n");
    else
        printf("\nTree is not symetric\n");

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
