#include "HashElement.h"

int HashFunction(int Data)
{
    return abs(Data%10);
}

void PrintHashTable(int SIZE,HashElement* HashTable)
{
    printf("Hash Function\t\tKey\n");
    int Index = 0;
    for (int i = 0; i < SIZE; i++)
    {
        printf("   %d", i);
        printf("\t\t\t");
        while (HashTable[i].Data[Index] != -842150451)
        {
            printf("%d ", HashTable[i].Data[Index]);
            Index++;
            if (Index == 6)
                break;
        }
        Index = 0;
        printf("\n");
    }
}

void AddHashElement(int key, HashElement*& HashTable)
{
    int Index = 0;
    while (HashTable[HashFunction(key)].Data[Index] !=-842150451)
    {
        Index++;
        if (Index == 6)
            return;
    }

    HashTable[HashFunction(key)].Data[Index] = key;
    HashTable[HashFunction(key)].Key = HashFunction(key);
}

int SearchForMax(HashElement* HashTable,int SIZE)
{
    int Index = 0;
    int* arr = (int*)malloc(sizeof(int) * SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (HashTable[i].Data[j] != -842150451)
            {
                arr[Index] = HashTable[i].Data[j];
                Index++;
            }
            else
                break;
        }
    }

    int max = arr[0];

    for (int i = 1; i < SIZE; i++)
    {
        if (max < arr[i])
            max = arr[i];
    }
    free(arr);
    return max;
}
