#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Retorna endereco da matriz */
int** alocar(int m, int n) {
    /* Cria ponteiro para matriz */
    int **mtz;

    /* Aloca a memoria das linhas da matriz */
    mtz = (int**)malloc(m * sizeof(int*));

    /* Verifica se ocorreu como esperado. erro: Memoria insuficiente */
    if(mtz == NULL) return NULL;

    /* Aloca a memoria de cada coluna da matriz */
    for(int i = 0; i < m; i++) {
        mtz[i] = (int*)malloc(m * sizeof(int));

        /* Faz a verificação, por coluna */
        if(mtz[i] == NULL) return NULL;
    }

    return mtz;
}

/* Solicita ao usuario preencher a matriz */
void popular(int m, int n, int **mtz) {
    /* for entrelaçado para percorrer matriz por completo,
     solicitando ao usuário um inteiro por posição */
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++) {
            printf("\nDigite o valor da posicao %d/%d: ", i , j);
            scanf("%d", &mtz[i][j]);
        }
}

/* Preenche matriz com valores de 0 ou 1 */
void popular_bi(int m, int n, int **mtz) {
    srand(time(0));

    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            mtz[i][j] = rand() % 2;
}

/* Apresenta ao usuario */
void print_matriz(int m, int n,int **mtz) {
    printf("\nMatriz de %d/%d posicoes\n\n", m, n);

    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            /* if ternario para definir quebra da linha */
            printf("%d%s", mtz[i][j], (j == n - 1) ? "\n" : " ");
}

/* Retorna o maior valor da matriz */
int menor_valor(int m, int n, int **mtz) {
    int valor;

    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            /* Se o valor da posicao eh menor que a variavel
            valor entao ele eh o menor valor */
            if(mtz[i][j] < valor) valor = mtz[i][j];

    return valor;
}

/* Conta o numero de vizinhos em volta da posicao que sao iguais a 1 */
int vizinhos_vivos(int m, int n, int **mtz) {
    int qtd_vivos = 0;

    /* Compara valor das posicoes em volta da referencia com 1 */
    for(int i = -1; i < 2; i++)
        for(int j = -1; j < 2; j++)
            if(mtz[m-i][n-j] == 1) qtd_vivos++;

    /* Posicao foi contada no loop, if para desconsidera-la */
    if(mtz[m][n] == 1) qtd_vivos--;

    return qtd_vivos;
}

int** liberar(int m, int n, int **mtz) {
    if(mtz == NULL) return NULL;

    /* Libera cada uma das colunas */
    for(int i = 0; i < m; i++)
        free(mtz[i]);

    /* Por fim, libera a memória das linhas */
    free(mtz);
    return NULL;
}

#endif // MATRIZ_H_INCLUDED
