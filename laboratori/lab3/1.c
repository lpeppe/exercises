#include <stdio.h>
#include <stdlib.h>

int main() {
    char frase;
    int i, k = 0;

    printf("Inserisci una frase: ");

    while (1) {
        scanf("%c", &frase);

        if (frase == '.')
            break;
        else {
            if (frase == '(')
                k++;
            if (frase == ')')
                k--;
        }
        if (k < 0)
            break;
    }
    if (k == 0)
        printf("sequenza corrente.\n");
    else if (k != 0 || k < 0)
        printf("sequenza non corrente.\n");

    return 0;
}