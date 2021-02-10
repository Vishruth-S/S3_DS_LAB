// Program to find the sibling of a given node in a binary Search Tree.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Method 1 - Iterative
// Time complexity: Worst case: O(n), Average case: O(logn). Space complexity: O(1)
int findSibling(struct Node *root, int data)
{
    if (root == NULL)
        return -1;

    struct Node *curr = root, *parent = NULL;
    while (curr) // first find the node and its parent
    {
        parent = curr;
        if (data < curr->data)
            curr = curr->left;
        else
            curr = curr->right;

        if (curr && curr->data == data)
            break;
    }
    struct Node *sibling = NULL;
    if (parent->left && parent->left == curr) // if the node is left child of parent
        sibling = parent->right;              // then the right child is the sibling

    if (parent->right && parent->right == curr) // if the node is right child of parent
        sibling = parent->left;                 // then the left child is the sibling

    int siblingData = -1;
    if (sibling)                     // if sibling is not NULL
        siblingData = sibling->data; // then copy the data

    return siblingData; // and return it
}

// Method 2 - Recursive implementation of the above logic
// Time complexity: Worst case: O(n), Average case: O(logn). Space complexity: O(logn)
int findSibling2(struct Node *root, int sibling, int data)
{
    if (root->left && root->right) // check if current node has both children
    {
        if (root->left->data == data)       // if left child is the target node
            return root->right->data;       // then right child is the sibling
        else if (root->right->data == data) // else if right child is the target node
            return root->left->data;        // then left child is the sibling
    }
    // recursively check on left and right sub-trees
    if (root->left)
        sibling = findSibling2(root->left, sibling, data);
    if (root->right)
        sibling = findSibling2(root->right, sibling, data);

    return sibling;
}

void inorder(struct Node *);
struct Node *insertIntoTree(struct Node *, int);

int main()
{
    struct Node *root = NULL;
    root = insertIntoTree(root, 12);
    root = insertIntoTree(root, 42);
    root = insertIntoTree(root, 8);
    root = insertIntoTree(root, 5);
    root = insertIntoTree(root, 10);
    root = insertIntoTree(root, 55);
    root = insertIntoTree(root, 6);
    root = insertIntoTree(root, 48);
    root = insertIntoTree(root, 69);

    //        Tree for reference
    //               12
    //             /   \
    //           8     42
    //          / \     \
    //         5  10    55
    //          \      / \
    //           6    48 69

    printf("\nBinary Search Tree Inorder\n");
    inorder(root);
    int data;
    printf("\nEnter data of node whose sibling to be found\n");
    scanf("%d", &data);
    int sibling = findSibling(root, data);
    // int sibling = findSibling2(root, -1, data);
    if (sibling == -1)
        printf("\nNo sibling exists\n");
    else
        printf("\nSibling of %d is %d\n", data, sibling);
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
