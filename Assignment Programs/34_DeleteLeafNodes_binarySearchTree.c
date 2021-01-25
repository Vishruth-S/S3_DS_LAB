// Program to count and delete the leaf nodes in a Binary Search Tree

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

int countLeafNodes(struct Node *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;

    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

struct Node *removeLeafNodes(struct Node *root)
{
    if (root == NULL)
        return root;

    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }

    root->left = removeLeafNodes(root->left);
    root->right = removeLeafNodes(root->right);

    return root;
}

struct Node *insertIntoTree(struct Node *, int);
void displayInorder(struct Node *);

int main()
{
    struct Node *root = NULL;
    root = insertIntoTree(root, 24);
    root = insertIntoTree(root, 41);
    root = insertIntoTree(root, 16);
    root = insertIntoTree(root, 31);
    root = insertIntoTree(root, 23);
    root = insertIntoTree(root, 65);
    root - insertIntoTree(root, 5);
    printf("\nBinary Search Tree Inorder\n");
    displayInorder(root);
    int count = countLeafNodes(root);
    printf("\nNumber of leaf nodes: %d", count);
    removeLeafNodes(root);
    printf("\nBinary Search Tree Inorder After removing leaf nodes\n");
    displayInorder(root);
}

struct Node *insertIntoTree(struct Node *root, int data)
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