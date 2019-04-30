#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct nd
{
    char *wrd;
    struct nd *prox;
} Node;

typedef Node *List;

typedef struct
{
    List a, b;
} CdL;

List getStringsInCommon(CdL c)
{
    List toReturnHead = NULL, toReturnLast, p;
    List headA = c.a;
    List headB = c.b;
    List a = headA;
    List b = headB;
    while (a != NULL)
    {
        while (b != NULL)
        {
            if (strcmp(a->wrd, b->wrd) == 0)
            {
                p = malloc(sizeof(Node));
                if (toReturnHead == NULL)
                    toReturnHead = p;
                else
                    toReturnLast->prox = p;
                p->wrd = a->wrd;
                p->prox = NULL;
                toReturnLast = p;
                break;
            }
            b = b->prox;
        }
        a = a->prox;
        b = headB;
    }
    return toReturnHead;
}

List getStringsNotInCommon(CdL c)
{
    List toReturnHead = NULL, toReturnLast, p;
    List headA = c.a;
    List headB = c.b;
    List a = headA;
    List b = headB;
    int flag = 0;
    while (a != NULL)
    {
        while (b != NULL)
        {
            if (strcmp(a->wrd, b->wrd) == 0)
            {
                flag = 1;
                break;
            }
            b = b->prox;
        }
        if (flag == 0)
        {
            p = malloc(sizeof(Node));
            if (toReturnHead == NULL)
                toReturnHead = p;
            else
                toReturnLast->prox = p;
            p->wrd = a->wrd;
            p->prox = NULL;
            toReturnLast = p;
        }
        flag = 0;
        a = a->prox;
        b = headB;
    }
    return toReturnHead;
}

CdL *split(CdL c)
{
    CdL *toReturn = malloc(sizeof(CdL));
    toReturn->a = getStringsInCommon(c);
    toReturn->b = getStringsNotInCommon(c);
    return toReturn;
}

void printList(List p)
{
    while (p != NULL)
    {
        printf("%s ", p->wrd);
        p = p->prox;
    }
    printf("\n");
}

void printCdL(CdL c)
{
    printf("Lista a:\n");
    printList(c.a);
    printf("-------------------------\nLista b:\n");
    printList(c.b);
}

int main()
{
    Node *firstA, *secondA, *thirdA, *firstB, *secondB;
    List a, b;
    CdL cdl;

    // allocate memory
    firstA = malloc(sizeof(Node));
    secondA = malloc(sizeof(Node));
    thirdA = malloc(sizeof(Node));
    firstB = malloc(sizeof(Node));
    secondB = malloc(sizeof(Node));
    firstA->wrd = malloc(3 * sizeof(char));
    secondA->wrd = malloc(3 * sizeof(char));
    thirdA->wrd = malloc(3 * sizeof(char));
    firstB->wrd = malloc(3 * sizeof(char));
    secondB->wrd = malloc(3 * sizeof(char));

    // assign strings
    strcpy(firstA->wrd, "aa");
    strcpy(secondA->wrd, "bb");
    strcpy(thirdA->wrd, "cc");
    strcpy(firstB->wrd, "aa");
    strcpy(secondB->wrd, "tt");

    // link the lists
    firstA->prox = secondA;
    secondA->prox = thirdA;
    thirdA->prox = NULL;
    firstB->prox = secondB;
    secondB->prox = NULL;

    a = firstA;
    b = firstB;
    cdl.a = a;
    cdl.b = b;
    printCdL(*split(cdl));

    // free up memory
    free(firstA->wrd);
    free(secondA->wrd);
    free(thirdA->wrd);
    free(firstB->wrd);
    free(secondB->wrd);
    free(firstA);
    free(secondA);
    free(thirdA);
    free(firstB);
    free(secondB);
}