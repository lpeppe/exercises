#include <stdio.h>
#include <stdlib.h>
#define N 10

void riordina(int v[]) {
    int i, j, tmp;
    for (i = 0; i < N - 1; i++)
        for (j = 0; j < N - 1 - i; j++) {
            if (v[j] > v[j + 1]) {
                tmp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = tmp;
            }
        }
}

void printArray(int a[]) {
    int i;
    for(i = 0; i < N; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main() { 
    int v[N] = {3, 9, -2, 11, 9, 4, 1, 17, 5, 8}; 
    riordina(v);
    printArray(v);
}