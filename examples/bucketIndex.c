#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    int **buckets;
} HT;

void initHT(HT *ht, int B, int d)
{
    ht->buckets = malloc(sizeof(int *) * B);
    for (int i = 0; i < B; i++)
        ht->buckets[i] = malloc(sizeof(int) * d);
}

void printBucket(int *p, int d) {
    for(int i = 0; i < d; i++)
        printf("%d ", p[i]);
    printf("\n");
}

int main()
{
    HT ht;
    int B = 3, d = 3, num;
    initHT(&ht, B, d);
    for (int i = 0; i < B; i++)
        for (int j = 0; j < d; j++)
            ht.buckets[i][j] = i + j;
    // printf("%d\n", ht.buckets[1][1]);
    printBucket(ht.buckets[1], d);
    return 0;
}