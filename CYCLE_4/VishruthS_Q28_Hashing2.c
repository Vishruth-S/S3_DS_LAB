//CSL201 DATA STRUCTURES LAB ----- VISHRUTH S, CS3A, 61
//CYCLE 4 QUESTION 2
//Given a natural language text, store each words in a hash table of size m=SIZE using the mod function. 
//Find the number of key comparisons for a successful search, if the collision resolution technique used is 1) linear probing 2) Quadratic probing

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 26

// ===== Inserting elements into hash table, using Linear probing ====== //
void hashWithLinearProbing(char word[], char hashTable[][20])
{
    int key;
    key = (int)(tolower(word[0]) - 'a') % SIZE; // Hash function "mod" is applied to first letter of word
    int j = 0;                                  // For moving to next indices, in case of collision
    while (hashTable[key + j][0] != '0')        // If already filled
    {
        j++;               // then move to next location, as per linear probing
        if (key + j >= SIZE) // If index overflows size
            j = -SIZE + j; // Reset to 0
    }
    strcpy(hashTable[key + j], word); // Copy the word to the hashTable at obtained index
}

// ===== Inserting elements into hash table, using Quadratic probing ===== //
void hashWithQuadraticProbing(char word[], char hashTable[][20])
{
    int key;
    key = (int)(tolower(word[0]) - 'a') % SIZE; // Hash function "mod" is applied to first letter of word
    int i = 0, j = 0;                           // For moving to next indices, in case of collision
    while (hashTable[key + j][0] != '0')        // If already filled
    {
        i++;
        j = i * i;           // then move to next location, as per Quadratic probing
        if (key + j >= SIZE) // If index overflows size
            j = -SIZE + j;   // Reset to 0
    }
    strcpy(hashTable[key + j], word); // Copy the word to the hashTable at obtained index
}

// ======== Search for a word using Linear probing ======== //
void searchLinearProbing(char queryWord[], char hashTable[][20])
{
    int count = 0, j = 0;
    int key = (int)(tolower(queryWord[0]) - 'a') % SIZE; // Applying mod function with first letter
    while (strcmp(hashTable[key + j], queryWord) != 0)   // While not found
    {
        count++;                                          // increase count of comparisons
        j++;                                              // move to next index as per linear probing
        if (key + j >= SIZE)                              // If index overflows size
            j = -SIZE + j;                                // Reset to 0
        if (hashTable[key + j][0] == '0' || count > SIZE) // If it reaches an empty index or comparisons exceed SIZE, it means element doesn't exist
        {
            printf("Element Not found\n");
            printf("Number of comparisons made: %d\n", count);
            return;
        }
    }
    printf("Element found at index %d\n", key + j);    // Print the index
    printf("Number of comparisons made: %d\n", count); // and count of comparisons
}

// ======== Search for a word using Quadratic probing ======== //
void searchQuadraticProbing(char queryWord[], char hashTable[][20])
{
    int count = 0, i = 0, j = 0;
    int key = (int)(tolower(queryWord[0]) - 'a') % SIZE; // Applying mod function with first letter
    while (strcmp(hashTable[key + j], queryWord) != 0)   // While not found
    {
        count++; // increase count of comparisons
        i++;
        j = i * i;                                        // move to next index as per Quadratic probing
        if (key + j >= SIZE)                              // If index overflows size
            j = -SIZE + j;                                // Reset to 0
        if (hashTable[key + j][0] == '0' || count > SIZE) // If it reaches an empty index or comparisons exceed SIZE, it means element doesn't exist
        {
            printf("Element Not found\n");
            printf("Number of comparisons made: %d\n", count);
            return;
        }
    }
    printf("Element found at index %d\n", key + j);    // Print the index
    printf("Number of comparisons made: %d\n", count); // and count of comparisons
}

// ======== Additional Functions ======== //
void initializeHashTable(char[][20]);
void printHashtables(char[][20], char[][20]);

// ==== MAIN FUNCTION ===== //
int main()
{
    char hashTable1[SIZE][20];
    char hashTable2[SIZE][20];
    initializeHashTable(hashTable1);
    initializeHashTable(hashTable2);

    int n;
    char word[20];
    char q[20];
    printf("Enter number of words\n");
    scanf("%d", &n);
    if (n > SIZE)
    {
        printf("\nSorry, max size exceeded");
        return 0;
    }

    printf("Enter the words\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%s", word);
        hashWithLinearProbing(word, hashTable1);
        hashWithQuadraticProbing(word, hashTable2);
    }
    printHashtables(hashTable1, hashTable2);

    printf("\nEnter word to search for\n");
    scanf("%s", q);
    printf("\nIn linear probing hash table:\n");
    searchLinearProbing(q, hashTable1);
    printf("\nIn quadratic probing hash table\n");
    searchQuadraticProbing(q, hashTable2);

    return 0;
}

// === To initiliaze hash table with empty ('0') values === //
void initializeHashTable(char hashTable[][20])
{
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < 20; j++)
        {
            hashTable[i][j] = '0';
            if (j == 19)
                hashTable[i][j] = '\0';
        }
}

// ===== To print the hash tables ======= //
void printHashtables(char hashTable1[][20], char hashTable2[][20])
{
    printf("\nLinear probing\t\t\tQuadratic Probing\n");
    printf("Index:\t");
    printf("\tValue\t");
    printf("\tIndex:\t");
    printf("\tValue\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d\t\t", i);
        hashTable1[i][0] != '0' ? printf("%s\t\t", hashTable1[i]) : printf("__\t\t");
        printf("%d\t\t", i);
        hashTable2[i][0] != '0' ? printf("%s\t\t", hashTable2[i]) : printf("__\t\t");
        printf("\n");
    }
}