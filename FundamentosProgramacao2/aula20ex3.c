/**
 * @file aula20ex3.c
 * @author Marcos Tadao Shoji (shoji@alunos.utfpr.edu.br)
 * @brief 3)Escreva uma função que receba como parâmetro dois vetores via referência( A e B)
            e o tamanho N. A função deve retornar o ponteiro para um vetor C de tamanho N
            alocado dinamicamente, em que:
            C[i] = A[i] * B[i]
 * @version 0.1
 * @date 2022-05-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<stdio.h>
#include<stdlib.h>

void instrucoes(){

    printf("Este programa recebera um tamanho de vetor com valor inteiro positivo.\n\n");
    printf("O tamanho velera tanto para o vetor 1 quanto para vetor 2.\n\n");
    printf("O usuario devera preencher os vetore 1 e 2 com qualquer numero inteiro");
    printf("Por fim o programa ira montar um vetor c pela multiplicação dos vetores 1 e 2.\n\n");

return;
}//intrucoes

int* alocacao_vetor(int vetor_A[], int vetor_B[], int tamanhoN){

    int* vetor_C = (int*) malloc(tamanhoN * sizeof(int));

    for(int linha = 0; linha < tamanhoN; linha++){

        vetor_C[linha] = vetor_A[linha] * vetor_B[linha];

    }//for linha

return vetor_C;
}//alocacao de vetor

int main(){

    int tamanhoN;
    int* vetor_C;

   instrucoes();

    printf("Digite o tamanho do vetor: ");
    scanf("%i",&tamanhoN);
    setbuf(stdin,NULL);

    int vetor_A[tamanhoN];
    int vetor_B[tamanhoN];

    printf("\nPara o vetor A:\n");

    for(int linha = 0; linha < tamanhoN; linha++){

        printf("\nDigite o valor para posicao [%i]: ",linha);
        scanf("%i",&vetor_A[linha]);
        setbuf(stdin,NULL);

    }//for linha

    printf("\nPara o vetor B:\n");

    for(int linha = 0; linha < tamanhoN; linha++){

        printf("\nDigite o valor para posicao [%i]: ",linha);
        scanf("%i",&vetor_B[linha]);
        setbuf(stdin,NULL);

    }//for linha

    vetor_C = alocacao_vetor(vetor_A, vetor_B, tamanhoN);

    printf("\nPara o vetor C:\n");

    for(int linha = 0; linha < tamanhoN; linha++){

        printf("\nA posicao [%i]: tem valor %i\n", linha, vetor_C[linha]);

    }//for linha

    free(vetor_C);

return 0;
}//main