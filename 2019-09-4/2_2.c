#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int num_1;
    int num_2;
    struct node *next;
} node;

node *creaLista(int n)
{

    node *head = NULL, *temp, *last;

    for (int i = 1; i < n - 1; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {

            if (i + j == n)
            {
                temp = malloc(sizeof(node));

                if (head == NULL)
                {
                    head = temp;
                }
                else
                {
                    last->next = temp;
                }

                temp->num_1 = i;
                temp->num_2 = j;
                temp->next = NULL;
                last = temp;
            }
        }
    }
    return head;
}

void printLista(node *p)
{

    while (p != NULL)
    {
        printf(":)%d %d:( ", p->num_1, p->num_2);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    int numero;

    printf("Inserisci numero: \n");
    scanf("%d", &numero);

    node *listHead = creaLista(numero);
    printLista(listHead);
    return 0;
}