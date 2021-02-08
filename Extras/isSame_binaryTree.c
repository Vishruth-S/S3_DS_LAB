// Check if 2 binary trees are same

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
bool isSameTree(struct Node *root1, struct Node *root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;

    if (root1 == NULL || root2 == NULL)
        return false;

    return root1->data == root2->data &&
           isSameTree(root1->left, root2->left) &&
           isSameTree(root1->right, root2->right);
}

struct Node *createNode(int);
struct Node *insertLeft(struct Node *, int);
struct Node *insertRight(struct Node *, int);
void levelOrderTraversal(struct Node *);

int main()
{
    struct Node *tree1 = NULL;
    tree1 = createNode(1);
    insertLeft(tree1, 3);
    insertRight(tree1, 2);
    insertLeft(tree1->left, 5);

    struct Node *tree2 = NULL;
    tree2 = createNode(1);
    insertLeft(tree2, 3);
    insertRight(tree2, 4);
    insertLeft(tree2->left, 5);

    //         for reference
    //    Tree 1          Tree 2
    //        1             1
    //       / \           / \                            
    //      3   2         3   2
    //     /             /
    //    5             5
    //

    printf("\nTree1 in level order\n");
    levelOrderTraversal(tree1);
    printf("\nTree2 in level order\n");
    levelOrderTraversal(tree2);

    if (isSameTree(tree1, tree2))
        printf("\nTrees are same");
    else
        printf("\nTrees are not same");
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

// For level order
struct Node *q[100];
int front = -1, rear = -1;
void qPush(struct Node *);
void qPop();
struct Node *qFront();
bool qEmpty();

void levelOrderTraversal(struct Node *root)
{
    if (root == NULL)
        return;
    qPush(root);
    struct Node *curr = NULL;
    while (!qEmpty())
    {
        curr = qFront();
        qPop();
        printf("%d ", curr->data);
        if (curr->left)
            qPush(curr->left);
        if (curr->right)
            qPush(curr->right);
    }
}

void qPush(struct Node *node)
{
    if (rear == 99)
        return;
    if (qEmpty())
        ++front;
    q[++rear] = node;
}

void qPop()
{
    if (!qEmpty())
    {
        if (front == rear)
            front = rear = -1;
        else
            ++front;
    }
}

struct Node *qFront()
{
    if (qEmpty())
        return NULL;
    return q[front];
}

bool qEmpty()
{
    return front == -1 && rear == -1;
}