#include <stdio.h>
#include <stdlib.h>

int findOccurencesNumber(char *str, char ch) {
    int len = strlen(str), cont = 0;
    for (int i = 0; i < len; i++)
        if (str[i] == ch)
            cont++;
    return cont;
}

char *replace(char *str, char *sost, char ch) {
    int sostLen = strlen(sost), strLen = strlen(str);
    int occurrences = findOccurencesNumber(str, ch);
    int toReturnLen = strLen + ((sostLen - 1) * occurrences);
    char *toReturn = malloc(sizeof(char) * toReturnLen + 1);
    // j è l'indice che utilizziamo per scorrere la stringa str
    // i è l'indice che utilizziamo per scorrere la stringa toReturn
    for (int i = 0, j = 0; i < toReturnLen; j++) {
        if (str[j] != ch) {
            toReturn[i] = str[j];
            i++;
        } else {
            for (int k = 0; k < sostLen; k++) {
                toReturn[i] = sost[k];
                i++;
            }
        }
    }
    toReturn[toReturnLen] = '\0';
    return toReturn;
}

int main() { printf("%s\n", replace("pomo", "enti", 'o')); }