#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define tam_hash 13

/* Set das estruturas heterogeneas  de dados */

typedef struct {
    int id;
    char titulo[55];
}Dado;

/* Sao propriedades acessadas pela hash um vetor de ponteiros,
 o tamanho total e sua quantidade de dados */
typedef struct {
    Dado **dados;
    int tam; 
    int qtd; 
}Hash;

/* Inicializar a tabela Hash */
Hash* criar_tabela(int tamanho) {
    /* Alocando memoria da Hash e do vetor de ponteiros */
    Hash *H = (Hash*)malloc(sizeof(Hash));
    H->dados = (Dado**)malloc(tamanho * sizeof(Dado*));

    /* Definindo tamanho e quantidade inicial de dados da Hash */
    H->tam = tamanho;
    H->qtd = 0;

    /* Atribuir NULL a cada um dos ponteiros do vetor */
    for(int i = 0; i < tamanho; i++)
        H->dados[i] = NULL;

    /* Retorna o endereco da Hash */
    return H;
}

/* Verifica se a quantidade de dados eh igual a zero,
 se sim a hash esta vazia */
bool tabela_vazia(Hash H) {
    return H.qtd == 0;
}

/* Funcao Hash para determinar posicao onde o dado
sera salvo utilizando o ID como chave */
int posicao(int id, int tamanho) {
    float constante = 0.742021;
    float aux = id * constante;

    /* Tira a parte inteira de aux*/
    aux -= (int)aux;

    /* Retorna a parte inteira da multiplicacao */
    return (int)(tamanho * aux);
}


/* Adiciona os dados na Hash com tratamento de colisoes
com enderecamento aberto e sondagem linear */
int adicionar(Hash *H, Dado dado) {
    int pos;

    /* Verifica se Hash esta com limite de dados */
    if(H->qtd == H->tam)
        return -1;

    /* Calcula posicao atraves da funcao Hash */
    pos = posicao(dado.id, H->tam);

    /* Percorre no pior dos casos o tamanho da tabela O(n)*/
    for(int i = 0; i < H->tam; i++) {
        /* sondagem linear */
        pos = (pos + i) % H->tam;

        /* Salva dado na Hash e sai da funcao quando
        encontrar posicao cujo valor eh NULL */
        if(H->dados[pos] == NULL) {
            Dado *temp = (Dado*)malloc(sizeof(Dado));
            *temp = dado;
            H->dados[pos] = temp;
            H->qtd++;

            return 0;
        }
    }
    
    return -1;
}

/* Procura dado na Hash utilizando o ID como chave */
int buscar(Hash *H, int id, Dado *dado) {
    int pos;

    pos = posicao(id, H->tam);

    /* Percorre a Hash ate encontrar o dado */
    for(int i = 0; i < H->tam; i++) {
        pos = (pos + i) % H->tam;

        /* Se posicao estiver vazia sai da
        funcao e retorna erro */
        if(H->dados[pos] == NULL)
            return -1;

        /* Se encontrar o retorna por passagem de parametro
         por referencia no endereco da variavel dado */
        if(H->dados[pos]->id == id) {
            *dado = *H->dados[pos];

            return 0;
        }
    }

    /* Passou pela Hash e nao encontrou o dado */
    return -1;
}

/* Apresenta dados da Hash ao usuario */
void print_tabela(Hash H) {
    printf("\n  ID          Titulo\n"
           " ----        --------\n");

    /* Percorre toda a Hash */
    for(int i = 0; i < H.tam; i++)
        /* Mostra valores diferentes de NULL ao usuario */
        if(H.dados[i] != NULL)
            printf("  %02d           %s\n", H.dados[i]->id, H.dados[i]->titulo);
}

/* Procura dado na Hash utilizando o ID como chave e
coloca sua posicao na Hash apontando para NULL */
int apagar(Hash *H, int id) {
    int pos;

    pos = posicao(id, H->tam);

    for(int i = 0; i < H->tam; i++) {
        pos = (pos + i) % H->tam;

        if(H->dados[pos] == NULL)
            return -1;

        if(H->dados[pos]->id == id) {
            H->dados[pos] = NULL;

            return 0;
        }
    }

    return -1;
}

#endif // HASH_H_INCLUDED