#include <stdlib.h>
#include <stdio.h>

int somma(int a, int b);
void stampa(int num);

// argv è l'array di stringhe passate in input al programma e argc è la dimensione dell'array
int main(int argc, char **argv)
{
    printf("%d\n", somma(3, 6));
    stampa(5);
    return 0;
}

int somma(int a, int b)
{
    return a + b;
}

void stampa(int num) {
    printf("---%d---\n", num);
}