#include <stdlib.h>
#include <stdio.h>

int max(int k)
{
    int *p = malloc(++k * sizeof(int));
    p[0] = 0;
    p[1] = 1;
    int max = 1;
    for (int i = 2; i < k; i++)
    {
        int tmp;
        // se il numero è pari, s 2n = s n
        if (i % 2 == 0)
            tmp = p[i / 2];
        // se è dispari, s 2n+1 = s n + s n+1
        else
            tmp = p[(i - 1) / 2] + p[(i - 1) / 2 + 1];
        // se l'elemento calcolato è > del massimo attuale, 
        // aggiorna il massimo
        if(tmp > max)
            max = tmp;
        p[i] = tmp;
    }
    return max;
}

int main()
{
    printf("%d\n", max(16));
    return 0;
}