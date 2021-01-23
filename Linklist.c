#include <stdio.h>

#include <malloc.h>

#include <stdlib.h>

void Insert_Beg();

void Insert_Any();

void insert_end();

void Display();

void Delete_Beg();

void Delete_Any();

void Delete_end();



struct node

{

	int data;

	struct node *link;

} * HEADER, *ptr1, *ptr2, *newptr;

int main()

{

	HEADER = (struct node *)malloc(sizeof(struct node));

	HEADER->link = NULL;

	int x;

	while (1)

	{

		printf("\nSingle Linked List\n");

		printf("\n_________Menu__________ \n");

		printf("Insert\t:\t1\nDisplay\t:\t2\nDelete\t:\t3\nExit\t:\t4");

		printf("\n______________________\n");

		printf("\nEnter the Choice 1 to 4:");

		scanf("%d", &x);

		if (x == 1)

		{

			while (1)

			{

				printf("\n1\t:\tInsert at the beginnig\n2\t:\tInsert at Any Position\n3\t:\tInsert at End\n");

				printf("\nEnter the Choice 1 to 3:");

				scanf("%d", &x);

				if (x == 1)

				{

					Insert_Beg();

					break;

				}

				else if (x == 2)

				{

					Insert_Any();

					break;

				}

				else if (x == 3)

				{

					insert_end();

					break;

				}

				else

					printf("Invalid Try again");

			}

		}

		else if (x == 2)

			Display();

		else if (x == 3)

		{

			while (1)

			{

				printf("\n1\t:\tDelete at beginnig\n2\t:\tDelete at Any Position\n3\t:\tDelete at End\n");

				printf("\nEnter the Choice 1 to 3:");

				scanf("%d", &x);

				if (x == 1)

				{

					Delete_Beg();

					break;

				}

				else if (x == 2)

				{

					Delete_Any();

					break;

				}

				else if (x == 3)

				{

					Delete_end();

					break;

				}

				else

					printf("Invalid Tryagain");

			}

		}

		else if (x == 4)

			break;

		else

			printf("Invalid Tryagain");

	}

}



void Insert_Beg()

{

	int number;

	newptr = (struct node *)malloc(sizeof(struct node));

	printf("\nEnter The Data\t:");

	scanf("%d", &number);

	if (HEADER->link == NULL)

	{

		newptr->link = NULL;

		HEADER->link= newptr;

		newptr->data = number;

	}

	else

	{

		newptr->link = HEADER->link;

		HEADER->link = newptr;

		newptr->data = number;

		HEADER->link = newptr;

	}

}



void Insert_Any()

{

	int number, key;

	newptr = (struct node *)malloc(sizeof(struct node));

	printf("\nEnter The Data\t:");

	scanf("%d", &number);

	printf("\nEnter The key\t:");

	scanf("%d", &key);

	ptr1 = HEADER->link;

	while ((ptr1 != NULL) && (ptr1->data != key))

		ptr1 = ptr1->link;

	if (ptr1 == NULL)

		printf("\nKey Not available in the list");

	else

	{

		newptr->link = ptr1->link;

		ptr1->link = newptr;

		newptr->data = number;

	}

}

void insert_end()

{

	int number;

	ptr1 = HEADER;

	newptr = (struct node *)malloc(sizeof(struct node));

	printf("\nEnter The Data\t:");

	scanf("%d", &number);

	while (ptr1->link != NULL)

		ptr1 = ptr1->link;

	ptr1->link = newptr;

	newptr->data = number;

	newptr->link = NULL;

}

void Display()

{

	ptr1 = HEADER->link;

	printf("\nSingle Link List is \n");

	do

	{

		printf("%d\t", ptr1->data);

		ptr1 = ptr1->link;

	} while (ptr1 != NULL);

}

void Delete_Beg()

{

	ptr1 = HEADER->link;

	if (ptr1 == NULL)

		printf("List empty");

	else

	{

		HEADER->link = ptr1->link;

		free(ptr1);

	}

}

void Delete_Any()

{

	int key;

	ptr2 = HEADER;

	ptr1=ptr2->link;

	printf("\nEnter The key\t:");

	scanf("%d", &key);

	if (ptr2->link  == NULL)

		printf("List empty");

	while (ptr1->link == NULL)

	{

	if (ptr1->data == key)

	{

		ptr2=ptr1;

		ptr1=ptr1->link;	

	}

	else

	{

		ptr2->link=ptr1->link;

	}

	free(ptr1);

	}

}

void Delete_end()

{

	ptr1 = HEADER;

	if (ptr1->link == NULL)

		printf("List empty");

	else

	{

		while (ptr1->link != NULL)

		{

			ptr2 = ptr1;

			ptr1 = ptr1->link;

		}

		ptr2->link = NULL;

		free(ptr1);

	}

}
