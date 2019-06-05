#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 5

void creaMat(int m[N][N]) {
    int i, j, k = 1;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            m[i][j] = k;
            k++;
        }
    }
}

void printMat(int m[][N]) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) printf("%3d ", m[i][j]);
        printf("\n");
    }
}

int main() {
    int m[N][N], num, old_num, i, j, k = 1, r, c;

    creaMat(m);
    printMat(m);
    printf("\n");
    printf("Inserisci le coordinate di una cella della matrice: ");
    scanf("%d%d", &r, &c);
    printf("il numero nella cella e' %d\n\n", m[r][c]);
    num = m[r][c];
    old_num = num;
    k = 1;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (i > r || (r == i && j > c)) {
                m[i][j] = k;
                k++;
            } else if (m[i][j] != num) {
                num++;
                m[i][j] = num;
            }
        }
    }
    for (i = 0; i < N; i++) {
        if (i != r)
            m[i][c] = old_num * 2;
        else
            m[i][c] = old_num;
    }
    printMat(m);

    return 0;
}