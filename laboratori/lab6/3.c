#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void invertiLettere(char frase1[]) {
    int dim = strlen(frase1), word_start = 0, word_end, i, j, dim_parola;
    char tmp, frase[100];
    sprintf(frase, "%s", frase1);
    for (i = 0; i <= dim; i++) {
        if (frase[i] == '.' || frase[i] == '\0') {
            word_end = i - 1;
            dim_parola = (word_end + 1) - word_start;
            for (j = 0; j < dim_parola / 2; j++) {
                tmp = frase[word_start + j];
                frase[word_start + j] = frase[word_end - j];
                frase[word_end - j] = tmp;
            }
            word_start = word_end + 2;
        }
    }
    printf("%s\n", frase);
}

// word_start contiene le posizioni dell'inizio delle parole.
// nella prima frase di esempio sarebbe
// 0 7 10 16 23
void invertiParole(char frase1[]) {
    int dim = strlen(frase1), i, k = 1, word_start[100], j, s = 0;
    char tmp, frase[100];
    word_start[0] = 0;
    for (i = 0; i < dim; i++) {
        if (frase1[i] == '.') {
            word_start[k] = i + 1;
            k++;
        }
    }

    // scorriamo l'array degli indici al contrario
    for (j = k - 1; j >= 0; j--) {
        // scorriamo tutte le lettere della parola
        for (i = word_start[j];; i++) {
            if (frase1[i] == '.' || frase1[i] == '\0')
                break;
            frase[s] = frase1[i];
            s++;
        }
        // scrivi il punto solo se non ci troviamo
        // alla prima parola
        if (j > 0) {
            frase[s] = '.';
            s++;
        }
    }
    frase[s] = '\0';
    printf("%s\n", frase);
}

int main() {
    char a[100];

    printf("Inserisci una frase: ");
    scanf("%s", a);

    invertiLettere(a);
    invertiParole(a);

    return 0;
}