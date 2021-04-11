#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n) {
    if(n == 0 || n == 1) return 1;

    return fibonacci(n-1) + fibonacci(n-2);
}

int somatorio(int n) {
    int soma = n;

    if(n > 0) soma += somatorio(n - 1);

    return soma;
}

int main() {
    int fib = 10;
    int som = 5;

    /* Sequencia de fibonacci */
    printf("\nSequencia de fibonacci de %d posicoes\n", fib);
    for(int i = 0; i < fib; i++)
        printf("%d ", fibonacci(i));

    /* Somatorio de som*/
    printf("\n\nSomatorio de %d\n%d",som, somatorio(som));

    return 0;
}