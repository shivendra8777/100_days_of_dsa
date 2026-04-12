/*Problem Statement
Implement a hash table using quadratic probing with formula:
h(k, i) = (h(k) + i*i) % m
*/
#include <stdio.h>
#include <string.h>

#define EMPTY -1

int table[100];

// insert function
void insert(int key, int m)
{
    int i = 0;
    int index;

    printf("Inserting %d\n", key);

    while(i < m)
    {
        index = (key % m + i*i) % m;

        if(table[index] == EMPTY)
        {
            table[index] = key;
            printf("Placed at index %d\n", index);
            return;
        }
        else
        {
            printf("Collision at index %d → trying i = %d\n", index, i+1);
        }

        i++;
    }

    printf("Hash Table Full!\n");
}

// search function
void search(int key, int m)
{
    int i = 0;
    int index;

    printf("Searching %d\n", key);

    while(i < m)
    {
        index = (key % m + i*i) % m;

        if(table[index] == key)
        {
            printf("FOUND\n");
            return;
        }
        else if(table[index] == EMPTY)
        {
            printf("NOT FOUND\n");
            return;
        }

        i++;
    }

    printf("NOT FOUND\n");
}

int main()
{
    int m, n;
    char op[10];
    int value;

    printf("Enter table size: ");
    scanf("%d", &m);

    // initialize table
    for(int i = 0; i < m; i++)
        table[i] = EMPTY;

    printf("Enter number of operations: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        printf("Enter operation: ");
        scanf("%s", op);

        if(strcmp(op, "INSERT") == 0)
        {
            scanf("%d", &value);
            insert(value, m);
        }
        else if(strcmp(op, "SEARCH") == 0)
        {
            scanf("%d", &value);
            search(value, m);
        }
    }

    return 0;
}