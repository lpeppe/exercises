#include <stdio.h>
#include <stdlib.h>

typedef struct nd {
    int n;
    struct nd* prox;
} Nodo;

typedef Nodo* Lista;

typedef struct it {
    Lista sublist;
    struct it* next
} Item;

typedef Item* LdL;

void printList(Lista p) {
    while (p != NULL) {
        printf("%d ", p->n);
        p = p->prox;
    }
    printf("\n");
}

LdL rampe(Lista lis) {
    LdL toReturn;
    Lista p, last;
    while (lis != NULL) {
        p = malloc(sizeof(Nodo));
        p->n = lis->n;
        p->prox = NULL;
        if (toReturn == NULL) {
            toReturn = malloc(sizeof(Item));
            toReturn->sublist = p;
            printf("%d\n", toReturn->sublist->n);
            toReturn->next = NULL;
        } else
            last->prox = p;
        last = p;
        // p = malloc(sizeof(Nodo));
        // if (toReturn == NULL) {
        //     toReturn = p;
        // }
        lis = lis->prox;
    }
    return toReturn;
}

int main() {
    Lista p1 = malloc(sizeof(Nodo));
    Lista p2 = malloc(sizeof(Nodo));
    Lista p3 = malloc(sizeof(Nodo));
    p1->n = 1;
    p1->prox = p2;
    p2->n = 2;
    p2->prox = p3;
    p3->n = 3;
    p3->prox = NULL;

    printList(p1);
    LdL ldl = rampe(p1);
    free(p1);
    free(p2);
    free(p3);
    free(ldl);
}