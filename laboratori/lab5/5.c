#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int controlloBase(char alf1[], char alf2[], int b1, int b2) {
    int dim1 = strlen(alf1);
    int dim2 = strlen(alf2);
    // l'espressione booleana restituisce 1 se entrambe le
    // condizioni sono verificate, 0 altrimenti
    return (dim1 >= b1 && dim2 >= b2);
}

int checkAlf(char alf[], char n[]) {
    int i, j, dim_alf = strlen(alf), dim_n = strlen(n), k = 0;
    for (i = 0; i < dim_n; i++) {
        for (j = 0; j < dim_alf; j++) {
            if (n[i] == alf[j]) {
                k++;
                break;
            }
        }
        if (k == 0)
            return 0;
    }
    return 1;
}

int indexOf(char c, char alf[]) {
    int i, dim = strlen(alf);
    for (i = 0; i < dim; i++) {
        if (alf[i] == c)
            return i;
    }
    return -1;
}

int conversioneInDecimale(char n1[], int b1, char alf1[]) {
    int i, exp = 0, dim, n_dec = 0;
    // 126578
    dim = strlen(n1);
    for (i = (dim - 1); i >= 0; i--) {
        n_dec = n_dec + indexOf(n1[i], alf1) * (int)pow(b1, exp);
        exp++;
    }
    return n_dec;
}

char *conversioneDefinitiva(int n_dec, int b2) {
    int arr[100], i, j, n_finale = 0;

    for (i = 0; n_dec > 0; i++) {  // i è la posizione dell'array in cui metto i
                                   // retsi della divisione
        arr[i] = n_dec % b2;  // che sono le cifre del numero covertito
        n_dec = n_dec / b2;
    }
    // 7
    // 15
    // 14
    // 4
    for (j = 0; j < i; j++) {
        n_finale = n_finale + (arr[j] * (int)pow(b2, j));
    }
    printf("%d\n", n_finale);
    return "n_finale";
}

int main() {
    int b1, b2, dim, n_dec;
    char arr[100], alf1[100], alf2[100], n1[100];
    // char alf1[] = "abcde";
    // char alf2[] = "01234";
    // "cde" -> "234"
    printf("inserisci un numero da convertire:  ");
    scanf("%s", n1);
    printf("inserisci una base da convertire:  ");
    scanf("%d", &b1);
    printf("inserisci i due alfabeti:  ");
    scanf("%s %s", alf1, alf2);
    printf("inserisci una base in cui convertire il numero:  ");
    scanf("%d", &b2);

    if (!controlloBase(alf1, alf2, b1, b2)) {
        printf("La base è troppo grande!\n");
        return 0;
    }
    if (!checkAlf(alf1, n1)) {
        printf("Il numero non è nell'alfabeto!\n");
        return 0;
    }

    // printf("%d\n", conversioneInDecimale(n1, b1, alf1));
    printf("%d\n",
           conversioneDefinitiva(conversioneInDecimale(n1, b1, alf1), b2));
    // printf("in che base vuoi convertire il numero inserito?  ");
    // scanf("%d", &b2);

    // if (!controlloBase(n1, b1))
    //     return 0;

    // n_dec = conversioneInDecimale(n1, b1);

    // printf("%d", conversioneDefinitiva(n_dec, b2));

    return 0;
}