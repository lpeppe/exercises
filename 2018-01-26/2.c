#include <stdlib.h>
#include <stdio.h>

int isOmogeneo(int *arr, int size)
{
    int tmp = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (tmp == 0)
            tmp = arr[i];
        else if (tmp != arr[i])
            return 0;
    }
    return 1;
}

int main(int argc, char **argv)
{
    FILE *fp;
    // inizializza tutti gli elementi a 0
    int conts[5] = {}, num;
    char c;
    fp = fopen(argv[1], "r");
    fp = fopen("inputFile.txt", "r");
    if (fp != NULL)
    {
        while ((c = fgetc(fp)) != EOF)
        {
            num = c - '0';
            if (num >= 0 && num <= 9)
                if (num % 2 == 0)
                    conts[num / 2]++;
        }
        printf("I numeri %shanno una frequenza omogenea\n", isOmogeneo(conts, 5) ? "" : "non ");
    }

    fclose(fp);
}