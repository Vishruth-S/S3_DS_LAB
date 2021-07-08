// Program to implement priorty Queue using Heap

#include <stdio.h>
#include <stdlib.h>

void heapify(int);
void swap(struct Item *, struct Item *);
void printHeap();

// each Item consists of a value and priority
struct Item
{
    int val;
    int priority;
};

// Heap array and size
struct Item pq[1000];
int size = -1;

// To Insert into Heap
// Time complexity: O(logn)
void insertIntoHeap(int i)
{
    int curr = i;
    int parent = (curr - 1) / 2;
    while (parent >= 0 && pq[curr].priority > pq[parent].priority)
    {
        swap(&pq[curr], &pq[parent]);
        curr = parent;
        parent = (curr - 1) / 2;
    }
}

// To remove from Heap
// Time complexity: O(logn)
int removeFromHeap()
{
    if (size == -1)
        return -1;
    struct Item last = pq[size];
    int deleted = pq[0].val;
    pq[0] = last;
    size--;
    heapify(0);
    return deleted;
}

// To get element with max priority
// Time complexity: O(1)
int getMax()
{
    if (size == -1)
        return -1;
    return pq[0].val;
}

int main()
{
    int ch, maxP, del;
    int val, priority;
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
            scanf("%d", &val);
            printf("\nEnter Priority of element: ");
            scanf("%d", &priority);
            size++;
            pq[size].val = val;
            pq[size].priority = priority;
            insertIntoHeap(size);
            break;
        case 2:
            del = removeFromHeap();
            if (del == -1)
                printf("\nEmpty");
            else
                printf("Deleted: %d\n", del);
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
    if (leftChild <= size && pq[leftChild].priority > pq[largest].priority)
        largest = leftChild;
    if (rightChild <= size && pq[rightChild].priority > pq[largest].priority)
        largest = rightChild;
    if (largest != i)
    {
        swap(&pq[i], &pq[largest]);
        heapify(largest);
    }
}

void printHeap()
{
    if (size == -1)
    {
        printf("\nQueue empty");
        return;
    }
    printf("\n---Priority Queue---\nValue   Priority\n");
    for (int i = 0; i <= size; i++)
    {
        printf("%2d%10d\n", pq[i].val, pq[i].priority);
    }
    printf("\n");
}

void swap(struct Item *p, struct Item *q)
{
    struct Item t = *p;
    *p = *q;
    *q = t;
}