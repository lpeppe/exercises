#include <stdio.h>
#include <stdlib.h>

int main() {
    while (1) {
        int numero, i, k, j = 1;

        printf("Inserisci un numero: ");
        scanf("%d", &numero);

        for (i = 1; i <= numero; i++) {
            for (k = 1; k <= i; k++) {
                printf("%5d", j);
                j++;
            }
            printf("\n");
        }
    }

    return 0;
}