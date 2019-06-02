#include <stdio.h>
#include <stdlib.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}, i;
    // vogliamo eliminare l'elemento all'indice 2
    for (i = 2; i < 8; i++) 
        arr[i] = arr[i + 1];
}