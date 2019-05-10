#include <stdlib.h>
#include <stdio.h>

int findOccurencesNumber(char *str, char ch)
{
    int len = strlen(str), cont = 0;
    for (int i = 0; i < len; i++)
        if (str[i] == ch)
            cont++;
    return cont;
}

char *replace(char *str, char *sost, char ch)
{
    int sostLen = strlen(sost), strLen = strlen(str);
    int occurrences = findOccurencesNumber(str, ch);
    int toReturnLen = strLen + ((sostLen - 1) * occurrences);
    char *toReturn = malloc(sizeof(char) * toReturnLen + 1);
    for(int i = 0, j = 0; i < toReturnLen; j++) {
        if(str[j] != ch) {
            toReturn[i] = str[j];
            i++;
        }
        else {
            for(int k = 0; k < sostLen; k++)
                toReturn[i+k] = sost[k];
            i+=sostLen;
        }
    }
    toReturn[toReturnLen] = '\0';
    return toReturn;
}

int main()
{
    printf("%s\n", replace("lonfo", "gniffo", 'a'));
}