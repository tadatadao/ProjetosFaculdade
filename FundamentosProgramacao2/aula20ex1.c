/**
 * @file aula20ex1.c
 * @author Marcos Tadao Shoji (shoji@alunos.utfpr.edu.br)
 * @brief 1)Elabore um programa que leia do usuário o tamanho de um vetor a ser lido. Em
            seguida, faça a alocação dinâmica desse vetor. Por fim, leia o vetor do usuário e o
            imprima.
 * @version 0.1
 * @date 2022-05-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<stdio.h>
#include<stdlib.h>

void instrucoes(){

    printf("Este programa recebera um numero inteiro e positivo do usuario.\n\n");
    printf("O numero sera o tamanho de um vetor.\n\n");
    printf("Em seguida o usuario deve preencher as posicoes do vetor.\n\n");
    printf("Podem ser usados qualquer numero inteiro.\n\n");

return;
}//instrucoes

int main(){

    int tamanho;
    int *ponteiro_vetor;

    instrucoes();

    printf("Digite o tamanho do vetor: ");
    scanf("%i", &tamanho);
    setbuf(stdin,NULL);
    printf("\n");

    ponteiro_vetor = (int*) malloc(tamanho * sizeof(int));

    for(int linha = 0; linha < tamanho; linha++){
        
        printf("Digite o numero para posicao [%i]: ", linha);
        scanf("%i", &ponteiro_vetor[linha]);
        setbuf(stdin,NULL);

    }//for linha

    for(int linha = 0; linha < tamanho; linha++){
        
        printf("\nPosicao[%i]: %i\n", linha, ponteiro_vetor[linha]);

    }//for linha

    free(ponteiro_vetor);

    printf("\n");    

return 0;
}//main