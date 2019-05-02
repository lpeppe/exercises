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

void insertNode(List *head, char *wrd)
{
    List p = malloc(sizeof(Node));
    p->wrd = wrd;
    p->prox = *head;
    *head = p;
}

List getStringsInCommon(CdL c)
{
    List toReturnHead = NULL, toReturnLast;
    List headB = c.b;
    List a = c.a;
    List b = headB;
    while (a != NULL)
    {
        while (b != NULL)
        {
            if (strcmp(a->wrd, b->wrd) == 0)
            {
                insertNode(&toReturnHead, a->wrd);
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
    List mergedHead = NULL, mergedLast, p;
    List a = c.a;
    List b = c.b;
    int strcmpRes;
    while (a != NULL || b != NULL)
    {
        if (a == NULL)
        {
            insertNode(&mergedHead, b->wrd);
            b = b->prox;
        }
        else if (b == NULL)
        {
            insertNode(&mergedHead, a->wrd);
            a = a->prox;
        }
        else
        {
            strcmpRes = strcmp(a->wrd, b->wrd);
            if (strcmpRes < 0)
            {
                insertNode(&mergedHead, a->wrd);
                a = a->prox;
            }
            else if (strcmpRes == 0)
            {
                a = a->prox;
                b = b->prox;
            }
            else
            {
                insertNode(&mergedHead, b->wrd);
                b = b->prox;
            }
        }
    }
    return mergedHead;
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
    Node *firstA, *secondA, *thirdA, *firstB,
        *secondB, *thirdB, *fourthB;
    List a, b;
    CdL cdl;

    // allocate memory
    firstA = malloc(sizeof(Node));
    secondA = malloc(sizeof(Node));
    thirdA = malloc(sizeof(Node));
    firstB = malloc(sizeof(Node));
    secondB = malloc(sizeof(Node));
    thirdB = malloc(sizeof(Node));
    fourthB = malloc(sizeof(Node));
    firstA->wrd = malloc(3 * sizeof(char));
    secondA->wrd = malloc(3 * sizeof(char));
    thirdA->wrd = malloc(3 * sizeof(char));
    firstB->wrd = malloc(3 * sizeof(char));
    secondB->wrd = malloc(3 * sizeof(char));
    thirdB->wrd = malloc(3 * sizeof(char));
    fourthB->wrd = malloc(3 * sizeof(char));

    // assign strings
    strcpy(firstA->wrd, "aa");
    strcpy(secondA->wrd, "bb");
    strcpy(thirdA->wrd, "cc");
    strcpy(firstB->wrd, "aa");
    strcpy(secondB->wrd, "bb");
    strcpy(thirdB->wrd, "cc");
    strcpy(fourthB->wrd, "zz");

    // link the lists
    firstA->prox = secondA;
    secondA->prox = thirdA;
    thirdA->prox = NULL;
    firstB->prox = secondB;
    secondB->prox = thirdB;
    thirdB->prox = fourthB;
    fourthB->prox = NULL;

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
    free(thirdB->wrd);
    free(fourthB->wrd);
    free(firstA);
    free(secondA);
    free(thirdA);
    free(firstB);
    free(secondB);
    free(thirdB);
    free(fourthB);
}