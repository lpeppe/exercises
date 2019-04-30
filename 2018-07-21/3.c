#include <stdlib.h>
#include <stdio.h>
#include "htlib.h"

void initBucket(int *bucket, int size)
{
    for (int i = 0; i < size; i++)
        bucket[i] = 0;
}

void initHT(HT *ht, int B, int d)
{
    ht->buckets = malloc(sizeof(int *) * B);
    for (int i = 0; i < B; i++)
    {
        ht->buckets[i] = malloc(sizeof(int) * d);
        initBucket(ht->buckets[i], d);
    }
}

void freeMemory(HT *ht, int B)
{
    for (int i = 0; i < B; i++)
        free(ht->buckets[i]);
    free(ht);
}

int h(int B, int val)
{
    return val % B;
}

int add(int *arr, int numero, int dim)
{
    if (numero <= 0)
        return 0;
    for (int i = 0; i < dim; i++)
    {
        if (arr[i] == 0)
        {
            arr[i] = numero;
            return 1;
        }
    }
    return 0;
}

int insert(HT ht, int val, int B, int d)
{
    int index = h(B, val);
    int count = 0;
    for (int i = index; count < B; i = (i + 1) % B)
    {
        if (add(ht.buckets[i], val, d))
            return 1;
        count++;
    }
    return 0;
}

int main()
{
    HT *ht = malloc(sizeof(HT));
    int B = 2, d = 3, num;
    initHT(ht, B, d);
    while (1)
    {
        printf("Inserisci un numero: ");
        scanf("%d", &num);
        if (!insert(*ht, num, B, d))
            break;
    }
    freeMemory(ht, B);
}