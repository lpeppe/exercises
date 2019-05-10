#include <stdlib.h>
#include <stdio.h>

int main() {
    // come invertire due variabili
    int a = 5, b = 7;
    int c;
    c = a;
    a = b;
    b = c;
    printf("%d %d\n", a, b);
}