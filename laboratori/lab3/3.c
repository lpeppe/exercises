#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void conversioneInBin(int n) {
    int esp, ris_max;
    // il logaritmo in base 2 calcola l'esponente della potenza
    // massima del 2 minore di n
    for (esp = (int)log2(n); esp >= 0; esp--) {
        ris_max = (int)pow(2, esp);
        if (ris_max <= n) {
            n = n - ris_max;
            printf("1");
        } else
            printf("0");
    }
    printf("\n");
}

int conversioneInDecConNum(int num1) {
    // 10011011
    char num[100];
    sprintf(num, "%d", num1);
    int i, digit = 0, pow_max = strlen(num) - 1, num_dec_tot = 0;
    for (i = 0; i <= strlen(num); i++) {
        if (num[i] == '1') {
            // num_dec_tot += (int)pow(2, pow_max);
            num_dec_tot = num_dec_tot + (int)pow(2, pow_max);
        }
        pow_max--;
    }
    return num_dec_tot;
}
int conversioneInDecConStr(char *num) {
    // 10011011
    int i, digit = 0, pow_max = strlen(num) - 1, num_dec_tot = 0;
    for (i = 0; i <= strlen(num); i++) {
        if (num[i] == '1') {
            // num_dec_tot += (int)pow(2, pow_max);
            num_dec_tot = num_dec_tot + (int)pow(2, pow_max);
        }
        pow_max--;
    }
    return num_dec_tot;
}

int main() {
    int n, buff[100];

    // conversione in binario
    // while (1) {
    //     printf("Inserisci numero: ");
    //     scanf("%d", &n);
    //     printf("Conversione in binario di %d: ", n);
    //     conversioneInBin(n);
    // }

    // versione con la stringa
    while (1) {
        printf("Inserisci numero: ");
        scanf("%s", buff);
        printf("Conversione in decimale di %s\n: %d\n", buff,
               conversioneInDecConStr(buff));
    }
    // versione con numero
    while (1) {
        printf("Inserisci numero: ");
        scanf("%d", n);
        printf("Conversione in decimale di %d\n: %d\n", n,
               conversioneInDecConNum(n));
    }
}

// 100011111