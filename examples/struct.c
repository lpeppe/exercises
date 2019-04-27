#include <stdlib.h>
#include <stdio.h>

typedef struct couple
{
    int num1;
    int num2;
} couple;

int main() {
    couple a;
    a.num1 = 5;
    a.num2 = 10;
    printf("%d %d\n", a.num1, a.num2);
    return 0;
}