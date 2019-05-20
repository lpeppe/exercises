#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num, temp;
    srand(time(NULL));
    num = rand() % 101;
    printf("ho pensato a un numero tra 0 e 100.\nIndovinalo:  ");
    scanf("%d", &temp);
    while (temp != num) {
        // if (temp < num)
        //     printf("No, troppo piccolo. Riprova: ");
        // else
        //     printf("No, troppo grande. Riprova: ");
        printf("No, troppo %s. Riprova: ", temp < num ? "piccolo" : "grande");
        scanf("%d", &temp);
    }
    printf("Bravo! Era il %d\n", num);
    return 0;
}