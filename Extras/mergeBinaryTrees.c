// Given two binary trees, imagine that when you put one of them to cover the other,
// some nodes of the two trees are overlapped while the others are not.
// You need to merge them. The merge rule is that if two nodes overlap,
// then sum node values up as the new value of the merged node.
// Otherwise, the NOT null node will be used as the node of new tree.
// Refer: https://leetcode.com/problems/merge-two-binary-trees/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *mergeTrees(struct Node *tree1, struct Node *tree2)
{
    if (!tree1)
        return tree2;
    if (!tree2)
        return tree1;

    tree1->data += tree2->data;
    tree1->left = mergeTrees(tree1->left, tree2->left);
    tree1->right = mergeTrees(tree1->right, tree2->right);

    return tree1;
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
    tree2 = createNode(2);
    insertLeft(tree2, 1);
    insertRight(tree2, 3);
    insertRight(tree2->left, 4);
    insertRight(tree2->right, 7);

    //         for reference
    //    Tree 1          Tree 2
    //        1             2
    //       / \           / \                            
    //      3   2         1   3
    //     /               \   \                      
    //    5                 4   7
    //
    //           Expected
    //         	    3
    //             / \
	//            4   5
    //           / \   \ 
	//          5   4   7
    printf("\nTree1 in level order\n");
    levelOrderTraversal(tree1);
    printf("\nTree2 in level order\n");
    levelOrderTraversal(tree2);

    tree1 = mergeTrees(tree1, tree2);
    printf("\nMerged tree in level order\n");
    levelOrderTraversal(tree1);
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