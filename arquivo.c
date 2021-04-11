#include <stdio.h>
#include <stdlib.h>

#define tam_vetor 13

typedef struct {
    int id;
    char titulo[55];
}Dado;

/* Vai ao arquivo save.txt e carrega dados para o vetor V */
int ler(Dado *V, FILE *arq, int *cont) {
    /* Abre arquivo em modo de leitura (read) */
    arq = fopen("save.txt", "r");

    if(!arq) {
        printf("Erro! Nao foi possivel abrir o arquivo.\n");
        return -1;
    }

    /* Enquanto o fim do arquivo nao chega essa funcao sera
    executada (end of file)*/
    for(int i = 0; !feof(arq); i++) {
        /* Utiliza o vetor para guardar as informacoes
         do arquivo linha por linha */
        fscanf(arq, "%d\t%[^\n]\n", &V[i].id, &V[i].titulo);

        /* Entrega a quantidade de dados carregados por passagem
         de parametro por referencia com a variavel cont*/
        *cont = *cont + 1;
    }

    /* Fecha o arquivo */
    fclose(arq);
    return 0;
}

/* Ao finalizar o programa essa funcao eh chamada para
salvar os dados no arquivo save.txt */
int gravar(Dado *V, FILE *arq, int *cont) {
    /* Abre arquivo em modo de escrita (write) */
    arq = fopen("save.txt", "w");

    if(!arq) {
        printf("Erro! Nao foi possivel abrir o arquivo.\n");
        return -1;
    }

    /* Percorre todo o vetor e suas informacoes sao salvas por linha */
    for(int i = 0; i < *cont; i++)
        fprintf(arq, "%d\t%s\n", V[i].id, V[i].titulo);

    fclose(arq);
    return 0;
}

int main() {
    FILE *arq;
    Dado vetor[tam_vetor];
    int qtd_elementos = 0;

    ler(vetor, arq, &qtd_elementos);

    for(int i = 0; i < qtd_elementos; i++)
        printf("%d\t%s\n", vetor[i].id, vetor[i].titulo);

    gravar(vetor, arq, &qtd_elementos);

    return 0;
}