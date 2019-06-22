#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int palindroma(char str[]) {
    int i, j;
    for (i = 0, j = strlen(str) - 1; i < strlen(str) / 2; i++, j--) {
        if (str[i] != str[j])
            return 0;
    }

    // se il compilatore non supporta la doppia inizializzazione
    // int i, j = strlen(str) - 1;
    // for (i = 0; i < strlen(str) / 2; i++) {
    //     if (str[i] != str[j])
    //         return 0;
    //     j--;
    // }
    return 1;
}

int palindromaConTrasporto(char str[]) {
    char *str_temp = malloc(sizeof(char) * 20);
    int i;
    // sprintf(str_temp, "%s", str);
    strcpy(str_temp, str);
    // <= di strlen così spostiamo in str_temp anche il \0
    for (i = 1; i <= strlen(str_temp); i++) {
        str_temp[i - 1] = str_temp[i];
    }
    if (palindroma(str_temp))
        return 1;
    strcpy(str_temp, str);
    str_temp[strlen(str_temp) - 1] = '\0';
    if (palindroma(str_temp))
        return 1;
    return 0;
}

int main() {
    char *str = malloc(sizeof(char) * 20);
    while (1) {
        scanf("%s", str);
        if (strlen(str) == 1)
            return 0;
        if (palindroma(str))
            printf("La stringa è palindroma\n");
        else if (palindromaConTrasporto(str))
            printf("La stringa è palindroma con trasporto\n");
        else
            printf("La stringa non è palindroma\n");
    }
}