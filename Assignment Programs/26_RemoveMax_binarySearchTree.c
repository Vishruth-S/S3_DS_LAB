// Find and delete maximum value in a Binary Search Tree

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
int removeMaximum()
{
    struct Node *curr = root, *parent = NULL;
    while (curr->right) // keep going right so as to get maximum value
    {
        parent = curr;
        curr = curr->right;
    }
    int maxi = curr->data; // copy maximum value

    if (curr == root) // if node to be deleted is root
    {
        root = curr->left; // then make root as its left child
        curr->left = NULL;
    }
    else if (curr->left) // if node to be deleted has a left child
    {
        parent->right = curr->left; // link this child to parent of current node
        curr->left = NULL;
    }
    else // if leaf node, no children
        parent->right = NULL;
    free(curr);
    return maxi;
}

struct Node *insertIntoTree(int);
void displayInorder(struct Node *);

int main()
{
    root = insertIntoTree(24);
    root = insertIntoTree(41);
    root = insertIntoTree(16);
    root = insertIntoTree(24);
    root - insertIntoTree(5);
    printf("\nBinary Search Tree Inorder\n");
    displayInorder(root);
    int maxi = removeMaximum();
    printf("\nMaximum: %d", maxi);
    printf("\nBST after removing maximum\n");
    displayInorder(root);
    return 0;
}

struct Node *insertIntoTree(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    if (root == NULL)
        return newNode;

    struct Node *curr = root, *parent = NULL;
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