// Program to perform Iterative Inorder Traversal on a Binary Tree

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Stack and its functions
struct Node *stack[100];
int top = -1;
void stackPush(struct Node *);
struct Node *stackPop();
bool stackEmpty();

// Inorder traversal - non-recursive
// Time complexity: O(n), Space complexity: Worst case - O(n), Average case - O(logn)
void inorderTraversal(struct Node *root)
{
    if (root == NULL)
        return;

    struct Node *curr = root;
    while (curr || !stackEmpty())
    {
        if (curr)
        {
            stackPush(curr);
            curr = curr->left;
        }
        else
        {
            curr = stackPop();
            printf("%d ", curr->data);
            curr = curr->right;
        }
    }
}

struct Node *createNode(int);
struct Node *insertLeft(struct Node *, int);
struct Node *insertRight(struct Node *, int);

int main()
{
    struct Node *root = NULL;
    root = createNode(7);
    insertLeft(root, 5);
    insertRight(root, 10);
    insertLeft(root->left, 2);
    insertRight(root->left, 6);
    insertLeft(root->right, 8);
    insertRight(root->right, 14);

    //    For reference
    //          7
    //        /  \
    //       5    10
    //      / \  / \
    //     2  6 8  14

    printf("\nInorder traversal\n");
    inorderTraversal(root);
    return 0;
}
void stackPush(struct Node *node)
{
    if (top == 99)
        return;
    stack[++top] = node;
}

struct Node *stackPop()
{
    if (stackEmpty())
        return NULL;
    return stack[top--];
}

bool stackEmpty()
{
    return top == -1;
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
