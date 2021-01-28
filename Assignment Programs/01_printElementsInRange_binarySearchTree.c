// program that displays all the elements x
// in a binary search tree such that k1 <= x <= k2, where k1 and k2 are inputs

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

void printElementsInRange(struct Node *root, int k1, int k2)
{
    if (root == NULL)
        return;
    printElementsInRange(root->left, k1, k2);
    if (k1 <= root->data && root->data <= k2)
        printf("%d ", root->data);
    printElementsInRange(root->right, k1, k2);
}

void inorder(struct Node *);
struct Node *insertIntoTree(struct Node *, int);

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
    printf("\nBinary Search Tree Inorder\n");
    inorder(root);
    int k1, k2;
    printf("\nEnter k1 and k2\n");
    scanf("%d %d", &k1, &k2);
    printf("\nNodes having values in range (%d,%d)\n", k1, k2);
    printElementsInRange(root, k1, k2);
    return 0;
}

void inorder(struct Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
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
