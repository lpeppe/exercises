#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int giorno;
    int mese;
    int anno;
} Data;

void stampaLettere(Data d) {
    char *k = malloc(sizeof(char) * 5);
    char mesi[12][4] = {
        "Gen",
        "Feb",
        "Mar",
        "Apr",
        "Mag",
        "Giu",
        "Lug",
        "Ago",
        "Set",
        "Ott",
        "Nov",
        "Dic"
    };
    if(d.anno < 0)
        k = "a.C.";
    else
        k = "d.C.";
    printf("%d %s %d %s\n", d.giorno, mesi[d.mese-1], abs(d.anno), k);
}

void stampa(Data d) { printf("%d/%d/%d\n", d.giorno, d.mese, d.anno); }

int dateCmp(Data d1, Data d2) {
    if (d1.anno != d2.anno) {
        if (d1.anno < d2.anno)
            return -1;
        return 1;
    }
    if (d1.mese != d2.mese) {
        if (d1.mese < d2.mese)
            return -1;
        return 1;
    }
    if (d1.giorno != d2.giorno) {
        if (d1.giorno < d2.giorno)
            return -1;
        return 1;
    }

    return 0;
}

int main() {
    Data d1, d2;
    printf("Inserisci due date: ");
    scanf("%d/%d/%d", &d1.giorno, &d1.mese, &d1.anno);
    // scanf("%d/%d/%d", &d2.giorno, &d2.mese, &d2.anno);
    // if (dateCmp(d1, d2) == -1)
    //     printf("le date sono in ordine cronologico.\n");
    // if (dateCmp(d1, d2) == 1)
    //     printf("le date sono in ordine cronologico inverso.\n");
    // if (dateCmp(d1, d2) == 0)
    //     printf("le date sono uguali.\n");
    stampaLettere(d1);
}