#include <stdlib.h>
#include <stdio.h>

int omogeneo(int *occorrenze, int size)
{
    // int temp = occorrenze[0];
    // for (int i = 1; i < size; i++)
    // {
    //     if (temp == 0)
    //         temp = occorrenze[i];
    //     else if (occorrenze[i] != temp)
    //         return 0;
    // }

    // non tenendo conto delle occorrenze uguali a 0
    // per es. se l'array delle occorrenze è
    // 00111, la funzione restituisce false
    for (int i = 1; i < size; i++)
        if (occorrenze[i] != occorrenze[0])
            return 0;
    return 1;
}

int main(int argc, char **argv)
{
    if (argc < 2)
        return 0;
    char c;
    int occorrenze[5] = {}, temp = 0;
    FILE *fp;
    fp = fopen(argv[1], "r");

    while ((c = fgetc(fp)) != EOF)
    {
        temp = c - '0';
        if (temp >= 0 && temp <= 9)
        {
            if (temp % 2 == 0)
                occorrenze[temp / 2]++;
        }
    }
    if(omogeneo(occorrenze, 5)==0)
        printf("non omogenea\n");
    else printf("omogeneo\n");

    fclose(fp);
}