#include "HashElement.h"
#include <malloc.h>
#include <time.h>

int main()
{
    bool ProgramProcess = true;
    while (ProgramProcess)
    {
        int SIZE = 10;
        srand(time(NULL));
        HashElement* HashTable = (HashElement*)malloc(sizeof(HashElement) * SIZE);
        for (int i = 0; i < SIZE; i++)
        {
            AddHashElement(rand() % 100 - 50, HashTable);
        }
        PrintHashTable(SIZE, HashTable);
        printf("Max Key:%d\n", SearchForMax(HashTable, SIZE));
        free(HashTable);
        int Choice;
        printf("Press \"1\" to restart program or any button to continue:");
        scanf_s("%d", &Choice);
        switch (Choice)
        {
        case 1:
            system("cls");
            Choice = 0;
            continue;
        default:
            ProgramProcess = false;
            break;
        }
    }
}
