/**
 * @file aula20ex2.c
 * @author Marcos Tadao Shoji (shoji@alunos.utfpr.edu.br)
 * @brief 2)Escreva uma função que receba um valor inteiro positivo N por parâmetro e retorne
            o ponteiro para um vetor de tamanho N alocado dinamicamente. Se N for negativo ou
            igual a zero, um ponteiro nulo deverá ser retornado.
 * @version 0.1
 * @date 2022-05-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<stdio.h>
#include<stdlib.h>

void instrucoes(){

    printf("Este programa recebera do usuario um numero insteiro.\n\n");
    printf("Este numero determinara o tamanho de um vetor.\n\n");
    printf("Caso um tamanho 0 ou negativo seja inserido o usuario recebera um retorno nulo.\n\n");

return;
}//instrucoes

int* alocar_vetor(int inteiro){

    int *vetor_alocado;

    if(inteiro > 0){

        vetor_alocado = (int*) malloc(inteiro * sizeof(int));
        
        return vetor_alocado;

    }//if tamanho maior que 0

    else{

        vetor_alocado = NULL;

        return vetor_alocado;        

    }//else interio 0 ou negativo

}//ponteiro alocado

int main(){

    int inteiro;
    int* vetor_ponteiro;

    printf("Digite o numero: ");
    scanf("%i", &inteiro);
    setbuf(stdin,NULL);
    printf("\n");

    vetor_ponteiro = alocar_vetor(inteiro);

    if(vetor_ponteiro == NULL){

        printf("O tamanho informado foi negativo ou 0, o valor recebido foi nulo.\n");

    }//if nulo

    else{

        for(int linha = 0; linha < inteiro; linha++){

            printf("\nDigite um valor para posicao [%i]: ", linha);
            scanf("%i", &vetor_ponteiro[linha]);
            setbuf(stdin,NULL);

        }//for linha

        for(int linha = 0; linha < inteiro; linha++){

            printf("\nA posicao [%i]: tem valor %i\n", linha, vetor_ponteiro[linha]);

        }//for linha

    }//else vetor alocado

    free()

return 0;
}//main