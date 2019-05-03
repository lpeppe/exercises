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
    int sum = 0;
    for (int i = 1; i <= size; i++)
    {
        for (int j = 0; j < i; j++)
            sum += arr[j];
        sp[i - 1] = sum;
        sum = 0;
    }
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
    int arr[] = {1, 1, 1, 2};
    printf("%d\n", maxTriProd(arr, size));
    // printArray(sommePrefisse(arr, size), size);
}