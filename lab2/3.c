#include <stdio.h>
#include <stdlib.h>

int main() {
    int num, lung_max = 1, lung_temp = 1, temp;
    scanf("%d", &temp);
    while (1) {
        scanf("%d", &num);
        if (num == 0)
            break;
        if (num > temp) {
            lung_temp++;
        } else
            lung_temp = 1;
        if (lung_temp > lung_max)
            lung_max = lung_temp;
        temp = num;
    }
    printf("Lung. max = %d\n", lung_max);
    return 0;
}