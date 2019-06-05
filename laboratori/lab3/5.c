#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int controlloBase(int n1, int b1) {
    char arr[100];
    int dim, i, k = 0;
    sprintf(arr, "%d", n1);
    dim = strlen(arr);
    for (i = 0; i < dim; i++) {
        if ((arr[i] - '0') >= (b1))  // arr[i]-'0' converte il char in intero
            return 0;
    }
    return 1;
}

int conversioneInDecimale(int n1, int b1) {
    char arr[100];
    int i, exp = 0, dim, n_dec = 0;

    sprintf(arr, "%d", n1);
    dim = strlen(arr);
    for (i = (dim - 1); i >= 0; i--) {
        n_dec = n_dec + (arr[i] - '0') * (int)pow(b1, exp);
        exp++;
    }
    return n_dec;
}

int conversioneDefinitiva(int n_dec, int b2) {
    int arr[100], i, j, n_finale = 0;

    for (i = 0; n_dec > 0; i++) {  // i è la posizione dell'array in cui metto i
                                   // retsi della divisione
        arr[i] = n_dec % b2;  // che sono le cifre del numero covertito
        n_dec = n_dec / b2;
    }
    for (j = 0; j < i; j++) {
        n_finale = n_finale + (arr[j] * (int)pow(10, j));
    }
    return n_finale;
}

int main() {
    int n1, b1, b2, dim, n_dec;
    char arr[100];

    printf("inserisci un numero da convertire e la sua base:  ");
    scanf("%d %d", &n1, &b1);

    printf("in che base vuoi convertire il numero inserito?  ");
    scanf("%d", &b2);

    if (!controlloBase(n1, b1))
        return 0;

    n_dec = conversioneInDecimale(n1, b1);

    printf("%d", conversioneDefinitiva(n_dec, b2));

    return 0;
}