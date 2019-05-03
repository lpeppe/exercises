#include <stdlib.h>
#include <stdio.h>

int main()
{
    char buf[50];
    // la sprintf funziona come la printf
    // con la differenza che l'output viene inserito
    // all'interno della stringa fornita come
    // primo parametro
    sprintf(buf, "%d %c %s", 4, 'a', "ciao");
    // printf("%s\n", buf);
    strcpy(buf, "sdf");
    // printf("%s\n", buf);
    sprintf(buf, "%s%c", buf, 'c');
    printf("%s\n", buf);
}