#include <stdlib.h>
#include <stdio.h>

int main() {
    int a = 5, *p;
    p = &a;
    printf("%p\n", &p);
    return 0;
}