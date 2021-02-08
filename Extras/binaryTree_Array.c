// Binary tree represented by Array

#include <stdio.h>

// inorder traversal
void inorder(int tree[], int i, int n)
{
    if (i >= n)
        return;

    inorder(tree, 2 * i + 1, n);
    if (tree[i] != 0)
        printf("%d ", tree[i]);
    inorder(tree, 2 * i + 2, n);
}

int main()
{
    int tree[100];
    printf("\nEnter nodes in level Order. Enter 0 for null value\n Enter -1 to exit\n");
    int node, i = 0;
    do
    {
        scanf("%d", &node);
        if (node != -1)
            tree[i++] = node;

    } while (node != -1);
    int n = i - 1;

    printf("\nBinary tree inorder\n");
    inorder(tree, 0, n);
    printf("\nBinary tree level order\n");
    for (int i = 0; i < n; i++)
        if (tree[i] != 0)
            printf("%d ", tree[i]);
    return 0;
}