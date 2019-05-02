#include <stdlib.h>
#include <stdio.h>

int ugualioquasi(char *str1, char *str2)
{
    if (!strcmp(str1, str2))
        return 1;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if (len1 != len2)
        return 0;
    char temp;
    int flag = 0;
    for (int i = 0; i < len1; i++)
    {
        for (int j = -1; j < 2; j++)
        {
            if (i + j >= 0)
            {
                if (str1[i] == str2[i + j])
                {
                    flag = 1;
                    break;
                }
            }
        }
        if (!flag)
            return 0;
        flag = 0;
    }
    return 1;
}

int main(int argc, char **argv)
{
    printf("%s\n", ugualioquasi(argv[1], argv[2]) ? "Simili" : "Non simili");
}