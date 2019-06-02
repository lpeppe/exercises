#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int controlloBase(int n1, int b1) {
    char arr[100];
    int dim, i, k = 0;
    sprintf(arr, "%d", n1);
    dim = strlen(arr);
    for (i = 0; i < dim; i++) {
        if ((arr[i] - '0') > (b1 - 1))
            return 0;
    }
    return 1;
}

int conversioneInDecimale(int n_dec, char arr[]) {}

int main() {
    int n1, b1, b2, dim;
    char arr[100];

    printf("inserisci un numero da convertire e la sua base:  ");
    scanf("%d %d", &n1, &b1);

    printf("in che base vuoi convertire il numero inserito?  ");
    scanf("%d", &b2);

    printf("%d\n", controlloBase(n1, b1));
    return 0;
}