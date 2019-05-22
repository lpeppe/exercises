#include <stdio.h>
#include <stdlib.h>

int getMax(int n) {
    int i, j, cont = 0;
    for (i = 0; i <= n; i++)
        for (j = 0; j < i; j++) cont++;
    return cont;
}

int main() {
    while (1) {
        int numero, i, j, numMax;
        printf("Inserisci un numero: ");
        scanf("%d", &numero);
        for (i = numero; i >= 0; i--) {
            numMax = getMax(i);
            for (j = 0; j <= i; j++) {
                // numMax = numMax + 1;
                printf("%5d", ++numMax);
            }
            printf("\n");
        }
    }
    return 0;
}