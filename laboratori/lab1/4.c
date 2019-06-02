#include <stdio.h>
#include <stdlib.h>

int main() {
    while (1) {
        int numero, i, k = 0;

        printf("Inserisci un numero: ");
        scanf("%d", &numero);

        if (numero < 0) {
            printf("Numero negativo.\n");
        } else {
            for (i = 2; i < numero; i++) {
                if (numero % i == 0)
                    k++;
            }

            if (k == 0)
                printf("il numero e'primo\n\n");

            else
                printf("il numero non e' primo\n\n");
        }
    }

    return 0;
}