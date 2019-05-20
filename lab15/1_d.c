#include <stdio.h>
#include <stdlib.h>

int findOccurrences(char *str, char c) {
    int len = strlen(str), cont = 0;
    for (int i = 0; i < len; i++)
        if (str[i] == c)
            cont++;
    return cont;
}

void createString(char *p, char *str, char c) {
    int len = strlen(str), i = 0, j = 0;
    for (i = 0, j = 0; i < len; i++) {
        p[i + j] = str[i];
        if (str[i] == c) {
            j++;
            p[i + j] = c;
        }
    }
    p[i + j] = '\0';
}

void allocateArray(char **source, char **dest, char c, int dim) {
    int newStrSize;
    char *p;
    for (int i = 0; i < dim; i++) {
        newStrSize = strlen(source[i]) + findOccurrences(source[i], c);
        p = malloc(sizeof(char) + newStrSize + 1);
        createString(p, source[i], c);
        dest[i] = p;
    }
}

int main() {
    char **str1 = malloc(sizeof(char*) * 4);
    str1[0] = "casa";
    str1[1] = "scuola";
    str1[2] = "macchina";
    str1[3] = "bicicletta";
    char **str2 = malloc(sizeof(char *) * 4);
    allocateArray(str1, str2, 'c', 4);
    printf("%s\n", str2[0]);
    printf("%s\n", str2[1]);
    printf("%s\n", str2[2]);
    printf("%s\n", str2[3]);
}