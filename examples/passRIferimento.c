#include <stdlib.h>
#include <stdio.h>

void scambiaRif(int *num) {
    *num = 7;
    printf("Inside func: %p\n", &num);
}

void scambiaVal(int num) {
    num = 7;
    printf("Inside func: %p\n", &num);
}

int main() {
    int a = 5;
    printf("Inside main: %p\n", &a);
    scambiaRif(&a);
    // scambiaVal(a);
    printf("%d\n", a);
    return 0;
}