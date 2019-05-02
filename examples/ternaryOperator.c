#include <stdlib.h>
#include <stdio.h>

void stampa1() {
    printf("Test1\n");
}
void stampa2() {
    printf("Test2\n");
}

int main() {
    printf("%s\n", 1 > 0 ? "Test1" : "Test2");
    1 ? stampa1() : stampa2();
}