#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int *extractDigits(int num, int size)
{

    int *toReturn = malloc(sizeof(int) * size);
    for (int i = size - 1; i >= 0; i--)
    {
        toReturn[i] = num % 10;
        num /= 10;
    }
}

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int ramp10(int num)
{
    int numDigits = (int)floor(log10(num)) + 1;
    // int *nums = extractDigits(num);
    printArray(extractDigits(num, numDigits), numDigits);
}

int main()
{
    ramp10(20);
}