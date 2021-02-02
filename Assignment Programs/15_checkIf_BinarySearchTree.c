// Check if a given binary search tree is a binary search tree or not

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// ===== Method 1 - using auxillary array =====
// This method is based on the idea that inorder travsersal of a BST will always give elements in sorted order
// So it is enough to check if the array generated on inorder traversal is sorted or not
//  == Time complexity: O(n), Space complexity: O(n) ==
int inorderArray[100];
int idx = 0;
void generateInorderArray(struct Node *root)
{
    if (root == NULL)
        return;
    generateInorderArray(root->left);
    inorderArray[idx++] = root->data;
    generateInorderArray(root->right);
}
bool isBST_inorder(struct Node *root)
{
    generateInorderArray(root);   // generate array
    for (int i = 1; i < idx; i++) // check if it is sorted
        if (inorderArray[i] < inorderArray[i - 1])
            return false;

    return true;
}
// The above method can be further optimized for space. Instead of storing the entire array,
// we can keep track of the previous node and compare currrent and previous node at each stage

// ==== Method 2 - Using range of each node ======
// Each node in a BST will have a specific range based on its ancestors
// So we check if all nodes fall within this range
// == Time complexity: O(n), Space complexity: O(1) ==
bool isBST(struct Node *root, int min, int max)
{
    if (root == NULL)
        return true;
    if (root->data < min || root->data > max)
        return false;
    return isBST(root->left, min, root->data - 1) && isBST(root->right, root->data + 1, max);
}

struct Node *createNode(int);
struct Node *insertLeft(struct Node *, int);
struct Node *insertRight(struct Node *, int);

int main()
{
    struct Node *root = NULL;
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

    if (isBST(root, INT_MIN, INT_MAX))
        printf("\nGiven tree is a BST");
    else
        printf("\nNope");

    // if (isBST_inorder(root))
    //     printf("\nGiven tree is a BST");
    // else
    //     printf("\nNope");
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
