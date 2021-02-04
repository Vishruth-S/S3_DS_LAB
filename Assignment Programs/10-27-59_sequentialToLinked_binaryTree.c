// A binary tree is given with the sequential storage representation. 
// Write a program to copy the binary tree into linked storage representation.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Time complexity: O(n)
struct Node *insertIntoTree(int arr[], struct Node *root, int i, int n)
{
    if (i >= n) // base case
        return root;

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); // create a new node
    newNode->data = arr[i];
    newNode->left = newNode->right = NULL;

    root = newNode;
    root->left = insertIntoTree(arr, root->left, (2 * i + 1), n);   // insert left child
    root->right = insertIntoTree(arr, root->right, (2 * i + 2), n); // insert right child

    return root;
}

void inOrder(struct Node *);

int main()
{
    int tree[] = {10, 5, 14, 3, 8, 11, 17, 1};
    int n = sizeof(tree) / sizeof(tree[0]);

    //          Tree for reference
    //
    //               10
    //             /   \
    //            5    14
    //           / \  / \ 
    //          3  8 11 17
    //         /
    //        1

    struct Node *root = NULL;
    root = insertIntoTree(tree, root, 0, n);
    printf("\nTree inorder\n");
    inOrder(root);

    return 0;
}

void inOrder(struct Node *root)
{
    if (root)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}
