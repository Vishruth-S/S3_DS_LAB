// Find maximum and minimum value in a binary search tree

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Time complexity
// - Worst case (in case of skewed tree) - O(n) , Average case (for balanced tree) - O(logn)
int FindMaximum(struct Node *root)
{
    if (root->right == NULL)
        return root->data;
    return FindMaximum(root->right);
}

int FindMinimum(struct Node *root)
{
    if (root->left == NULL)
        return root->data;
    return FindMinimum(root->left);
}

struct Node *insertIntoTree(struct Node *, int);
void displayInorder(struct Node *);

int main()
{
    struct Node *root = NULL;
    root = insertIntoTree(root, 12);
    root = insertIntoTree(root, 42);
    root = insertIntoTree(root, 13);
    root = insertIntoTree(root, 5);
    root = insertIntoTree(root, 18);
    root = insertIntoTree(root, 20);
    root = insertIntoTree(root, 35);
    displayInorder(root);
    int maxi = FindMaximum(root);
    int mini = FindMinimum(root);
    printf("\nMaximum: %d", maxi);
    printf("\nMinimum: %d", mini);
    return 0;
}

struct Node *insertIntoTree(struct Node *root, int data)
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