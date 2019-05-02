#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int num;
    struct node *next;
} node;

void printLista(node *p)
{
    while (p != NULL)
    {
        printf("%d-->", p->num);
        p = p->next;
    }
    printf("NULL\n");
}

int main()
{
    node *head = malloc(sizeof(node));
    // head->num = 2;
    (*head).num = 2;
    head->next = malloc(sizeof(node));
    
    // head è l'indirizzo di memoria del primo nodo
    printf("%p\n", head);

    // indirizzo di memoria del campo next del primo nodo
    printf("%p\n", &(head->next));
    head->next->num = 3;
    // il primo head->next restituisce il puntatore al primo blocco
    (*(head->next)).next = NULL;
    printLista(head);
}