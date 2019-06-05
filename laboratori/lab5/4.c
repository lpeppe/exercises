#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10

int trovaMin(int *arr) {
    int i, min;
    min = arr[0];
    for (i = 0; i < N; i++) {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}

int trovaMax(int *arr) {
    int i, max;
    max = arr[0];
    for (i = 0; i < N; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

int valorMedio(int arr[]) {
    int somma = 0, i;
    for (i = 0; i < N; i++) {
        somma = somma + arr[i];
    }
    return somma / N;
}

void printIstogramma(int arr[]) {
    int h, l, i, j;
    int max = trovaMax(arr);
    int min = trovaMin(arr);
    if (max > 0 && min > 0)
        h = max;
    if (max > 0 && min < 0)
        h = max - min;
    else
        h = min;
    // if (max<0 && min<0)
    //     h = min;
    l = N + 1;
    h = h + 4;
    for(i=0; i<h; i++){
        for(j=0; j<l; j++){

        }
    }
}

int main() {
    int arr[N], i;
    // printf("Inserisci i valori: ");
    // for (i = 0; i < N; i++) {
    //     scanf("%d", arr[i]);
    // }
    printf("--------");
    printf("\n");
    printf("%d%6d", -6, 5);
}