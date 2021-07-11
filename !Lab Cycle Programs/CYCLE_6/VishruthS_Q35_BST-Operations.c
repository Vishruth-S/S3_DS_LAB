//CSL201 DATA STRUCTURES LAB ----- VISHRUTH S, CS3A, 61
//CYCLE 6 QUESTION 2
//Program  to implement a binary search tree
//and perform insert, search and delete operations


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Binary Search Tree node structure
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int);
struct Node *FindMinimum(struct Node *);
void inorder(struct Node *);

// ================ TO INSERT A NEW NODE ================= //
// Method 1: Recursive
// Time complexity- Average case(Balanced trees): O(logn), Worst case(Skewed trees): O(n)
struct Node *insertNode(struct Node *root, int data)
{
    if (root == NULL)                                // if root is null,
        root = createNode(data);                     // then a new node is created
    else if (data <= root->data)                     // if data is less than current data,
        root->left = insertNode(root->left, data);   // then node to be inserted in left sub-tree
    else                                             // else if data is greater than current data
        root->right = insertNode(root->right, data); // then node to be inserted in right sub-tree

    return root;
}

// Method 2: Iterative
// Time complexity- Average case(Balanced trees): O(logn), Worst case(Skewed trees): O(n)
struct Node *insertNode_Iterative(struct Node *root, int data)
{
    struct Node *newNode = createNode(data); // new node is created
    if (root == NULL)                        // if root is null, then new node must be root node
        return newNode;                      // so return it

    struct Node *curr = root, *parent = NULL;
    while (curr) // traversing the tree
    {
        parent = curr;                   // points to parent node
        if (newNode->data <= curr->data) // if data is less than current data
        {
            curr = curr->left;          // then go to the left sub-tree
            if (curr == NULL)           // if current becomes null
                parent->left = newNode; // then new node should be inserted here
        }
        else // if data is greater than current data
        {
            curr = curr->right;          // then go to the right sub-tree
            if (curr == NULL)            // if current becomes null
                parent->right = newNode; // then new node should be inserted here
        }
    }

    return root;
}

// =================== TO SEARCH FOR NODE ===================== //
// Method 1: Recursive
// Time complexity- Average case(Balanced trees): O(logn), Worst case(Skewed trees): O(n)
bool Search(struct Node *root, int data)
{
    if (root == NULL) // if it reaches null, it means element doesn't exists
        return false;
    if (root->data == data) // if data is equal to search Query, then return true
        return true;

    else if (data <= root->data)          // if data is less than current data
        return Search(root->left, data);  // then continue searching in left sub-tree
    else                                  // else if data is greater than current data
        return Search(root->right, data); // then continue searching in right sub-tree
}

// Method 2: Iterative
// Time complexity- Average case(Balanced trees): O(logn), Worst case(Skewed trees): O(n)
bool Search_Iterative(struct Node *root, int data)
{
    struct Node *curr = root;
    while (curr) // traversing the tree
    {
        if (curr->data == data)      // if data is equal to search Query
            return true;             // return true
        else if (data <= curr->data) // else if data less than current data
            curr = curr->left;       // then go to left sub-tree
        else                         // else if data is greater than current data
            curr = curr->right;      // then go to right sub-tree
    }
    return false; // if it reaches here, it means curr = NULL, or data doesn't exist in tree
}


// =================== TO DELETE A NODE ===================== //
// Method 1: Recursive
// Time complexity- Average case(Balanced trees): O(logn), Worst case(Skewed trees): O(n)
struct Node *Delete(struct Node *root, int data)
{
    if (root == NULL) // if empty node, then return it;
        return root;
    else if (data < root->data)                  // if data less than current data
        root->left = Delete(root->left, data);   // then search for it in left sub-tree
    else if (data > root->data)                  // else if data is greater than current data
        root->right = Delete(root->right, data); // then search for it in right sub-tree

    else // once it reaches here, it means the current node is the node to be deleted
    {
        // case 1: Leaf node, No child
        if (root->left == NULL && root->right == NULL)
        {
            free(root);  // delete it
            root = NULL; // and set current value to null
        }
        // Case 2: Only one child
        else if (root->left == NULL || root->right==NULL) // only one child
        {
            struct Node *temp = root; // current node
            if (root->left) // if left child
                root = root->left; // change link to that of left child
            else // else if right child
                root = root->right; // change link to that of right child
            free(temp);// and delete the current node
        }
        // Case 3: Both children
        else
        {
            struct Node *temp = FindMinimum(root->right);  // find minimum of right node (can also be replaced with FindMaximum(root->left))
            root->data = temp->data;                       // and set current node equal to that value
            root->right = Delete(root->right, temp->data); // and delete that node
        }
    }
    return root;
}

// Method 2: Itertaive
// Time complexity- Average case(Balanced trees): O(logn), Worst case(Skewed trees): O(n)
struct Node *Delete_2(struct Node *root, int data)
{
    struct Node *curr = root, *parent = NULL;
    // Finding the node to be deleted
    while (curr && curr->data != data)
    {
        parent = curr;
        if (data < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }
    if (!curr)
    {
        printf("\nNode to be deleted does not exist in Tree\n");
        return root;
    }

    // CASE 1 : LEAF NODE, NO CHILDREN
    if (!curr->left && !curr->right)
    {
        // if node is root node
        if (parent == NULL)
            return NULL;

        if (parent->left == curr) // if node to be deleted is left child of parent
            parent->left = NULL;  // then set parent->left to NULL
        else                      // else if node to be deleted is right child of parent
            parent->right = NULL; // then set parent->right to NULL

        // Delete the current node
        free(curr);
    }

    // CASE 2: ONLY 1 CHILD
    else if (!curr->left || !curr->right)
    {
        struct Node *child = curr->left ? curr->left : curr->right;

        // if node is root node
        if (parent == NULL)
            return child;

        if (parent->left == curr)  // if node to be deleted is left child of parent
            parent->left = child;  // then set parent->left to child
        else                       // if node to be deleted is right child of parent
            parent->right = child; // then set parent->right to child
    }

    // CASE 3: BOTH CHILDREN
    else
    {
        // Find the inorder succesor (smallest node on right sub-tree)
        struct Node *succesor = curr->right;
        struct Node *succesor_parent = NULL;
        while (succesor->left)
        {
            succesor_parent = succesor;
            succesor = succesor->left;
        }

        if (succesor_parent == NULL)       // This is true if inorder_succesor is right child of node to be deleted
            curr->right = succesor->right; // Then set right child as succesor's right child
        else
            succesor_parent->left = succesor->right; // Else set parent's left child as successor's child

        curr->data = succesor->data; // Swap data of node to be deleted with that of the inorder succesor
        free(succesor);              // and delete inorder succesor
    }
    
    return root;
}

// ======= MAIN function ======== //
int main()
{
    struct Node *root = NULL;
    int ch, data, queryData;
    do
    {
        printf("\n\n1.Insert\n2.Search\n3.Delete\n4.Display (Inorder)\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter value to be inserted\n");
            scanf("%d", &data);
            root = insertNode(root, data);
            break;
        case 2:
            printf("\nEnter value to be searched\n");
            scanf("%d", &queryData);
            if (Search_Iterative(root, queryData))
                printf("\nElement found ");
            else
                printf("\nElement not found ");
            break;
        case 3:
            printf("\nEnter value to be deleted\n");
            scanf("%d", &queryData);
            root = Delete(root, queryData);
            // root = Delete_2(root, queryData);
            printf("\nElement deleted successfully (if it exists)");
            break;
        case 4:
            printf("\nBinary Search Tree Inorder\n");
            inorder(root);
        }
    } while (ch < 5);
}

// ====== Additional helper functions ======= //
// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Function to find minimum value node in a sub-tree
struct Node *FindMinimum(struct Node *root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

// For Inorder Traversal
void inorder(struct Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
