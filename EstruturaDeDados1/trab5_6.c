//Marcos Tadao Shoji
//RA: 2374200
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define NaoVisitado 0
#define Visitado    1
#define NoFinal     2
#define TamanhoNome 100

typedef struct{
    char* nomes[TamanhoNome];
    int chave;
    int coordenadaX;
    int coordenadaY;
}DadosClientes;

typedef struct grafoM{
    int  **matriz;
    int  vertices;
    bool digrafo; // se sim true, caso contrário false
    DadosClientes* clientes;
}GrafoMatriz;

typedef struct verticeAuxiliar {
    int precedente;
    float estimativa;
    bool fechado_aberto;//0_1  false_true
    //struct verticeAuxiliar* anterior;
    //struct verticeAuxiliar* proximo;
    int key;
} VerticeAuxiliar;

typedef struct matrizAuxiliar {
    int quantidade;
    VerticeAuxiliar* matriz;
} MatrizAuxiliar;

typedef struct obj {
    int key;
    char nome[50];
    double coordX;
    double coordY;
    MatrizAuxiliar matrizAux;
} Objeto;

typedef struct tabelaHash {
    Objeto* array;
    int qtdElem;
} TabelaHash;

double calcularDistancia(double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    return sqrt(dx * dx + dy * dy);
}

void manipulaArquivo(GrafoMatriz *grafo){
    char nomeArquivo[100];
    char nomeArquivo2[100];
    int numClientes;
    int aux = 0;
    int chave = 1;

    grafo = (GrafoMatriz*)malloc(sizeof(GrafoMatriz));//aloca memoria para o grafo

    printf("\nDigite o nome do arquivo de adjacencia: ");
    scanf("%s", nomeArquivo);
    setbuf(stdin,NULL);

    printf("\nDigite a quantidade de clientes: ");
    scanf("%d", &numClientes);
    setbuf(stdin,NULL);

    grafo->vertices = numClientes;// numero de vertices igual a quantidade de clientes

    grafo->clientes = (DadosClientes*)malloc(numClientes * sizeof(DadosClientes));//alocacao

    FILE* arquivo = fopen(nomeArquivo, "r");
    
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }//abertura e tratamento de arquivo

    char linha[TamanhoNome * numClientes];//variavel para ler linha por linha
    fgets(linha, sizeof(linha), arquivo);//leeitura de linha

    char* token = strtok(linha, ",");
    while (token != NULL) {
        aux++;
        token = strtok(NULL, ",");
    }

    // Ignorar a primeira coluna (nomes das pessoas)
    fgets(linha, sizeof(linha), arquivo);
    
    // Preencher matriz de adjacência
    int i = 0;
    while (fgets(linha, sizeof(linha), arquivo)) {
        char* numero = strtok(linha, ",");
        int j = 0;
        while (numero != NULL) {
            if (j > 0) {  // Ignorar a primeira coluna
                if (i > 0) {
                    grafo->matriz[i - 1][j - 1] = atoi(numero);
                } else {
                    strcpy(grafo->clientes[j - 1].nomes, numero); // Copiar o nome
                    grafo->clientes[j - 1].chave = chave++; // Atribuir chave                    
                }
            }
            numero = strtok(NULL, ",");
            j++;
        }
        i++;
    }
    
    fclose(arquivo);

    printf("\nDigite o nome do arquivo de coordenadas: ");
    scanf("%s", nomeArquivo2);
    setbuf(stdin,NULL);

    FILE* arquivoPesos = fopen(nomeArquivo2, "r");
    
    if (arquivoPesos == NULL) {
        printf("Erro ao abrir o arquivo de pesos.\n");
        fclose(arquivo);
        return;
    }

    char linhaPeso[TamanhoNome * numClientes];
    fgets(linhaPeso, sizeof(linhaPeso), arquivoPesos);
    
    int k = 0;
    while (fgets(linhaPeso, sizeof(linhaPeso), arquivoPesos)) {
        char* tokenPeso = strtok(linhaPeso, ",");
        int j = 0;
        while (tokenPeso != NULL) {
            if (j > 0) {  // Ignorar a primeira coluna
                if (j == 2) {
                    grafo->clientes[k].coordenadaX = atof(tokenPeso);
                } else if (j == 3) {
                    grafo->clientes[k].coordenadaY = atof(tokenPeso);
                }
            }
            tokenPeso = strtok(NULL, ",");
            j++;
        }
        
        k++;
    }
}

void inicializaTabelaHash (TabelaHash *t, int qtdElem) {
    t->qtdElem = qtdElem;

    t->array = (Objeto*) malloc(qtdElem*sizeof(Objeto));

    for (int i = 0; i < qtdElem - 1; i++) {
        t->array[i].key = i+1;
        t->array[i].nome[0] = '\0';
        t->array[i].coordX = 0;
        t->array[i].coordY = 0;
    }
}//inicializaTabelaHash

void inicializaMatrizAuxiliar(MatrizAuxiliar* matriz, int quantidade){
    matriz->quantidade = quantidade;

    matriz->matriz = (VerticeAuxiliar*) malloc(quantidade*sizeof(VerticeAuxiliar));

    matriz->matriz[0].precedente = -1;
    matriz->matriz[0].estimativa = 0;
    matriz->matriz[0].fechado_aberto = true;
    //matriz->matriz[0].anterior = NULL;
    //matriz->matriz[0].proximo = &(matriz->matriz[1]);
    matriz->matriz[0].key = 0;

    int i = 1;

    for(i; i < quantidade - 2; i++){
        matriz->matriz[i].precedente = -1;
        matriz->matriz[i].estimativa = INT_MAX;
        matriz->matriz[i].fechado_aberto = true;
        //matriz->matriz[i].anterior = &(matriz->matriz[i+1]);
        //matriz->matriz[i].proximo = NULL;
        matriz->matriz[i].key = i;
    }

    i = quantidade -1;

    matriz->matriz[i].precedente = -1;
    matriz->matriz[i].estimativa = INT_MAX;
    matriz->matriz[i].fechado_aberto = true;
    //matriz->matriz[i].anterior = &(matriz->matriz[i-1]);
    //matriz->matriz[i].proximo = NULL;
    matriz->matriz[i].key = i;
}//inicializaMatrizAuxiliar

void inicializaGrafo(GrafoMatriz *grafo, TabelaHash th, int qtdElem){
    grafo->matriz=(int**) malloc(grafo->vertices*sizeof(int*));
    for(int i=0; i<grafo->vertices; i++){
         grafo->matriz[i]= (int*) malloc(grafo->vertices*sizeof(int));
    }
}

void destroiGrafo(GrafoMatriz *grafo){
    for(int i=0; i<grafo->vertices; i++){
        free(grafo->matriz[i]);
    }

    free(grafo->matriz);
    free(grafo->clientes);
    free(grafo);
}

void visita(GrafoMatriz *grafo, int *status, char *arv, int vi){
    status[vi]=Visitado;
    
    for(int i=0; i<grafo->vertices; i++){
        if(grafo->matriz[vi][i]>0){
            if(status[i]==NaoVisitado){
                sprintf(arv,"%s (%d - %d)\n",arv, vi, i);
                visita(grafo, status, arv, i);
            }
        }
    }
    status[vi]=NoFinal;
}

int main(){
    GrafoMatriz grafo;
    TabelaHash tabelaHash;
    MatrizAuxiliar matrizAux;

    int pessoa1 = 0;
    int pessoa2 = 1;

    manipulaArquivo(&grafo);

    int qtdVertices = grafo.vertices;

    inicializaTabelaHash(&tabelaHash,qtdVertices);
    inicializaGrafo(&grafo, tabelaHash, tabelaHash.qtdElem); 

    double distancia = calcularDistancia(grafo.clientes[pessoa1].coordenadaX, grafo.clientes[pessoa1].coordenadaY, grafo.clientes[pessoa2].coordenadaX, grafo.clientes[pessoa2].coordenadaY); 

    destroiGrafo(&grafo);

    return EXIT_SUCCESS;
}