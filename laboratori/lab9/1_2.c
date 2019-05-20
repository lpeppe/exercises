#include <stdio.h>
#include <stdlib.h>

void scambioLettere(char *dest, char *lettere, int p_o_d) {
    for (int i = 0, j = 0; i < strlen(dest) && j < strlen(lettere); i++) {
        // if (p_o_d == 0) {
        //     if ((i + 1) % 2 == 0) {
        //         dest[i] = lettere[j];
        //         j++;
        //     }
        // } else {
        //     if ((i + 1) % 2 != 0)
        //         dest[i] = lettere[j];
        //         j++;
        // }
        if ((i + 1) % 2 == p_o_d) {
            // dest[i] = lettere[j];
            *(dest + i) = *(lettere + j);
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