//CSL201 DATA STRUCTURES LAB ----- VISHRUTH S, CS3A, 61
//CYCLE 4 QUESTION 1
//To insert a set of keys into a hash table of size m=13 using the division method and the collision resolution technique as linear probing.

#include <stdio.h>

#define SIZE 13

// Initializing hash table with zeroes
int hashTable[SIZE] = {0};

// ========== HASHING FUNCTION ========= //
void performHash(int inputArr[], int inputSize)
{
    int key;
    for (int i = 0; i < inputSize; i++) // for every element in input array
    {
        key = inputArr[i] % SIZE; // Finding index using the mod function

        if (hashTable[key] == 0)          // If empty
            hashTable[key] = inputArr[i]; //then just insert in that index
        else
        {
            int j;
            j = (key + 1) % SIZE; // else find the next index
            while (1)             // Repeat till an empty index is found
            {
                if (hashTable[j] == 0) // check if it is empty
                {
                    hashTable[j] = inputArr[i]; //then insert
                    break;                      //and exit out of loop
                }
                else
                {
                    j = (j + 1) % SIZE; // else go to next index
                }
            }
        }
    }
}

void printHashTable();

// Main function
int main()
{
    int inputArr[SIZE];
    int inputSize;

    printf("Enter size of input array\n");
    scanf("%d", &inputSize);
    if (inputSize > SIZE)
    {
        printf("\nSorry, Max size exceeded");
        return 0;
    }

    printf("Enter elements\n");
    for (int i = 0; i < inputSize; i++)
        scanf("%d", &inputArr[i]);

    performHash(inputArr, inputSize);
    printHashTable();

    return 0;
}

// To print the result hash table
void printHashTable()
{
    printf("\nHash table");
    printf("\nIndex:\t");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d\t", i);
    }
    printf("\nValue:\t");
    for (int i = 0; i < SIZE; i++)
    {
        hashTable[i] != 0 ? printf("%d\t", hashTable[i]) : printf("__\t");
    }
    printf("\n");
}