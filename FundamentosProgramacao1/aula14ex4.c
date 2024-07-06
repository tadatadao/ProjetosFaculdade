/**
 * @file aula16ex4.c
 * @author Marcos Tadao Shoji (shoji@alunos.utfpr.edu.br)
 * @brief 
 * @version 0.1
 * @date 2022-03-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/*
4) Fa�a uma fun��o que receba a m�dia final de um aluno
por par�metro e retorne o seu conceito, conforme a tabela
abaixo:
Nota     Conceito
[ 9 - 10] A
[ 7 � 9 [ B
[ 5 - 7 [ C
[ 0 � 5 [ D
*/

#include<stdio.h>
#include<stdlib.h>

char nota_conceitual(float media);//cabe�alho
void esclarecimentos();//cabe�alho

int main(){

    float recebe_media;
    char recebe_conceito;

    printf("Insira a media do aluno:\n\n");
    scanf("%f", &recebe_media);
    setbuf(stdin,NULL);

    recebe_conceito = nota_conceitual(recebe_media);

    printf("\nA nota conceitual do aluno foi: %c\n", recebe_conceito);

return 0;
}//main

char nota_conceitual(float media){

    char conceito;

    if(media <= 10 && media >= 9){

        conceito = 'A';

    }//if A

    else if(media < 9 && media >= 7){

        conceito = 'B';

    }//if B

    else if(media < 7 && media >= 5){

        conceito = 'C';

    }//if C

    else if(media < 5 && media >= 0){

        conceito = 'D';

    }//if D

return conceito;
}//nota_conceitual

void esclarecimentos(){

    printf("Este programa a media do usuario.\n\n");
    printf("Sera exibido a nota conceiutual do aluno.\n\n");
    printf("Dentro de uma media sera atribuido um conceito entre: A, B, C, e D.\n\n");
    printf("Para medias:\n\n");
    printf("Use numeros reais positivos.\n\n");
    printf("Para separacao decimal use (.).\n\n");

return;
}//esclarecimentos
