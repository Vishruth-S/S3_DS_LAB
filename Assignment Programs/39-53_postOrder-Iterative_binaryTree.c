// Program to perform a non-recursive postorder traversal on a binary tree

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Stack functions
void stackPush(struct Node *[], int *, struct Node *);
struct Node *stackPop(struct Node *[], int *);
bool stackEmpty(int);

// Postorder traversal - non-recursive
// Time complexity: O(n), Space complexity: Worst case - O(n), Average case - O(logn)
void postOrderTraversal(struct Node *root)
{
    if (root == NULL)
        return;

    struct Node *stack1[100], *stack2[100]; // creating 2 stacks
    int top1 = -1, top2 = -1;

    struct Node *curr;
    stackPush(stack1, &top1, root); // push root to the first stack

    while (!stackEmpty(top1)) // while stack 1 is not empty
    {
        curr = stackPop(stack1, &top1);            // pop from stack 1
        stackPush(stack2, &top2, curr);            // and push into stack 2
        if (curr->left)                            // if currently popped node has a left child
            stackPush(stack1, &top1, curr->left);  // then push that to stack1
        if (curr->right)                           // if currently popped node has a right child
            stackPush(stack1, &top1, curr->right); // then push that to stack1
    }
    while (!stackEmpty(top2)) // stack 2 will now have the required postorder
    {
        curr = stackPop(stack2, &top2); // pop elements
        printf("%d ", curr->data);      // and print them
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

    printf("\nPostOrder traversal\n");
    postOrderTraversal(root);
    return 0;
}

void stackPush(struct Node *stack[100], int *top, struct Node *node)
{
    if (*top == 99)
        return;
    stack[++*top] = node;
}

struct Node *stackPop(struct Node *stack[100], int *top)
{
    if (stackEmpty(*top))
        return NULL;
    return stack[(*top)--];
}

bool stackEmpty(int top)
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
