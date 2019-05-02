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

// inserisce un nodo in testa alla lista.
// In questo modo è possibile invertire l'ordine della lista di output
// se la lista sulla quale si invoca la funzione è:
// "aa"->"bb"->"cc" e si passa in input "zz", la nuova lista sarà:
// "zz"->"aa"->"bb"->"cc"
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
    // scorro la prima lista
    while (a != NULL)
    {
        // scorro la seconda lista
        while (b != NULL)
        {
            // se le due stringhe che stiamo scorrendo sono uguali,
            // aggiungile alla lista di output
            if (strcmp(a->wrd, b->wrd) == 0)
            {
                // passo ad insertNode l'indirizzo di memoria di
                // toReturnHead, in modo tale che la modifica sia visibile
                // dalla funzione chiamante
                insertNode(&toReturnHead, a->wrd);
                break;
            }
            // passo alla stringa successiva nella seconda lista
            b = b->prox;
        }
        // passo alla stringa successiva nella prima lista
        a = a->prox;
        // faccio ripartire b dall'inizio (come quando in un for interno azzero j)
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
    // scorro le liste fin quando non le esaurisco entrambe
    while (a != NULL || b != NULL)
    {
        // se la prima lista è finita, aggiungo alla lista di output
        // tutti gli elementi della seconda
        if (a == NULL)
        {
            insertNode(&mergedHead, b->wrd);
            b = b->prox;
        }
        // se la seconda è finita, aggiungo alla lista di output
        // tutti gli elementi della prima
        else if (b == NULL)
        {
            insertNode(&mergedHead, a->wrd);
            a = a->prox;
        }
        // se nessuna delle due liste è esaurita
        else
        {
            // faccio un confronto lessicografico tra le due stringhe
            strcmpRes = strcmp(a->wrd, b->wrd);
            // se a è più piccola di b (in ordine lessicografico)
            if (strcmpRes < 0)
            {
                insertNode(&mergedHead, a->wrd);
                a = a->prox;
            }
            // se strcmpRes == 0, significa che la stringa è presente
            // in entrambe le liste, quindi non deve essere inserita in quella
            // di output
            else if (strcmpRes == 0)
            {
                a = a->prox;
                b = b->prox;
            }
            // se si arriva qui, significa che b è più piccola di a
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
    // alloca memoria per la CdL da restituire in output
    CdL *toReturn = malloc(sizeof(CdL));
    // pone il campo a della CdL uguale all'output della funzione getStringsInCommon
    toReturn->a = getStringsInCommon(c);
    // pone il campo b della CdL uguale all'output della funzione getStringsNotInCommon
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
    strcpy(firstA->wrd, "uu");
    strcpy(secondA->wrd, "vv");
    strcpy(thirdA->wrd, "zz");
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