#include <stdio.h>
#include <stdlib.h>

int lunghezzaStringa(char *str, char ch, char *sost) {
    int l_str = strlen(str), occorrenze = 0, l_sost = strlen(sost);
    for (int i = 0; i < l_str; i++) {
        if (str[i] == ch)
            occorrenze++;
    }
    return (l_str - occorrenze) + (l_sost * occorrenze);
}

char *replace(char *str, char ch, char *sost) {
    int res_len = lunghezzaStringa(str, ch, sost);
    char *p = malloc(sizeof(char) * lunghezzaStringa(str, ch, sost) + 1);
    for (int i = 0, j = 0; i < res_len; i++, j++) {
        if (str[j] != ch) {
            p[i] = str[j];
        } else {
            for (int k = 0; k < strlen(sost); k++) {
                p[i + k] = sost[k];
            }
            i = i + strlen(sost) - 1;
        }
    }
    p[res_len] = '\0';
    return p;
}

int main() {
    char *rep = replace("pomo", 'o', "enti");
    printf("%s\n", rep);
    free(rep);
}