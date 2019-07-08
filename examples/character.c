#include <stdlib.h>
#include <stdio.h>

int main() {
    char buff[100];
    sprintf(buff, "%d", 155);
    printf("%d\n", buff[0] - '0');
}