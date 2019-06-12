#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define TOLLERANZA 50

typedef struct {
    int x, y;
} punto;

typedef struct {
    punto a, b, c;
} triangolo;

double lunghezzaLato(punto a, punto b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int disuguaglianza(triangolo t) {
    if (lunghezzaLato(t.a, t.b) + lunghezzaLato(t.b, t.c) <
        lunghezzaLato(t.c, t.a))
        return 0;
    if (lunghezzaLato(t.b, t.c) + lunghezzaLato(t.c, t.a) <
        lunghezzaLato(t.a, t.b))
        return 0;
    if (lunghezzaLato(t.a, t.c) + lunghezzaLato(t.b, t.a) <
        lunghezzaLato(t.c, t.b))
        return 0;
    return 1;
}

int percentuale(double a, double b) {
    if (a < b) {
        if (b - a < b / 100 * TOLLERANZA)
            return 1;
        return 0;
    } else {
        if (a - b < a / 100 * TOLLERANZA)
            return 1;
        return 0;
    }
}
int controlloIsoscele(triangolo t) {
    if (percentuale(lunghezzaLato(t.a, t.b), lunghezzaLato(t.b, t.c)))
        return 1;
    if (percentuale(lunghezzaLato(t.b, t.c), lunghezzaLato(t.c, t.a)))
        return 1;
    if (percentuale(lunghezzaLato(t.a, t.c), lunghezzaLato(t.b, t.a)))
        return 1;
    return 0;
}

int controlloEquilatero(triangolo t) {
    return (percentuale(lunghezzaLato(t.a, t.b), lunghezzaLato(t.b, t.c)) &&
            percentuale(lunghezzaLato(t.b, t.c), lunghezzaLato(t.a, t.c)) &&
            percentuale(lunghezzaLato(t.a, t.c), lunghezzaLato(t.a, t.b)));
}

int main() {
    punto a, b, c;
    a.x = 0;
    a.y = 0;
    b.x = 4;
    b.y = 0;
    c.x = 2;
    c.y = 4;
    triangolo t;
    t.a = a;
    t.b = b;
    t.c = c;
    printf("%se' isoscele\n", controlloIsoscele(t) ? "" : "Non ");
    printf("%se' equilatero\n", controlloEquilatero(t) ? "" : "Non ");
}