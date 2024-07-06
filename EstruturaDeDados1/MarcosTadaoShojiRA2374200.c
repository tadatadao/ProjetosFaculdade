/*
A empresa Matrix precisa melhorar o sistema de
armazenamento de informacoes de seus funcionarios. MuriNeo, o gerente, entrou em contato contigo e
pediu para que voce seja o responsavel por desenvolver este novo sistema.
MuriNeo descreveu que as informacoes dos funcionarios estao armazenadas em um arquivo denominado
funcionarios.txt e que consta, na primeira linha, um numero que indica a quantidade de funcionarios.

Pediu para que se utilizasse estruturas de modo a representar as demais informacoes, conforme esquema-
tizadas abaixo:

i) CADASTRO: nome, endereco, salario, estado civil, idade, sexo;
ii) ENDERECO: rua, cidade, estado.
Continuou suas explicacoes mostrando que no arquivo funcionarios.txt, a partir da segunda linha, cada
linha contem os dados de um funcionario. As informacoes dos funcionarios estao dispostas como no
exemplo:
{Persephone Belluci; {Rua Revolutions,12 ; Apucarana; Parana} ; 3200; solteiro; 30; F}
Referente as respectivas informacoes:

{nome; {rua; cidade; estado} ; salario ; estado civil ; idade; sexo}
Exemplo de arquivo: encurtador.com.br/nqrMV

1

MuriNeo ainda esclareceu que seu sistema sera compartilhado com outras filiais da empresa que pos-
suem suas informacoes armazenadas de modo similar, ou seja, cada filial tem seu respectivo quadro de

funcionarios (e quantidade tambem!).
O programa devera:
• ordenar por salario (utilizando o algoritmo Heapsort), em ordem decrescente, imprimir em TELA
e em ARQUIVO.txt o nome o salario, a idade e o sexo do funcionario (nesta ordem).
Obs 1: Utilizar a main apenas para realizar as chamadas das funcoes e procedimentos dos itens listados
logo acima (ou seja, nao de implementar a main gigantesca).
Obs 2: Lembre-se de limpar a memoria antes de encerrar a execucao do programa (evitar memory leak).
Vocˆe precisa utilizar alocacao dinˆamica de memoria, certo?!
Obs 3: Utilizar passagem de parˆametros (argC e argV) para receber o nome do arquivo de entrada e de
saida.
*/

//bibliotecas
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//define para tamanho de vetores
#define MAX_LEN 2000//para a leitura de arquivo
#define MAX_LEN2 100//para os demais vetores

//struct de cadastros
typedef struct cadastro{

    char nome[100];
    char estadoCivil[20];
    int idade;
    char sexo;
    int salario;

}Cadastro;

//struct de endereco
typedef struct endereco{

    char rua[100];
    char cidade[100];
    char estado[50];

}Endereco;

//variavel global
int salvaNumFuncionarios;

//funcao que manipula o arquivo
void manipulaArquivo(Endereco **end, Cadastro **cad){

    char nomeArquivo[25];
    int qntdeAlocada;
    char aux[6]; // auxiliar para leitura da primira linha do arquivo
    char salvaConteudoArquivo[MAX_LEN];
    int i = 0; // contador para o while de leitura de arquivo
    char nome[MAX_LEN2], rua[MAX_LEN2], cidade[MAX_LEN2], estado[MAX_LEN2], estadoCivil[MAX_LEN2], sexo;
    int idade, salario;

    printf("Digite o nome do arquivo: ");
    fgets(nomeArquivo, 24, stdin);
    nomeArquivo[strcspn(nomeArquivo, "\n")] = '\0';
    setbuf(stdin, NULL);

    strcat(nomeArquivo, ".txt");

    // abre o arquivo digitado
    FILE *arquivo = fopen(nomeArquivo, "r+");

    // tratamento de erro para abertura de arquivo
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo\n");
        exit(1);
    }

    // Lê a primeira linha do arquivo
    fgets(aux, 6, arquivo);

    // Atoi transforma um numero tipo char em tipo int
    qntdeAlocada = atoi(aux);

    printf("\n%d\n", qntdeAlocada);

    // alocação dinâmica das structs com a quantidade de funcionarios
    *end = (Endereco*)malloc(qntdeAlocada * sizeof(Endereco));
    *cad = (Cadastro*)malloc(qntdeAlocada * sizeof(Cadastro));

      while(fgets(salvaConteudoArquivo, MAX_LEN, arquivo)){

        if (salvaConteudoArquivo[0] != '{') continue;

        // lê nome
        sscanf(salvaConteudoArquivo, "{%[^;]", nome);

        // lê endereço
        sscanf(salvaConteudoArquivo, "{%*[^{]{%[^;];%[^;];%[^}]", rua, cidade, estado);

        // lê salário, estado civil, idade e gênero
        sscanf(salvaConteudoArquivo, "{%*[^{]{%*[^{]{%*[^{]{%*[^{]{%*[^{]{%*[^{]{%d;%[^;];%d;%c}", &salario, estadoCivil, &idade, &sexo);

        // armazena os dados lidos nas structs de cadastro e endereço
        strcpy((*cad)[i].nome, nome);
        (*cad)[i].salario = salario;//infelizmente nao esta atribuindo *no debugador o ssscanf nao atribui valor a variavel
        strcpy((*cad)[i].estadoCivil, estadoCivil);//infelizmente nao esta atribuindo *no debugador o ssscanf nao atribui valor a variavel
        (*cad)[i].idade = idade;//infelizmente nao esta atribuindo *no debugador o ssscanf nao atribui valor a variavel
        (*cad)[i].sexo = sexo;//infelizmente nao esta atribuindo *no debugador o ssscanf nao atribui valor a variavel
        //tambem tentei usar o strtok mas piora pois a cidade e o estado tambem ficaram com erro
        strcpy((*end)[i].rua, rua);
        strcpy((*end)[i].cidade, cidade);
        strcpy((*end)[i].estado, estado);

        i++;

    }//le e salva

    salvaNumFuncionarios = i;

    fclose(arquivo);//fecha arquivo

}//abre arquivo

/*
Funcao heapify:

Recebe um vetor de cadastros, um tamanho de heap e um indice
Identifica qual e o maior elemento entre o no atual e seus filhos (se existirem)
Se o maior elemento nao for o no atual, faz a troca entre os dois e chama recursivamente heapify para o no trocado
*/

void heapify(Cadastro *cad, int tamanhoHeap, int indice) {
    int maior = indice;
    int esquerda = 2 * indice + 1;
    int direita = 2 * indice + 2;

    if (esquerda < tamanhoHeap && cad[esquerda].salario > cad[maior].salario)
        maior = esquerda;

    if (direita < tamanhoHeap && cad[direita].salario > cad[maior].salario)
        maior = direita;

    if (maior != indice) {
        Cadastro temp = cad[indice];
        cad[indice] = cad[maior];
        cad[maior] = temp;

        heapify(cad, tamanhoHeap, maior);
    }
}//nao foi possivel verificar a funcionalidade devido ao erro ao pegar os valores de salario, estado civil, idade e sexo, mas acho que funciona

/*
Função heapSort:

Recebe um vetor de cadastros e seu tamanho
Constroi o heap inicial chamando heapify para cada nó interno na ordem inversa
Ordena o vetor em ordem crescente fazendo a troca do primeiro com o último elemento, diminuindo o tamanho do heap e chamando heapify para o primeiro elemento
*/

void heapSort(Cadastro *cad, int tamanho) {
    for (int i = tamanho / 2 - 1; i >= 0; i--)
        heapify(cad, tamanho, i);

    for (int i = tamanho - 1; i > 0; i--) {
        Cadastro temp = cad[0];
        cad[0] = cad[i];
        cad[i] = temp;

        heapify(cad, i, 0);
    }
}//nao foi possivel verificar a funcionalidade devido ao erro ao pegar os valores de salario, estado civil, idade e sexo, mas acho que funciona

/*Função imprimeDadosOrdenados:

Recebe um vetor de cadastros e seu tamanho
Abre o arquivo "ARQUIVO.txt" em modo de escrita
Imprime na tela e no arquivo os dados dos cadastros ordenados por salário
Fecha o arquivo
*/

void imprimeDadosOrdenados(Cadastro *cad, int tamanho) {
    FILE *arquivo = fopen("ARQUIVO.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo\n");
        exit(1);
    }

    printf("Dados ordenados por salario:\n");
    fprintf(arquivo, "Dados ordenados por salario:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Nome: %s, Salario: %d, Idade: %d, Sexo: %c\n", cad[i].nome, cad[i].salario, cad[i].idade, cad[i].sexo);
        fprintf(arquivo, "%s %d %d %c\n", cad[i].nome, cad[i].salario, cad[i].idade, cad[i].sexo);
    }
    fclose(arquivo);
}//mostra tudo errado, mas acho que funcionaria se os valores estivessem corretos


int main(){

    Endereco *end = NULL;
    Cadastro *cad = NULL;
    salvaNumFuncionarios = 0;

    manipulaArquivo(&end, &cad);

    // testando a leitura
    /*for (int i = 0; i < salvaNumFuncionarios; i++){

        printf("Cadastro [%d]\n", i+1);
        printf("Nome: %s\n", cad[i].nome);
        printf("Rua: %s\n", end[i].rua);
        printf("Cidade: %s\n", end[i].cidade);
        printf("Estado: %s\n", end[i].estado);
        printf("Salario: %d\n", cad[i].salario);
        printf("Estado civil: %s\n", cad[i].estadoCivil);
        printf("Idade: %d\n", cad[i].idade);
        printf("Sexo: %c\n", cad[i].sexo);

    }*/

    heapSort(cad, salvaNumFuncionarios);

    imprimeDadosOrdenados(cad, salvaNumFuncionarios);

    free(end);//libera memoria alocada
    free(cad);//libera memoria alocada

    return 0;
}//main
