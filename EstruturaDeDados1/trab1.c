#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 100
#define MAX_RUA 100
#define MAX_CIDADE 50
#define MAX_ESTADO 20

typedef struct {
    char nome[MAX_NOME];
    float salario;
    char estado_civil[10];
    int idade;
    char genero;
} cadastro;

typedef struct {
    char rua[MAX_RUA];
    char cidade[MAX_CIDADE];
    char estado[MAX_ESTADO];
} endereco;

void ler_dados(cadastro* funcionarios, endereco* enderecos, int n) {
    for (int i = 0; i < n; i++) {
        char linha[200];
        fgets(linha, 200, stdin);
        sscanf(linha, "{%[^;]; {%[^;]; %[^;]; %[^}]}; %f; %[^;]; %d; %c}",
            funcionarios[i].nome,
            enderecos[i].rua,
            enderecos[i].cidade,
            enderecos[i].estado,
            &funcionarios[i].salario,
            funcionarios[i].estado_civil,
            &funcionarios[i].idade,
            &funcionarios[i].genero);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    getchar(); // Consumir o caractere de fim de linha

    cadastro* funcionarios = (cadastro*) malloc(n * sizeof(cadastro));
    endereco* enderecos = (endereco*) malloc(n * sizeof(endereco));

    ler_dados(funcionarios, enderecos, n);

    // Imprimir os dados lidos
    for (int i = 0; i < n; i++) {
        printf("Funcionario %d:\n", i + 1);
        printf("  Nome: %s\n", funcionarios[i].nome);
        printf("  Salario: %.2f\n", funcionarios[i].salario);
        printf("  Estado civil: %s\n", funcionarios[i].estado_civil);
        printf("  Idade: %d\n", funcionarios[i].idade);
        printf("  Genero: %c\n", funcionarios[i].genero);
        printf("  Endereco:\n");
        printf("    Rua: %s\n", enderecos[i].rua);
        printf("    Cidade: %s\n", enderecos[i].cidade);
        printf("    Estado: %s\n", enderecos[i].estado);
    }

    free(funcionarios);
    free(enderecos);

    return 0;
}
