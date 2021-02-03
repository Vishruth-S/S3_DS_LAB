// Program to remove the minimum element from a Binary Search Tree

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *root = NULL;

// Time complexity
// - Worst case (in case of skewed tree) - O(n) , Average case (for balanced tree) - O(logn)
int removeMinimum()
{
    if (root == NULL)
        return -1;
    struct Node *curr = root, *parent = NULL;
    while (curr->left) // keep going left so as to get minimum value
    {
        parent = curr;
        curr = curr->left;
    }
    int minimum = curr->data; // copy minimum value, so as to return later

    // now delete the node
    if (curr == root)       // if it is root node
        root = root->right; // then make new root as its right child

    else if (curr->right)           // if it has a right child
        parent->left = curr->right; // link this child to parent of current node

    else // if leaf node, no children
        parent->left = NULL;

    free(curr);
    return minimum;
}

struct Node *insertIntoTree(int);
void displayInorder(struct Node *);

int main()
{
    root = insertIntoTree(24);
    root = insertIntoTree(41);
    root = insertIntoTree(16);
    root = insertIntoTree(31);
    root = insertIntoTree(23);
    root = insertIntoTree(65);
    root - insertIntoTree(5);
    root - insertIntoTree(10);

    //    for reference
    //           24
    //         /    \
    //        16    41
    //       / \   / \
    //      5  23 31 65
    //       \
    //       10

    printf("\nBinary Search Tree Inorder\n");
    displayInorder(root);
    int mini = removeMinimum(root);
    printf("\n\nMinimum value: %d", mini);
    printf("\n\nBST inorder after removing minimum\n");
    displayInorder(root);
}

struct Node *insertIntoTree(int data)
{
    struct Node *curr = root, *parent = NULL;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    if (root == NULL)
        return newNode;

    while (curr)
    {
        parent = curr;
        if (data <= curr->data)
        {
            curr = curr->left;
            if (curr == NULL)
                parent->left = newNode;
        }
        else
        {
            curr = curr->right;
            if (curr == NULL)
                parent->right = newNode;
        }
    }

    return root;
}

void displayInorder(struct Node *root)
{
    if (root == NULL)
        return;
    displayInorder(root->left);
    printf("%d ", root->data);
    displayInorder(root->right);
}