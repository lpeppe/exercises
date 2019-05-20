#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int num1;
    int num2;
    struct node *next;
} node;

node *scomponi(int n)
{
    // head è un puntatore che contiene l'indirizzo di memoria del primo nodo della lista
    // last è un puntatore che contiene l'indirizzo di memoria dell'ultimo elemento della lista
    // p è un puntatore di appoggio per allocare la memoria
    node *head = NULL, *last, *p;
    for (int i = 1; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (i + j == n)
            {
                // alloca memoria per un nuovo nodo
                p = malloc(sizeof(node));
                // se la lista è vuota, inizializza head con il primo nodo
                if (head == NULL)
                    head = p;
                // altrimenti aggiungi il nuovo nodo alla fine della lista
                else
                    last->next = p;
                // assegna i campi del nodo
                p->num1 = i;
                p->num2 = j;
                p->next = NULL;
                // sposta il puntatore sul nuovo ultimo nodo
                last = p;
            }
        }
    }
    return head;
}

void printList(node *p)
{
    while (p != NULL)
    {
        printf("(%d, %d) ", p->num1, p->num2);
        p = p->next;
    }
    printf("\n");
    return;
}

int main()
{
    printList(scomponi(11));
    return 0;
}