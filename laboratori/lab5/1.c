#include <stdio.h>
#include <stdlib.h>

int eRipetitivo(int num) {
    char arr[100];
    int i, j;
    sprintf(arr, "%d", num);
    int dim = strlen(arr);
    for (i = 0; i < dim - 1; i++) {
        for (j = i + 1; j < dim; j++) {
            if (arr[i] == arr[j])
                return 1;
        }
    }
    return 0;
}

int main() { 
    printf("Il numero e' %s\n", eRipetitivo(1224) ? "ripetitivo" : "vario"); 
}