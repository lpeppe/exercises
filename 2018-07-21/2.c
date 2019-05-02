#include <stdlib.h>
#include <stdio.h>

// alloca un nuovo bucket e setta tutti gli elementi a 0.
int *newBucket(int size)
{
    int *p = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
        p[i] = 0;
    return p;
}

int add(int num, int *bucket, int bucketSize)
{
    // se il numero passato in input alla funzione è negativo
    //  l'inserimento fallisce
    if (num < 1)
        return 0;
    // prova ad inserire l'elemento nella prima posizione disponibile.
    // Se il bucket è pieno (non ci sono elementi pari a 0), 
    // l'inserimento fallisce
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
    // la grandezza del bucket viene passata come argomento
    // da riga di comando
    bucketSize = atoi(argv[1]);
    int *bucket = newBucket(bucketSize);
    // inserisci numeri nel bucket fin quando non si riempie
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