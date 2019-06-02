#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ePrimo(int num) {
    int i;
    for (i = 2; i < num; i++) {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

int main() {
    // n numero da scomporre, k mantiene la potenza dei numeri primi genera un
    // arrey di interi arr
    int n, *arr, j = 0, i, k = 0;

    printf("Inserisci un numero da scomporre: ");
    scanf("%d", &n);
    arr = malloc(sizeof(int) * n);
    if (n < 0)
        printf("Numero negativo.\n");
    else {
        // i parte da 2 perche' quando vado a dividere il numero per i se
        // partisse da 1 si entrerebbe in loop.
        for (i = 2; i < n; i++) {
            if (ePrimo(i)) {
                arr[j] = i;
                j++;
            }
        }
    }

    // scorro l'array in cui ho inserito i numeri primi per cui è possibile
    // dividere n
    for (i = 0; i < j; i++) {
        if (n == 0)
            break;
        while (n % arr[i] == 0) {
            n = n / arr[i];
            k++;
        }
        if (k > 0)
            printf("%d ^ %d   ", arr[i], k);
        k = 0;
    }

    return 0;
}