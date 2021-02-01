// Given a linked list of words, create a palindrome list from it
// by concatenating its reverse list to the given list

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char s[100];
    struct Node *next;
};

struct Node *insertAtHead(struct Node *, char[]);
void display(struct Node *);

struct Node *makePalindrome(struct Node *head)
{
    struct Node *curr = head, *end = head;
    struct Node *head2 = NULL;
    while (curr)
    {
        char temp[100];
        strcpy(temp, (curr->s));
        head2 = insertAtHead(head2, strrev(temp));

        if (curr->next == NULL)
            end = curr;
        curr = curr->next;
    }
    end->next = head2;
    return head;
}

int main()
{
    struct Node *head = NULL;
    head = insertAtHead(head, "mom");
    head = insertAtHead(head, "no");
    head = insertAtHead(head, "racecar");
    head = insertAtHead(head, "wow");
    printf("\nLinked list\n");
    display(head);
    head = makePalindrome(head);
    printf("\n\nLinked list after palindrome\n");
    display(head);
    printf("\n");
    return 0;
}

struct Node *insertAtHead(struct Node *head, char data[100])
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    strcpy(newNode->s, data);
    newNode->next = NULL;
    if (head)
        newNode->next = head;
    return newNode;
}

void display(struct Node *head)
{
    while (head)
    {
        printf("%s ", head->s);
        head = head->next;
    }
}