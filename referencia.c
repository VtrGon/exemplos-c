#include <stdio.h>
#include <stdlib.h>

void fatorial(int n, int *valor) {
    *valor = 1;

    for(int i = 2; i <= n; i++)
        *valor *= i;
}

int main() {
    int fat = 5;
    int valor;

    /* Fatorial de fat*/
    fatorial(fat, &valor);
    printf("\n\nFatorial de %d\n%d",fat, valor);

    return 0;
}