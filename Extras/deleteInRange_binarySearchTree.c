// Given a binary search tree and a range [low, high],
// Delete all elements falling in this range

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *deleteNode(struct Node *);

// Time complexity: O(n)
struct Node *deleteInRange(struct Node *root, int low, int high)
{
    if (root == NULL)
        return root;
    if (low <= root->data)
        root->left = deleteInRange(root->left, low, high);
    if (high >= root->data)
        root->right = deleteInRange(root->right, low, high);
    if (root->data >= low && root->data <= high)
        return deleteNode(root);

    return root;
}

struct Node *findMin(struct Node *);
struct Node *deleteNode(struct Node *root)
{
    if (!root->left)
    {
        struct Node *temp = root->right;
        root = NULL;
        return temp;
    }
    if (!root->right)
    {
        struct Node *temp = root->left;
        root = NULL;
        return temp;
    }

    struct Node *temp = findMin(root->right);
    root->data = temp->data;
    root->right = deleteNode(temp);
    return root;
}

struct Node *insertNode(struct Node *, int);
void display_inorder(struct Node *);

int main()
{
    struct Node *root = NULL;
    root = insertNode(root, 10);
    root = insertNode(root, 5);
    root = insertNode(root, 16);
    root = insertNode(root, 2);
    root = insertNode(root, 8);
    root = insertNode(root, 6);
    root = insertNode(root, 12);
    root = insertNode(root, 19);
    root = insertNode(root, 23);

    // For reference
    //        10
    //      /    \
    //     5     16
    //    / \   /  \
    //   2  8  12  19
    //     /        \
    //    6         23

    printf("\ninorder\n");
    display_inorder(root);

    int low, high;
    printf("\nEnter lower bound\n");
    scanf("%d", &low);
    printf("\nEnter higher bound\n");
    scanf("%d", &high);
    root = deleteInRange(root, low, high);

    printf("\nAfter deleting\n");
    display_inorder(root);
}

struct Node *findMin(struct Node *root)
{
    struct Node *curr = root;
    while (curr->left)
        curr = curr->left;
    return curr;
}

struct Node *insertNode(struct Node *root, int data)
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

void display_inorder(struct Node *root)
{
    if (root == NULL)
        return;
    display_inorder(root->left);
    printf("%d ", root->data);
    display_inorder(root->right);
}