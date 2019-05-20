#include <stdio.h>
#include <stdlib.h>

int main() {
    char buff[50], out[150];
    int i, offset = 0;
    // scanf("%20[^\n]", buff);
    fgets(buff, 50, stdin);
    int dim = strlen(buff);
    for (i = 0; i < dim; i++) {
        if (buff[i] == 'r')
            out[i + offset] = 'V';
        if (buff[i] == 's')
            out[i + offset] = 'F';
        if ((i == 0 || buff[i - 1] == ' ') && buff[i] == 'c')
            out[i + offset] = 'H';
        else {
            if (buff[i] < 97 || buff[i] > 122)
                out[i + offset] = buff[i];
            else {
                out[i + offset] = buff[i] - 32;
                if (buff[i] == 'a' || buff[i] == 'e' || buff[i] == 'i' ||
                    buff[i] == 'o' || buff[i] == 'u') {
                    out[i + offset + 1] = 'F';
                    out[i + offset + 2] = buff[i] - 32;
                    offset += 2;
                }
            }
        }
    }
    printf("%s\n", out);
    return 0;
}