#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int maxTriProd(int *arr, int size)
{
    int max = 0, prod;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            for (int k = 0; k < size; k++) {
                // controlliamo gli indici e non gli elementi
                // contenuti in quell'indice !(arr[i])
                // perchè se l'array in input contiene più occorrenze
                // dello stesso elemento, dobbiamo considerarle
                if (i != j && j != k && i != k)
                {
                    prod = arr[i] * arr[j] * arr[k];
                    if (prod > max)
                        max = prod;
                }
            }
    return max;
}

int *sommePrefisse(int *arr, int size)
{
    int *sp = malloc(sizeof(int) * size);
    sp[0] = arr[0];
    for (int i = 1; i < size; i++)
        sp[i] = sp[i-1] + arr[i];
    return sp;
}

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int size = 4;
    int arr[] = {1, -1, 9, 21};
    // printf("%d\n", maxTriProd(arr, size));
    printArray(sommePrefisse(arr, size), size);
}