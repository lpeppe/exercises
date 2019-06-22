#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numeroOccorrenze(char str[], char a) {
    int i, dim = strlen(str), count = 0;
    for (i = 0; i < dim; i++) {
        if (tolower(str[i]) == tolower(a))
            count++;
    }
    return count;
}

int sonoAnagrammi(char str1[], char str2[]) {
    int dim1 = strlen(str1), dim2 = strlen(str2), i;
    for (i = 0; i < dim1; i++) {
        if ((str1[i] >= 65 && str1[i] <= 90) ||
            (str1[i] >= 97 && str1[i] <= 122)) {
            if (numeroOccorrenze(str1, str1[i]) !=
                numeroOccorrenze(str2, str1[i])) {
                return 0;
            }
        }
    }
    for (i = 0; i < dim2; i++) {
        if ((str2[i] >= 65 && str2[i] <= 90) ||
            (str2[i] >= 97 && str2[i] <= 122)) {
            if (numeroOccorrenze(str1, str2[i]) !=
                numeroOccorrenze(str2, str2[i])) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    printf("Le frasi %ssono anagrammi\n",
           sonoAnagrammi("Halloween", "hello, Wane!") ? "" : "non ");
}