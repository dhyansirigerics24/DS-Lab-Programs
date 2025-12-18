#include <stdio.h>
#define SIZE 10

int hashTable[SIZE];

void insert(int key)
{
    int index = key % SIZE;

    while (hashTable[index] != -1)
        index = (index + 1) % SIZE;

    hashTable[index] = key;
}

void display()
{
    int i;
    for (i = 0; i < SIZE; i++)
        printf("Index %d : %d\n", i, hashTable[i]);
}

int main()
{
    int i, key, n;

    for (i = 0; i < SIZE; i++)
        hashTable[i] = -1;

    printf("Enter number of keys: ");
    scanf("%d", &n);

    printf("Enter keys:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &key);
        insert(key);
    }

    printf("Hash Table:\n");
    display();

    return 0;
}
