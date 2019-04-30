#include <stdlib.h>
#include <stdio.h>

// La funzione controlla che i numeri nell'array siano tutti uguali
// restituisce 0 se non sono tutti uguali, 1 altrimenti
int tuttiUguali(int *p, int n)
{
    int temp = p[0];
    for (int i = 1; i < n; i++)
    {
        if (temp != p[i])
            return 0;
    }
    return 1;
}

// La funzione controlla che i numeri nell'array siano tutti diversi
// restituisce 0 se non sono tutti diversi, 1 altrimenti
int tuttiDiversi(int *p, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (p[i] == p[j])
                return 0;
        }
    }
    return 1;
}

int main()
{
    // k è la grandezza dell'array
    // n è il numero che l'utente inserisce ad ogni iterazione
    int k, *p, n, count = 0;
    printf("Inserisci un numero k: ");
    scanf("%d", &k);
    p = calloc(k, sizeof(int));
    while (1)
    {
        scanf("%d", &n);
        if (n == 0)
            break;
        p[count % k] = n;
        count++;
        if (count >= k)
            if (tuttiUguali(p, k) == 1 || tuttiDiversi(p, k) == 1)
                break;
    }
    free(p);
    return 0;
}