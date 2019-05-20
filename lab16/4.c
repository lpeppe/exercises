#include <stdio.h>
#include <stdlib.h>

typedef struct nd {
    char c;
    struct nd *prox;
} Node;

typedef Node *List;

List insertNode(List head, char c) {
    List p = malloc(sizeof(Node));
    p->c = c;
    p->prox = head;
    head = p;
    return head;
}

int compareLists(List head1, List head2) {
    for (List p1 = head1, p2 = head2; p1 != NULL && p2 != NULL;
         p1 = p1->prox, p2 = p2->prox)
        if (p1->c != p2->c)
            return 0;
    return 1;
}

int checkPalindroma(List head) {
    List head2 = NULL, p = head;
    while (p != NULL) {
        head2 = insertNode(head2, p->c);
        p = p->prox;
    };
    return compareLists(head, head2);
}

int main() {
    List p1 = malloc(sizeof(Node));
    List p2 = malloc(sizeof(Node));
    List p3 = malloc(sizeof(Node));
    List p4 = malloc(sizeof(Node));
    p1->c = 'o';
    p2->c = 's';
    p3->c = 's';
    p4->c = 'o';
    p1->prox = p2;
    p2->prox = p3;
    p3->prox = p4;
    p4->prox = NULL;
    printf("La lista %sè palindroma\n", checkPalindroma(p1) ? "" : "non ");
}