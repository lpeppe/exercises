#include <math.h>
#include <stdio.h>
int main() {
    int a = 1, b;
    printf("%p\n", &a);
    int *a1;
    a1 = &a;
    printf("Indirizzo di memoria di a: %p\n", &a);
    printf("Valore di a1: %p\n", a1);
    printf("Valore contenuto in a1: %d\n", *a1);
    *a1 = 5;
    printf("%d\n", a);
    return 0;
}