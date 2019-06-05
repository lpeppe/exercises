#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char a[100], parola[50], tmp;
    int i, j, k = 0, s = 0, word_start = 0, dim_parola;

    printf("Inserisci una frase: ");
    scanf("%s", a);
    int dim = strlen(a);

    for (i = 0; i <= dim - 1; i++) {
        if (a[i] == '.') {
            k = i;
            dim_parola = k - word_start;
            for (j = 0; j < dim_parola / 2; j++) {
                tmp = a[word_start + j];
                a[word_start + j] = a[k - j];
                a[k - j] = tmp;
            }
            word_start = k;
        }
    }

    return 0;
}