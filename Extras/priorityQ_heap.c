// Program to implement priorty Queue using Heap
// Here, the value of the element is its priority

#include <stdio.h>
#include <stdlib.h>

void heapify(int);
void swap(int *, int *);

// Heap array and size
int pq[1000];
int size = -1;

// To Insert into Heap
// Time complexity: O(logn)
void insertIntoHeap(int i)
{
    int curr = i;
    int parent = (curr - 1) / 2;
    while (parent >= 0 && pq[curr] > pq[parent])
    {
        swap(&pq[curr], &pq[parent]);
        curr = parent;
        parent = (curr - 1) / 2;
    }
}

// To remove from Heap
// Time complexity: O(logn)
void removeFromHeap()
{
    int last = pq[size];
    pq[0] = last;
    size--;
    heapify(0);
}

// To get element with max priority
// Time complexity: O(1)
int getMax()
{
    if (size == -1)
        return -1;
    return pq[0];
}

void printHeap()
{
    if (size == -1)
    {
        printf("\nQueue empty");
        return;
    }
    for (int i = 0; i <= size; i++)
        printf("%d ", pq[i]);
    printf("\n");
}

int main()
{
    int ch, el, maxP;
    do
    {
        printf("\n1.Insert into queue");
        printf("\n2.Delete from queue");
        printf("\n3.Get max priority element");
        printf("\n4.Display queue\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter element to insert: ");
            scanf("%d", &el);
            size++;
            pq[size] = el;
            insertIntoHeap(size);
            break;
        case 2:
            removeFromHeap();
            break;
        case 3:
            maxP = getMax();
            if (maxP == -1)
                printf("\nEmpty");
            else
                printf("Max priority element: %d\n", maxP);
            break;
        case 4:
            printHeap();
        }
    } while (ch < 5);

    return 0;
}

void heapify(int i)
{
    int largest = i;
    int leftChild = (2 * i) + 1;
    int rightChild = (2 * i) + 2;
    if (leftChild <= size && pq[leftChild] > pq[largest])
        largest = leftChild;
    if (rightChild <= size && pq[rightChild] > pq[largest])
        largest = rightChild;
    if (largest != i)
    {
        swap(&pq[i], &pq[largest]);
        heapify(largest);
    }
}

void swap(int *p, int *q)
{
    int t = *p;
    *p = *q;
    *q = t;
}