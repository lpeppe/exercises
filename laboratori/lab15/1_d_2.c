#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define RIGHE 3

char *modificaParola(char *str, char g) {
    int i, j = 0, occorrenze = 0;
    for (i = 0; i < strlen(str); i++) {
        if (str[i] == g)
            occorrenze++;
    }
    //+1 aggiunge il \0 alla fine dell stringa.
    char *nuova_parola = malloc(sizeof(char) * (strlen(str) + occorrenze + 1));
    for (i = 0; i <= strlen(str); i++, j++) {
        nuova_parola[j] = str[i];
        if (str[i] == g) {
            j++;
            nuova_parola[j] = str[i];
        }
    }
    return nuova_parola;
}

void raddoppia(char sorgente, char **destinazione, char g) {
    int i;
    for (i = 0; i < RIGHE; i++) {
        destinazione[i] = modificaParola(sorgente[i], g);
    }
}

int main(int argc, char argv) {
    int i;
    char **sorgente = malloc((sizeof(char *) * RIGHE)),
         **destinazione = malloc(sizeof(char *) * 50), g;
    printf("Inserisci il carattere da raddoppiare: ");
    scanf("%c", &g);
    for (i = 0; i < RIGHE; i++) {
        char *parola = malloc(sizeof(char) * 50);
        printf("Inserisci la parola %d: ", i + 1);
        scanf("%s", parola);
        sorgente[i] = parola;
    }
    for (i = 0; i < RIGHE; i++) {
        destinazione[i] = NULL;
    }
    raddoppia(sorgente, destinazione, g);
    for (i = 0; i < RIGHE; i++) {
        printf("%s\n", destinazione[i]);
    }
    return 0;
}