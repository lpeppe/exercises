#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define N 60000

// la funzione restituisce 1 se il numero n è scomponibile in
// 2 quadrati. In tal caso, i valori a e b saranno posti uguali
// ai 2 numeri che stiamo cercando
int scomponi(int n, int *a1, int *b1) {
    int rad_n = (int)sqrt(n), a, b;
    for (a = 1; a <= rad_n; a++) {
        for (b = 1; b <= rad_n; b++) {
            // (int)pow(a,2) + (int)pow(b,2);
            if ((a * a) + (b * b) == n) {
                *a1 = a;
                *b1 = b;
                return 1;
            }
        }
    }
    return 0;
}

void scomponiA(int n) {
    int rad_n = (int)sqrt(n), a, b;
    for (a = 1; a <= rad_n; a++) {
        for (b = 1; b <= a; b++) {
            // (int)pow(a,2) + (int)pow(b,2);
            if ((a * a) + (b * b) == n) {
                printf("%d %d\n", a, b);
            }
        }
    }
}

// la funzione restituisce il numero di coppie in cui il
// numero n può essere scomposto
int numScomposizioni(int n) {
    int rad_n = (int)sqrt(n), a, b, count = 0;
    for (a = 1; a <= rad_n; a++) {
        for (b = 1; b <= a; b++) {
            if ((a * a) + (b * b) == n)
                count++;
        }
    }
    return count;
}

// la funzione stampa tutti i numeri < N che sono scomponibili
// in un numero di coppie pari a n_coppie
void scomponiB(int n_coppie) {
    int i;
    for (i = 1; i < N; i++) {
        if (numScomposizioni(i) == n_coppie)
            printf("%d ", i);
    }
    printf("\n");
}

int scomponiInTre(int n, int *a1, int *b1, int *c1) {
    int rad_n = (int)sqrt(n), a, b, c;
    for (a = 1; a <= rad_n; a++) {
        for (b = 1; b <= rad_n; b++) {
            for (c = 1; c <= rad_n; c++) {
                if ((a * a) + (b * b) + (c * c) == n) {
                    *a1 = a;
                    *b1 = b;
                    *c1 = c;
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main() {
    int a, b, c;
    // alla funzione scomponi viene passato l'indirizzo
    // di memoria di a e b. I puntatori a1 e b1 conterranno
    // questo indirizzo di memoria e quindi le modifiche
    // fatte a questi due valori all'interno della funzione
    // saranno visibili all'esterno (al main)
    int res = scomponi(41, &a, &b);
    printf("Scomposizione in 2 numeri:\n");
    printf("res:%d\na:%d\nb:%d\n", res, a, b);
    printf("Tutte le coppie in cui il numero può essere scomposto:\n");
    scomponiA(325);
    printf("Descrizione sulla funzione:\n");
    scomponiB(5);
    printf("Scomposizione in 3 numeri:\n");
    res = scomponiInTre(325, &a, &b, &c);
    printf("res:%d\na:%d\nb:%d\nc:%d\n", res, a, b, c);
    return 0;
}