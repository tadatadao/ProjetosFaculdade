//@Marcos Tadao Shoji @2374200 @aula13ex2
/*
2) Faça um programa que armazene o nome e salário de 5
empregados. Em seguida calcule um aumento de 8% nos
salários e exiba a nova folha de pagamentos.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char nomes[5][25];
    float salario[5][1];
    int linha;

    printf("Este programa recebera nomes de 5 funcionarios(as) e seus respectivos salarios.\n\n");
    printf("Sera calculado um aumento de 8 por cento no salario de cada funcionario(a).\n\n");
    printf("O programa possui um limite de 24 entradas de caracteres.\n\n");
    printf("Os espacos contam como um caractere cada.\n\n");
    printf("Ao inserir o salario use valores reais.\n\n");
    printf("Para separacao decimal use (.).\n\n");
    printf("Agora preencha abaixo:\n");

    for(linha = 0; linha < 5; linha++){

        printf("\nO nome do(a) funcionario(a):\n\n");
        fgets(nomes[linha], 25, stdin);
        nomes[linha][strcspn(nomes[linha], "\n")] = '\0';
        setbuf(stdin, NULL);
        printf("\nO salario do(a) funcionario(a):\n\n");
        scanf("%f", &salario[linha][1]);
        setbuf(stdin, NULL);

    }//for preenchimento de dados

    for(linha = 0; linha < 5; linha++){

        salario[linha][1] = 1.08 * salario[linha][1];

    }//for aumento de oito por cento

    printf("\nOs novos salarios de cada funcionario(a) sera:\n");

    for(linha = 0; linha < 5; linha++){

        printf("\nFuncionario(a): %s\n", nomes[linha]);
        printf("Salario: %.2f\n\n\n", salario[linha][1]);

    }//for imprime novos salarios

return 0;
}//main
