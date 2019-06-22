#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char a[100], b[100];
    int i, j, k = 0;

    printf("Inserisci due stringhe: ");
    scanf("%s %s", a, b);

    int dim_a = strlen(a);
    int dim_b = strlen(b);

    if (dim_a != dim_b)
        printf("le due parole non sono anagrammi\n");
    else
        for (i = 0; i <= dim_a - 1; i++) {
            for (j = 0; j <= dim_b - 1; j++) {
                if (a[i] == b[j]) {
                    k++;
                    b[j] = ' ';
                    break;
                }
            }
        }
    if (k == dim_a)
        printf("le due parole sono anagrammi. \n");
    else
        printf("le due parole non sono anagrammi. \n");

    return 0;
}