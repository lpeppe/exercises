#include <stdio.h>
#include <stdlib.h>

int max(int numero)
{

    if (numero == 0)
    {
        return 0;
    }

    int *p = malloc(sizeof(int) * (numero + 1));
    p[0] = 0;
    p[1] = 1;
    int max = 1;

    for (int i = 2; i <= numero; i++)
    {
        if (i % 2 == 0)
        {
            p[i] = p[i / 2];
        }
        else
        {
            p[i] = p[(i - 1) / 2] + p[((i - 1) / 2) + 1];
        }
        if (p[i] > max)
        {
            max = p[i];
        }
    }
    free(p);
    return max;
}

int main(int argc, char **argv)
{

    int n;

    printf("Inserisci numero: \n");
    scanf("%d", &n);
    printf("%d\n", max(n));

    return 0;
}