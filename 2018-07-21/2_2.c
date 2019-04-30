#include <stdlib.h>
#include <stdio.h>

int *newBucket(int d)
{
    int *arr = malloc(sizeof(int) * d);
    for (int i = 0; i < d; i++)
    {
        // arr[i] = 0;
        *(arr + i) = 0;
    }
    return arr;
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

int main(int argc, char *argv[])
{
    // char c = '1';
    // char c[2];
    // c[0] = '1';
    // c[1] = '\0';
    // printf("%c\n", atoi(c));
    
    if(argc < 2)
        return 0;
    int numero, temp;
    int dim = atoi(argv[1]);
    int *p = newBucket(dim);
    printf("Inserire numeri: ");
    while (1)
    {
        scanf("%d", &numero);
        // temp = add(p, numero, dim);
        // if (temp == 0)
        //     break;
        if(!add(p, numero, dim))
            break;
    }
    free(p);


    return 0;
}