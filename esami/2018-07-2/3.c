#include <stdlib.h>
#include <stdio.h>

int pref(char *str1, char *str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    // se la seconda stringa è più lunga della prima str1 non può essere prefisso di str2
    if (len2 < len1)
        return 0;
    // scorre la prima stringa e controlla che il primo carattere della prima stringa sia
    // uguale al primo carattere della seconda, che il secondo carattere della prima stringa
    // sia uguale al secondo carattere della seconda striga e così via. Se la condizione
    // non è verificata restituisce 0;
    for (int i = 0; i < len1; i++)
        if (str1[i] != str2[i])
            return 0;
    return 1;
}

void shift(char s[], char c)
{
    int len = strlen(s), i;
    // sostituisce ogni char col suo successore
    for (i = 1; i < len; i++)
        s[i - 1] = s[i];
    // inserisce c nell'ultima posizione della stringa
    s[len - 1] = c;
}

int main()
{
    printf("%s\n", pref("pari", "sipario") == 1 ? "Vero" : "Falso");
    char str[] = "pari";
    shift(str, 'a');
    printf("%s\n", str);
}