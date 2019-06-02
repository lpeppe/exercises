#include <stdio.h>
#include <stdlib.h>

// il decremento della dimensione è visibile
// anche dall'esterno
void deleteIndex(int *arr, int index, int *dim) {
    int i;
    for (i = index; i < *dim - 1; i++) 
        arr[i] = arr[i + 1];
    (*dim)--;
}

int main() {
    int i, j = 0, dim = 100, arr[dim], eliminatore = 1;
    for (i = 0; i < 200; i++) {
        if ((i + 1) % 2 == 1) {
            arr[j] = i + 1;
            j++;
        }
    }

    while (eliminatore < dim) {
        for (i = dim - 1; i >= eliminatore; i--) {
            if ((i + 1) % arr[eliminatore] == 0) {
                deleteIndex(arr, i, &dim);
            }
        }
        eliminatore++;
    }

    for (i = 0; i < dim; i++) 
        printf("%d ", arr[i]);
    return 0;
}