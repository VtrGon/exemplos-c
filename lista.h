#ifndef LISTA_ENCADEADA_H_INCLUDED
#define LISTA_ENCADEADA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Set das estruturas heterogeneas de dados */

typedef struct {
    int id;
    char titulo[55];
}Dado;

/* Contem dado e o endereco da proxima celula */
typedef struct Celula {
    Dado dado;
    struct Celula *prox;
}Celula;

/* Sao propriedades acessadas pela lista apenas as celulas de inicio,
 fim e a quantidade de itens da mesma dada por seu tamanho */
typedef struct {
    Celula *inicio, *fim;
    int tam;
}Lista;

/* Inicializar a lista */
void criar_lista(Lista *L) {
    /* Alocar o espaco na memoria da celula inicial */
    Celula *temp = (Celula*)malloc(sizeof(Celula));

    /* O inicio e fim propriedades da lista guardam o endereco de temp*/
    temp->prox = NULL;
    L->inicio = L->fim = temp;

    /* Quantidade de celulas iniciais da lista */
    L->tam = 0;
}

/* Verifica se o fim eh o comeco, se sim a lista esta vazia */
bool lista_vazia(Lista L) {
    return L.inicio == L.fim;
}

/* Adicionar uma celula no fim da lista */
void adicionar_fim(Lista *L, Dado dado) {
    Celula *temp = (Celula*)malloc(sizeof(Celula));

    /* Como ela se torna a ultima celula o prox aponta para NULL */
    temp->prox = NULL;

    /* set do dado na lista */
    temp->dado = dado;

    /* Aponta a propriedade prox do atual fim para o temp
    e atribui a ela o novo fim */
    L->fim->prox = temp;
    L->fim = temp;

    L->tam++;
}

/* Adicionar uma celula no inicio da lista */
void adicionar_inicio(Lista *L, Dado dado) {
    Celula *temp = (Celula*)malloc(sizeof(Celula));

    temp->prox = L->inicio;

    L->inicio->dado = dado;
    L->inicio = temp;

    L->tam++;
}

/* Adicionar uma celula na posicao escolhida da lista */
int adicionar_em(Lista *L, Dado dado, int pos) {
    /* Verifica se posicao esta entre o tamanho da lista */
    if(pos < 0 || pos >= L->tam) 
        return -1;

    /* Inicializa ant como inicio da lista */
    Celula *ant = L->inicio;

    /* Percorre lista ate a posicao desejada */
    for(int i = 0; i < pos; i++)
        ant = ant->prox;

    Celula *temp = (Celula*)malloc(sizeof(Celula));;

    temp->prox = ant->prox;
    ant->prox = temp;
    temp->dado = dado;

    L->tam++;

    return 0;
}

/* Apresenta dados da lista ao usuario */
void print_lista(Lista L) {
    Celula *temp = L.inicio->prox;

    printf("\n  ID          Titulo\n"
           " ----        --------\n");

    /* Apresenta dados enquanto nao chegar no fim da lista */
    while(temp != NULL) {
        printf("  %02d           %s\n", temp->dado.id, temp->dado.titulo);

         /* Seta o proprio temp como proxima celula */
        temp = temp->prox;
    }
}

/* Apaga da lista passando a posicao */
int remover_em(Lista *L, int pos) {
    if(pos < 0 || pos >= L->tam)
        return -1;

    Celula *ant = L->inicio;

    for(int i = 0; i < pos; i++)
        ant = ant->prox;

    /* Temp recebe o endereco do prox do ant e
    o prox do ant eh alterado para o prox do temp */
    Celula *temp = ant->prox;
    ant->prox = temp->prox;

    /* Libera memoria alocada do temp */
    free(temp);

    L->tam--;

    /* Se o novo prox do ant estiver vazio esse eh o fim da lista */
    if(ant->prox == NULL)
        L->fim = ant;

    return 0;
}

/* Desfazer lista */
void destruir_lista(Lista *L) {

    /* Enquanto a lista nao estiver vazia chama a funcao
    remover_em passando a primeira posicao da lista */
    while(!lista_vazia(*L))
        remover_em(L, 0);
}

#endif // LISTA_ENCADEADA_H_INCLUDED