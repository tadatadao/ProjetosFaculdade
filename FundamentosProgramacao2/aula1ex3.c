/**
 * @file aula1ex3.c
 * @author Marcos Tadao Shoji (shoji@alunos.utfpr.edu.br)
 * @brief 
 * @version 0.1
 * @date 2022-03-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
/*
3) Construa uma estrutura aluno com nome, curso e 4 notas,
média e situação. Leia as informações nome, curso e notas do
teclado, calcule a média e armazene a situação do aluno.
 media ≥ 7 → Aprovado;
 3 ≤ media < 7 → Exame;
 media < 3 → Reprovado;
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{

    char nome[30];
    char curso[30];
    float nota_1;
    float nota_2;
    float nota_3;
    float nota_4;
    float media;
    char situacao[20];

}Aluno;

void instrucoes(){

    printf("Este programa ajudara a calcular a media e a situacao do aluno.\n\n");
    printf("Com media 7 ou mais o aluno e aprovado.\n\n");
    printf("Com media 3 ou mais e inferior a 7 o aluno esta de exame.\n\n");
    printf("Com media inferior a 3 o aluno e reprovado.\n\n");
    printf("O programa recebera o nome do aluno, o curso e 4 notas.\n\n");
    printf("Nao use numeros negativos.\n\n");

}

void recebe_calcula_informa(){

    Aluno aluno;
    printf("Insira o nome do aluno:\n\n");
    fgets(aluno.nome, 29, stdin);
    aluno.nome[strcspn(aluno.nome, "\n")] = '\0';
    setbuf(stdin,NULL);
    printf("\nInsira o curso do aluno:\n\n");
    fgets(aluno.curso, 29, stdin);
    aluno.curso[strcspn(aluno.curso, "\n")] = '\0';
    setbuf(stdin,NULL);
    printf("\nInsira a nota 1 do aluno:\n\n");
    scanf("%f", &aluno.nota_1);
    setbuf(stdin,NULL);
    printf("\nInsira a nota 2 do aluno:\n\n");
    scanf("%f", &aluno.nota_2);
    setbuf(stdin,NULL);
    printf("\nInsira a nota 3 do aluno:\n\n");
    scanf("%f", &aluno.nota_3);
    setbuf(stdin,NULL);
    printf("\nInsira a nota 4 do aluno:\n\n");
    scanf("%f", &aluno.nota_4);
    setbuf(stdin,NULL);
    aluno.media = (aluno.nota_1 + aluno.nota_2 + aluno.nota_3 + aluno.nota_4) / 4;
    printf("\nA media foi de: %.2f\n\n", aluno.media);
    if(aluno.media < 3){

        aluno.situacao[20] = "reprovado";
        printf("O aluno esta %s.\n", aluno.situacao);

    }//if reprovado
    
    if(aluno.media >= 3 || aluno.media < 7){

        aluno.situacao[20] = "exame";
        printf("O aluno esta %s.\n", aluno.situacao);

    }//if exame

    if(aluno.media >= 7){

        aluno.situacao[20] = "aprovado";
        printf("O aluno esta %s.\n", aluno.situacao);

    }//if aprovado

}//void recebe_calcula_informa

int main(){

    instrucoes();
    recebe_calcula_informa();

return 0;
}//main
