#include <stdlib.h>
#include <stdio.h>

int *newBucket(int size)
{
    int *p = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
        p[i] = 0;
    return p;
}

int add(int num, int *bucket, int bucketSize)
{
    if (num < 1)
        return 0;
    for (int i = 0; i < bucketSize; i++)
    {
        if (bucket[i] == 0)
        {
            bucket[i] = num;
            return 1;
        }
    }
    return 0;
}

int main(int argc, char **argv)
{
    int num, bucketSize, temp;
    if (argc < 2)
        return 0;
    bucketSize = atoi(argv[1]);
    int *bucket = newBucket(bucketSize);
    while (1)
    {
        printf("Inserisci il numero: ");
        scanf("%d", &num);
        // if (num > 0)
        //     if (!add(num, bucket, bucketSize))
        //         break;
        if (num > 0)
        {
            temp = add(num, bucket, bucketSize);
            if (temp == 0)
                break;
        }
    }
    return 0;
}