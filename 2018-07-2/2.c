#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int ramp10(int num)
{
    int num1, num2;

    // calcola il numero di digit del numero in input facendone il log in base 10.
    int numDigits = (int)log10(num);
    for (int i = 1; i < numDigits + 1; i++)
    {
        // num1 è la parte sinistra del numero che andiamo ad estrarre
        num1 = num / (int)pow(10, i);
        // num2 è la parte destra
        num2 = (num - num1 * (int)pow(10, i)) / (int)pow(10, i - 1);
        // restituiamo 0 in output se la parte sinistra è 0, oppure se i num1 non è divisibile per num2
        if (num2 == 0 || num1 % num2 != 0)
            return 0;
    }
    return 1;
}

int main(int argc, char **argv)
{
    if (argc < 2)
        return 0;
    int k = atoi(argv[1]);
    // count memorizza quanti numeri ramp10 abbiamo trovato. J è il parametro 
    // che viene passato in input alla funzione e inizia da 10 perchè un numero
    // ramp10 deve avere almeno 2 cifre
    for (int count = 0, j = 10; count < k; j++)
    {
        if (ramp10(j))
        {
            count++;
            printf("%d ", j);
        }
    }
}
