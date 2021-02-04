// Check if the two binary trees T1 and T2 are same or not.
// Out of these two trees T1 is represented with linked storage
// representation and T2 is represented with sequential storage representation.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Time complexity: O(n)
bool checkIfSame(int tree1[], int i, int n, struct Node *tree2)
{
    // base cases
    if (tree2 !=NULL && i >= n) // if tree2 has more nodes than tree1
        return false;
    if (tree2 == NULL && i < n) // if tree1 has more nodes than tree2
        return false;

    if (tree2 == NULL && i >= n) // if they have same number of nodes
        return true;

    // check if the values are same
    if (tree2->data != tree1[i])
        return false;

    // recursively check for each of the left and right sub-trees
    return checkIfSame(tree1, (2 * i + 1), n, tree2->left) 
        && checkIfSame(tree1, (2 * i + 2), n, tree2->right);
}

// Same logic as above, but a bit shorter code
// Time complexity: O(n)
bool checkIfSame_alternate(int tree1[], int i, int n, struct Node *tree2)
{
    if (tree2 == NULL && i >= n) // base case, both empty
        return true;

    if(tree2!=NULL && i<n) // both non-empty, so compare 
    {
        return(
            tree2->data == tree1[i] && // compare node values and recursively check for left and right subtrees
            checkIfSame(tree1, (2 * i + 1), n, tree2->left) && 
            checkIfSame(tree1, (2 * i + 2), n, tree2->right)
        );
    }
    
    // If it reaches here, it means one of the trees is empty while other is non-empty
    return false;
}

struct Node *createNode(int);
struct Node *insertLeft(struct Node *, int);
struct Node *insertRight(struct Node *, int);

int main()
{
    int tree1[] = {10, 5, 14, 3, 8, 11, 17, 1};
    int n = sizeof(tree1) / sizeof(tree1[0]);

    struct Node *tree2 = NULL;
    tree2 = createNode(10);
    insertLeft(tree2, 5);
    insertRight(tree2, 14);
    insertLeft(tree2->left, 3);
    insertRight(tree2->left, 8);
    insertLeft(tree2->right, 11);
    insertRight(tree2->right, 17);
    insertLeft(tree2->left->left, 1);

    //          Tree for reference
    //
    //               10
    //             /   \
    //            5    14
    //           / \  / \ 
    //          3  8 11 17
    //         /
    //        1

    if (checkIfSame(tree1, 0, n, tree2))
        printf("\nTrees are same\n");
    else
        printf("\nNope");
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