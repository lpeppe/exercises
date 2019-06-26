#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pif(char frase[], char parola[]) {
    char *token;
    token = strtok(frase, " ");
    while (token != NULL) {
        if (strcmp(parola, token) == 0)
            return 1;
        token = strtok(NULL, " ");
    }
    return 0;
}

int main() {
    char frase[20] = "dario";
    char parola[20] = "dario0";
    printf("La parola %sc'è\n", pif(frase, parola) ? "" : "non ");
    return 0;
}