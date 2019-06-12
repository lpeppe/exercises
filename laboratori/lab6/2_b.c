#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y;
} punto;

typedef struct {
    punto NO, SE;
} rettangolo;

int isValid(rettangolo r) { return (r.NO.y >= r.SE.y && r.SE.x >= r.NO.x); }

rettangolo inviluppo(rettangolo a, rettangolo b) {
    rettangolo inviluppo;
    punto no, se;
    // il NO del rettangolo di inviluppo deve avere come
    // y il massimo tra gli y dei NO di a e b e come
    // x il minimo tra gli x dei NO di a e b
    if (a.NO.x <= b.NO.x)
        no.x = a.NO.x;
    else
        no.x = b.NO.x;
    if (a.NO.y >= b.NO.y)
        no.y = a.NO.y;
    else
        no.y = b.NO.y;

    if (a.SE.x >= b.SE.x)
        se.x = a.SE.x;
    else
        se.x = b.SE.x;
    if (a.SE.y <= b.SE.y)
        se.y = a.SE.y;
    else
        se.y = b.SE.y;
    inviluppo.NO = no;
    inviluppo.SE = se;
    return inviluppo;
}

rettangolo creaRettangolo(nox, noy, sex, sey) {
    rettangolo a;
    punto no, se;
    no.x = nox;
    no.y = noy;
    se.x = sex;
    se.y = sey;
    a.NO = no;
    a.SE = se;
    return a;
}

void intersezione(rettangolo a, rettangolo b) {
    
}

int main() {
    rettangolo r1 = creaRettangolo(5, 2, 10, 0);
    rettangolo r2 = creaRettangolo(2, 2, 12, -1);
    rettangolo i = inviluppo(r1, r2);
    printf("%d\n", i.NO.x);
}