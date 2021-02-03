// Program to print the ancestors of a given node in a binary tree

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
bool printAncestors(struct Node *root, int query)
{
    if (root == NULL)
        return false;
    if (root->data == query)
        return true;

    // if data is present in either of the subtrees, then this node is an ancestor, so print it
    if (printAncestors(root->left, query) || printAncestors(root->right, query))
    {
        printf("%d ", root->data);
        return true;
    }
    // else return false
    return false;
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
    insertRight(root->right, 6);
    insertLeft(root->left->left, 7);

    //    For reference
    //          1
    //        /  \
    //       2    3
    //      / \    \
    //     4  5     6
    //    /
    //   7

    int child = 7;
    printf("\nAncestors of %d are\n", child);
    printAncestors(root, child);

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
