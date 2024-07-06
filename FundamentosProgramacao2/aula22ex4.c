/**
 * @file aula22ex4.txt
 * @author Marcos Tadao Shoji (shoji@alunos.utfpr.edu.br)
 * @brief 4)Considerando a estrutura atleta do exercício anterior, escreva
            um programa que leia um arquivo binário contendo os dados de
            cinco atletas. Calcule e exiba o nome do atleta mais alto e do
            mais velho.
 * @version 0.1
 * @date 2022-05-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<stdio.h>
#include<stdlib.h>

typedef struct{

    char nome[50];
    char esporte[50];
    int idade;
    float altura;

}Atleta;

int main(){

    Atleta atle[5];

    float salva_mais_alto;
    int salva_mais_velho;
    int salva_posicao_alto;
    int salva_posicao_velho;

    FILE *arquivo = fopen("a22e3.dat", "rb");

    if(arquivo == NULL){

       printf("\nOcorreu o  erro 1.\n\n");

    }//if erro

    fread(atle, sizeof(Atleta), 5, arquivo);

    salva_mais_alto = atle[0].altura;

    for(int tamanho = 1; tamanho < 5; tamanho++){

        if(atle[tamanho].altura > salva_mais_alto){

            salva_mais_alto = atle[tamanho].altura;
            salva_posicao_alto = tamanho;

        }//if filtra o mais alto e salva sua posicao dentro da struct

    }//for tamanho

    salva_mais_velho = atle[0].idade;

    for(int tamanho = 1; tamanho < 5; tamanho++){

        if(atle[tamanho].idade > salva_mais_velho){

            salva_mais_velho = atle[tamanho].idade;
            salva_posicao_velho = tamanho;

        }//if filtra o mais alto e salva sua posicao dentro da struct

    }//for tamanho

    printf("\nO atleta mais velho e o %s com %i anos\n\n", atle[salva_posicao_velho].nome, salva_mais_velho);
    printf("\nO atleta mais alto e o %s com %.2f metros\n\n", atle[salva_posicao_alto].nome, salva_mais_alto);

    fclose(arquivo);

return 0;
}//main
