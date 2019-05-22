#include <stdio.h>
#include <stdlib.h>

int main() {
    int k, i, *arr;
    while (1) {
        printf("Inserisci un numero: ");
        scanf("%d", &k);
        arr = malloc(sizeof(int) * k);
        for (i = 0; i < 3; i++) {
            arr[i] = 1;
            printf("%d ", arr[i]);
        }
        for (i = 3; i <= k; i++) {
            arr[i] = arr[i - 2] + arr[i - 3];
            printf("%d ", arr[i]);
        }
        printf("\n");
        free(arr);
    }
    return 0;
}