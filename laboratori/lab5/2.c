#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n1, n2;

    printf("Inserisci una coppia di numeri: ");
    scanf("%d%d", &n1, &n2);

    char arr1[100], arr2[100];
    int i, j, k = 0;

    sprintf(arr1, "%d", n1);
    int dim1 = strlen(arr1);
    sprintf(arr2, "%d", n2);
    int dim2 = strlen(arr2);
    if (dim1 == dim2) {
        for (i = 0; i <= dim1 - 1; i++) {
            for (j = 0; j <= dim2 - 1; j++) {
                if (arr1[i] == arr2[j]) {
                    k++;
                    arr2[j] = 0;
                    break;
                }
            }
        }
    }

    if (k == dim1)
        printf("sono anagrammi. \n");
    else
        printf("non sono anagrammi. \n");

    return 0;
}