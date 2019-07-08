#include <stdio.h>
#include <stdlib.h>

int main() {
    char test[] = "ciao";
    for (int i = 0; test[i] != '\0'; i++) 
        printf("%c", test[i]);
}