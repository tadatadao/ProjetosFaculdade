#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição das estruturas

typedef struct {
    char nome[100];
    char condicaoSaude[10];
} Cliente;

typedef struct No {
    Cliente cliente;
    struct No* proximo;
} No;

typedef struct {
    No* inicio;
    No* fim;
} Fila;

// Funções auxiliares

Fila* criarFila() {
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
}

int filaVazia(Fila* fila) {
    return (fila->inicio == NULL);
}

void inserirNaFila(Fila* fila, Cliente cliente) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->cliente = cliente;
    novoNo->proximo = NULL;

    if (filaVazia(fila)) {
        fila->inicio = novoNo;
        fila->fim = novoNo;
    } else {
        fila->fim->proximo = novoNo;
        fila->fim = novoNo;
    }
}

Cliente removerDaFila(Fila* fila) {
    if (filaVazia(fila)) {
        Cliente clienteVazio;
        strcpy(clienteVazio.nome, "");
        strcpy(clienteVazio.condicaoSaude, "");
        return clienteVazio;
    }

    No* noRemovido = fila->inicio;
    Cliente clienteRemovido = noRemovido->cliente;

    fila->inicio = fila->inicio->proximo;
    free(noRemovido);

    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }

    return clienteRemovido;
}

void destruirFila(Fila* fila) {
    while (!filaVazia(fila)) {
        removerDaFila(fila);
    }
    free(fila);
}

void imprimirFila(Fila* fila) {
    if (filaVazia(fila)) {
        printf("A fila está vazia.\n");
        return;
    }

    No* atual = fila->inicio;
    int posicao = 1;
    while (atual != NULL) {
        printf("Posição %d: %s\n", posicao, atual->cliente.nome);
        atual = atual->proximo;
        posicao++;
    }
}

// Funções do programa

void montarFilas() {
    FILE* arquivo;
    arquivo = fopen("DadosChegada.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    Fila* filaEspera = criarFila();
    Fila* filaBuffetD = criarFila();
    Fila* filaBuffetH = criarFila();
    Fila* filaBuffetN = criarFila();

    char linha[100];
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        char nome[100];
        char condicaoSaude[10];
        sscanf(linha, "%[^;];%s", nome, condicaoSaude);

        Cliente cliente;
        strcpy(cliente.nome, nome);
        strcpy(cliente.condicaoSaude, condicaoSaude);

        if (strcmp(condicaoSaude, "D") == 0) {
            inserirNaFila(filaBuffetD, cliente);
        } else if (strcmp(condicaoSaude, "H") == 0) {
            inserirNaFila(filaBuffetH, cliente);
        } else if (strcmp(condicaoSaude, "N") == 0) {
            inserirNaFila(filaBuffetN, cliente);
        } else {
            inserirNaFila(filaEspera, cliente);
        }
    }

    fclose(arquivo);

    printf("Filas montadas com sucesso!\n");
    printf("----------------------------\n");
    printf("Fila de espera:\n");
    imprimirFila(filaEspera);
    printf("----------------------------\n");
    printf("Fila do buffet D:\n");
    imprimirFila(filaBuffetD);
    printf("----------------------------\n");
    printf("Fila do buffet H:\n");
    imprimirFila(filaBuffetH);
    printf("----------------------------\n");
    printf("Fila do buffet N:\n");
    imprimirFila(filaBuffetN);

}
