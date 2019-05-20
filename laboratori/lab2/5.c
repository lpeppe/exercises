#include <stdio.h>
#include <stdlib.h>

void quadratoPieno(int n) {
    int i, k;
    for (i = 0; i < n; i++) {
        for (k = 0; k < n; k++) {
            printf("*");
        }
        printf("\n");
    }
}

void quadratoVuoto(int n) {
    int i, k;
    for (i = 0; i < n; i++) {
        for (k = 0; k < n; k++) {
            if (i == 0 || i == n - 1)
                printf("*");
            else if (k == 0 || k == n - 1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}

void piramide(int n) {
    int i, k;
    for (i = 1; i <= n; i++) {
        for (k = 1; k <= i; k++) {
            printf("*");
        }
        printf("\n");
    }
}

void quadratoUltimo(int n) {
    int i, k, j;
    for (i = 0; i < n; i++) {
        for (k = 0; k < n; k++) {
            if (k <= i)
                printf("*");
            else
                printf("+");
        }
        printf("\n");
    }
}

int main() {
    int lato;
    printf("Inserisci numero: ");
    scanf("%d", &lato);

    // quadratoPieno(lato);
    // quadratoVuoto(lato);
    // piramide(lato);
    quadratoUltimo(lato);
    return 0;
}