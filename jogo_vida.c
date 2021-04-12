#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

#define tam_matriz 13

/* Regras do Jogo da Vida
    - Uma celula sobrevive se tem exatamente 2 ou 3
    vizinhos vivos, caso contrario morre.
    - Uma nova celula eh criada em uma posicao vazia
    quando ela tem exatamente 3 vizinhos vivos. */

/* Algoritmo
    [x] alocar matriz para ponteiro
    [x] popular matriz com zeros e uns aleatorios
    [x] contar vizinhos
    [x] aplicar regra de negocio
    [x] printar matriz anterior e printar apos iteracao
    [x] liberar matriz */

void iteracao(int m, int n, int **mtz) {
    int qtd_vizinhos;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++) {
            qtd_vizinhos = vizinhos_vivos(i, j, mtz);

            if(mtz[i][j] == 1) {
                if(qtd_vizinhos == 2 || qtd_vizinhos == 3) mtz[i][j] = 1;
                else mtz[i][j] = 0;
            }

            else {
                if(qtd_vizinhos == 3) mtz[i][j] = 1;
                else mtz[i][j] = 0;
            }
        }
}

int main() {
    int **matriz;

    matriz = alocar(tam_matriz, tam_matriz);
    popular_bi(tam_matriz, tam_matriz, matriz);

    print_matriz(tam_matriz, tam_matriz, matriz);

    /* Realizar tratamento na funcao vizinhos_vivos.
     Contando para alem dos limites da matriz */
    iteracao(tam_matriz, tam_matriz, matriz);

    print_matriz(tam_matriz, tam_matriz, matriz);

    liberar(tam_matriz, tam_matriz, matriz);

    return 0;
}
