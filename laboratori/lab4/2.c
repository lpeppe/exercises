#include <stdio.h>
#include <stdlib.h>
#define N 10

int ciclicita(int* arr) {
    int i = 0, k = 0;
    while (arr[i] < N) {
        i = arr[i];
        k++;
        if (k > N)
            return 1;
    }
    return 0;
}

int main() {
    int v1[] = {5, -6, 7, 6, 2, 4, 2, 9};
    printf("L'array %se'ciclico\n", ciclicita(v1) ? "" : "non ");
    return 0;
}