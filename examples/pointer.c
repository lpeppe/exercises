#include <stdlib.h>
#include <stdio.h>

typedef struct nd {
    int num;
    struct nd *next;
}Node;

int main() {
    Node *i = malloc(sizeof(Node));
    i->num = 5;
    i->next = NULL;
    printf("%p\n", i);
    printf("%d\n", i->num);
    // int a = 5, *p;
    // p = &a;
    // printf("%p\n", p);
    // printf("%d\n", *p);
    return 0;
}