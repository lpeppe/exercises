#include <stdlib.h>
#include <stdio.h>

int ugualioquasi(char *str1, char *str2)
{
    // se le stringhe sono uguali, restituisci 1
    if (strcmp(str1, str2) == 0)
        return 1;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    // se le stringhe sono di dimensione diversa, restituisci 0
    if (len1 != len2)
        return 0;
    char temp;
    for (int i = 0; i < len1 - 1; i++)
    {
        if (str1[i] != str2[i])
        {
            temp = str2[i + 1];
            str2[i + 1] = str2[i];
            str2[i] = temp;
            if (strcmp(str1, str2) == 0)
                return 1;
            return 0;
        }
    }
}

int main(int argc, char **argv)
{
    printf("%s\n", ugualioquasi(argv[1], argv[2]) ? "Simili" : "Non simili");
    // int res = ugualioquasi(argv[1], argv[2]);
    // if (res)
    //     printf("Simili");
    // else
    //     printf("Non simili");
    return 0;
}