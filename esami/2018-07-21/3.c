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
    // alloca memoria per l'array di putatori ai bucket
    ht->buckets = malloc(sizeof(int *) * B);
    for (int i = 0; i < B; i++)
    {
        // alloca memoria per ogni bucket
        ht->buckets[i] = malloc(sizeof(int) * d);
        initBucket(ht->buckets[i], d);
    }
}

// libera la memoria
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

// funzione uguale a quella dell'esercizio 2
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
    int count = 0;
    // prova ad inserire l'elemento in un bucket.
    // inizialmente si prova ad inserire nel bucket di indice h(B, val)
    // se il bucket è pieno si prova con il successivo, fino a trovarne uno pieno
    // se sono tutti pieni la funzione restituisce 0. Il contatore serve a mantenere
    // il conto di quanti bucket abbiamo provato. I viene incrementato modulo B in
    // modo tale che quando arriviamo a provare l'ultimo bucket e scopriamo che anche quello
    // è pieno possiamo ripartire dal primo. 
    for (int i = h(B, val); count < B; i = (i + 1) % B)
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
    // inserisci elementi nella HT fin quando non è piena
    while (1)
    {
        printf("Inserisci un numero: ");
        scanf("%d", &num);
        // se insert restituisce 0 significa che la HT è piena.
        // ricorda !0 = 1 (quando insert restituisce 0 si entra nell'if)
        if (!insert(*ht, num, B, d))
            break;
    }
    freeMemory(ht, B);
}