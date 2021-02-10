// Given a binary search tree, find the second largest element

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// ======== Method 1 - Using inorder traversal array. ========== //
// Logic: Inorder traversal of a BST always gives elements in sorted order.
// So second largest element will simply be the second last element of the inorder array.
// Time complexity: O(logN) for balanced trees, O(N) for skewed trees. Space complexity: O(N)
int inorderArray[100];
int idx = 0;
void inorderTraversal(struct Node *root)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    inorderArray[idx++] = root->data;
    inorderTraversal(root->right);
}
int findSecondLargest(struct Node *root)
{
    inorderTraversal(root);       // perform inorder travesal and fill up the array
    if (idx == 1)                 // corner case, when there is only one node
        return inorderArray[idx]; // then second largest will be that node itself
    return inorderArray[idx - 2]; // else second largest is the second last element of this array
}

// Note: In the above method, Reverse Inorder-traversal can also be done,
// Then the second largest would be the second element of the array thus generated.

// ============ Method 2 - Using largest ============ //
// Logic: Find the largest element first.
// If largest has a left subtree, then second largest will be maximum value in its left subtree
// Else, second largest will be the parent of largest.
// Time complexity: O(logN) for balanced trees, O(N) for skewed trees. Space complexity: O(1)
int findSecondLargest2(struct Node *root)
{
    if (root == NULL)
        return -1;

    struct Node *largest = root, *parent = NULL;
    while (largest->right) //first find the largest element and its parent
    {
        parent = largest;
        largest = largest->right;
    }

    int secondLargest = root->data;
    if (largest->left) // if it has a left sub-tree
    {
        struct Node *temp = largest->left;
        while (temp->right) // then find the largest in the left sub-tree
            temp = temp->right;
        secondLargest = temp->data; // and this will be the second largest element in the tree
    }
    else if (parent != NULL)
        secondLargest = parent->data; // else, parent will be the second largest

    return secondLargest;
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
    int secondLargest = findSecondLargest(root);
    printf("\nSecond largest: %d", secondLargest);
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
