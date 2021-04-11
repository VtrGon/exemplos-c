#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Verifica se numero eh primo */
bool primo(int n) {
    for(int i = 2; i <= n; i++)
        /* Se o resto da divisao de n por i for 0 e 
         nao for o proprio numero esse nao eh primo */
        if(n % i == 0 && i != n) return false;

    return true;
}

int main() {
    int pri = 7;

    /* Utiliza if ternario para a resposta */
    printf("\nO %d %s primo", pri, (primo(pri)) ? "eh" : "nao eh");

    return 0;
}