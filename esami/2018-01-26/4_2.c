#include <stdio.h>
#include <stdlib.h>
#define N 10

typedef struct nd {
    int n;
    struct nd *prox;
} Nodo;

typedef Nodo *Lista;

int fCons(Lista lis, int n) {
    while (lis != NULL) {
        if (lis->prox == NULL)
            return 0;
        if (lis->n == lis->prox->n)
            return 1;
        lis = lis->prox;
    }
    return 0;
}

int fNonCons(Lista lis, int n) {
    int flag = 0;
    while (lis->prox != NULL) {
        if (lis->n == n) {
            if (flag == 0) {
                flag = 1;
                if (lis->prox->prox == NULL)
                    return 0;
                lis = lis->prox->prox;

            } else
                return 1;
        } else
            lis = lis->prox;
    }
    return 0;
}

int quantiAlmenoTriplici(Lista lis) {
    int occorrenze = 0, num_valori = 0;
    for (int i = 1; i <= N; i++) {
        for (Lista j = lis; j != NULL; j = j->prox) {
            if (i == j->n)
                occorrenze++;
            if (occorrenze == 3) {
                num_valori++;
                break;
            }
        }
        occorrenze = 0;
    }
    return num_valori;
}

int main() {
    Lista p1 = malloc(sizeof(Nodo));
    Lista p2 = malloc(sizeof(Nodo));
    Lista p3 = malloc(sizeof(Nodo));
    Lista p4 = malloc(sizeof(Nodo));
    Lista p5 = malloc(sizeof(Nodo));
    Lista p6 = malloc(sizeof(Nodo));
    p1->n = 1;
    p2->n = 1;
    p3->n = 2;
    p4->n = 2;
    p5->n = 1;
    p6->n = 2;
    p1->prox = p2;
    p2->prox = p3;
    p3->prox = p4;
    p4->prox = p5;
    p5->prox = p6;
    p6->prox = NULL;
    // printf("%d\n", fNonCons(p1, 1));
    printf("%d\n", quantiAlmenoTriplici(p1));
}