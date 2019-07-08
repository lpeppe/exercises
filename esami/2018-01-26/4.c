#include <stdio.h>
#include <stdlib.h>
#define N 10

typedef struct nd {
    int n;
    struct nd *prox;
} Nodo;

typedef Nodo *Lista;

int fCons(Lista p, int n) {
    while (p->prox != NULL) {
        if (p->n == n && p->n == p->prox->n)
            return 1;
        p = p->prox;
    }
    return 0;
}
// versione ricorsiva
// int fCons(Lista lis, int n) {
//     if (!lis || !lis->prox)
//         return 0;
//     if (n == lis->n && n == lis->prox->n)
//         return 1;
//     return fCons(lis->prox);
// }

int fNonCons(Lista p, int n) {
    int flag = 0;
    while (p != NULL) {
        if (p->n == n) {
            if (flag)
                return 1;
            if (p->prox->prox == NULL)
                return 0;
            flag = 1;
            p = p->prox->prox;
        } else
            p = p->prox;
    }
}

int fNonCons2(Lista p, int n) {
    int cont = 0, contDif = 0;
    while (p != NULL) {
        if (p->n == n) {
            if (cont > 0 && contDif > 0)
                return 1;
            cont++;
            contDif = 0;
        } else {
            contDif++;
        }
        p = p->prox;
    }
    return 0;
}

int quantiAlmenoTriplici(Lista lis) {
    int count = 0, tmpCont = 0;
    Lista head = lis;
    for (int i = 1; i <= N; i++) {
        while (lis != NULL) {
            if (lis->n == i)
                tmpCont++;
            lis = lis->prox;
        }
        if (tmpCont >= 3)
            count++;
        tmpCont = 0;
        lis = head;
    }
    return count;
}

int main() {
    Lista p1 = malloc(sizeof(Nodo));
    Lista p2 = malloc(sizeof(Nodo));
    Lista p3 = malloc(sizeof(Nodo));
    Lista p4 = malloc(sizeof(Nodo));
    Lista p5 = malloc(sizeof(Nodo));
    Lista p6 = malloc(sizeof(Nodo));
    p1->n = 2;
    p2->n = 1;
    p3->n = 1;
    p4->n = 1;
    p5->n = 2;
    p6->n = 1;
    p1->prox = p2;
    p2->prox = p3;
    p3->prox = p4;
    p4->prox = p5;
    p5->prox = p6;
    p6->prox = NULL;
    // printf("%d\n", fNonCons(p1, 1));
    // printf("%d\n", quantiAlmenoTriplici(p1));
    printf("%d\n", fNonCons2(p1, 1));
}