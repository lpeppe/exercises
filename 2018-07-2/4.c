#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct nd
{
    char *str;
    struct nd *prox;
} Node;

typedef Node *List;

char *appendChar(char *str, char newChar)
{
    int len = strlen(str);
    // un char aggiuntivo + uno per il \0
    char *toReturn = malloc(sizeof(char) * (len + 2));
    sprintf(toReturn, "%s%c", str, newChar);
    if (strlen(str) > 0)
        free(str);
    return toReturn;
}

int pref(char *str1, char *str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if (len2 < len1)
        return 0;
    for (int i = 0; i < len1; i++)
        if (str1[i] != str2[i])
            return 0;
    return 1;
}

int calcListSize(List lis)
{
    int counter = 0;
    while (lis != NULL)
    {
        counter++;
        lis = lis->prox;
    }
    return counter;
}

int *allocateArray(int size) {
    int *toReturn = malloc(sizeof(int) * size);
    for(int i = 0; i < size; i++)
        toReturn[i] = 0;
    return toReturn;
}

int *countall(List lis, FILE *source)
{
    char c, *str = "";
    int *toReturn = allocateArray(calcListSize(lis));
    int i = 0;
    while (lis != NULL)
    {
        while ((c = fgetc(source)) != EOF)
        {
            str = appendChar(str, c);
            if (pref(str, lis->str))
            {
                if (strcmp(str, lis->str) == 0)
                {
                    toReturn[i]++;
                    free(str);
                    str = "";
                }
            }
            else
            {
                free(str);
                str = "";
            }
        }
        lis = lis->prox;
        i++;
        rewind(source);
    }
    return toReturn;
}

List createList(char **words, int size)
{
    List head = malloc(sizeof(Node)), p, last;
    head->str = words[0];
    head->prox = NULL;
    last = head;
    for (int i = 1; i < size; i++)
    {
        p = malloc(sizeof(Node));
        last->prox = p;
        p->str = words[i];
        p->prox = NULL;
        last = p;
    }
    return head;
}

int main()
{
    FILE *fp;
    char *str[] = {"prova1", "prova2", "prova3"};
    List head = createList(str, 3);
    fp = fopen("inputFile.txt", "r");
    if (fp != NULL)
    {
        int *buf = countall(head, fp);
        printf("%d\n", buf[0]);
        printf("%d\n", buf[1]);
        printf("%d\n", buf[2]);
    }
    fclose(fp);
    return 0;
}