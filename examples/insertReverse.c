#include <stdlib.h>
#include <stdio.h>

typedef struct nd
{
    int num;
    struct nd *next;
} Node;

Node *insertNode(Node **head, int num)
{
    Node *p = malloc(sizeof(Node));
    p->num = num;
    p->next = *head;
    *head = p;
}

void printLista(Node *p)
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
    Node *head = NULL;
    insertNode(&head, 5);
    insertNode(&head, 6);
    printLista(head);
}