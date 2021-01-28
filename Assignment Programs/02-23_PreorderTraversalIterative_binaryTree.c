// Program to perform a non-recursive preorder traversal on a binary tree

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
void stackPop();
struct Node *stackTop();
bool stackEmpty();

// Preorder traversal
// Time complexity: O(n), Space complexity: Worst case - O(n), Average case - O(logn)
void preorderTraversal(struct Node *root)
{
    if (root == NULL)
        return;
    stackPush(root);
    while (!stackEmpty())
    {
        struct Node *curr = stackTop();
        stackPop();
        printf("%d ", curr->data);
        if (curr->right)
            stackPush(curr->right);
        if (curr->left)
            stackPush(curr->left);
    }
}

struct Node *createNode(int);
struct Node *insertLeft(struct Node *, int);
struct Node *insertRight(struct Node *, int);

int main()
{
    struct Node *root = NULL;
    root = createNode(1);
    insertLeft(root, 2);
    insertRight(root, 3);
    insertLeft(root->left, 4);
    insertRight(root->left, 5);
    insertLeft(root->right, 6);
    insertRight(root->right, 7);

    //    For reference 
    //          1
    //        /  \
    //       2    3
    //      / \  / \
    //     4   5 6  7
        
    printf("\nPreorder traversal\n");
    preorderTraversal(root);
    return 0;
}

void stackPush(struct Node *node)
{
    if (top == 99)
        return;
    stack[++top] = node;
}

struct Node *stackTop()
{
    if (!stackEmpty())
        return stack[top];
}

void stackPop()
{
    if (!stackEmpty())
        top--;
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
