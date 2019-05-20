#include <stdio.h>
#include <stdlib.h>

void scambioLettere(char *dest, char *lettere, int p_o_d) {
    int destLen = strlen(dest), lettereLen = strlen(lettere);
    for (int i = 0, j = 0; i < destLen && j < lettereLen; i++) {
        if ((i + 1) % 2 == 0) {
            dest[i] = lettere[j];
            j++;
        }
    }
}

int main() {
    char str1[] = "parolagigante";
    char str2[] = "PROVA";
    scambioLettere(str1, str2, 0);
    printf("%s\n", str1);
    return 0;
}