#include <stdio.h>
#include <stdlib.h>

typedef struct nd {
    char *wrd;
    struct nd *prox;
} Node;

typedef Node *List;

int areLinkable(char *p, char *q) {
    int pLen = strlen(p), qLen = strlen(q), index = -1, i, j;
    for (i = pLen; i >= 0; i--)
        if (p[i] == q[0])
            index = i;
    if (index != -1)
        for (i = index, j = 0; i < pLen && j < qLen; i++, j++)
            if (p[i] != q[j])
                return -1;
    if (i == pLen)
        return index;
    return -1;
}

int calcLinkedSize(pLen, qLen, index) {
    int intersectionLength = pLen - index;
    return qLen + pLen - intersectionLength;
}

char *allaccia(char *p, char *q) {
    int pLen = strlen(p), qLen = strlen(q);
    int index = areLinkable(p, q);
    if (index != -1) {
        int linkedSize = calcLinkedSize(pLen, qLen, index);
        char *linked = malloc(sizeof(char) * linkedSize + 1);
        for (int i = 0; i < index; i++) linked[i] = p[i];
        for (int j = 0; j < qLen; j++) linked[index + j] = q[j];
        linked[linkedSize] = '\0';
        return linked;
    }
    return NULL;
}

List shrink(List p) {
    while (p->prox != NULL) {
        char *linked = allaccia(p->wrd, p->prox->wrd);
        if (linked != NULL) {
        }
    }
}

int main() {
    char str1[] = "antro";
    char str2[] = "tropo";
    char str3[] = "polo";
    char str4[] = "logo";
    char str5[] = "laurea";
    char str6[] = "reato";
    List p1 = malloc(sizeof(Node));
    List p2 = malloc(sizeof(Node));
    List p3 = malloc(sizeof(Node));
    List p4 = malloc(sizeof(Node));
    List p5 = malloc(sizeof(Node));
    List p6 = malloc(sizeof(Node));
    p1->wrd = str1;
    p2->wrd = str2;
    p3->wrd = str3;
    p4->wrd = str4;
    p5->wrd = str5;
    p6->wrd = str6;
    p1->prox = p2;
    p2->prox = p3;
    p3->prox = p4;
    p4->prox = p5;
    p5->prox = p6;
    p6->prox = NULL;
    char *res = allaccia(str1, str2);
    res != NULL ? printf("%s\n", res) : printf("Stringhe non allacciabili\n");
    free(p1);
    free(p2);
    free(p3);
    free(p4);
    free(p5);
    free(p6);
}