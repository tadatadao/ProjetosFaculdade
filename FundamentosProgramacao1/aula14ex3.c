/**
 * @file aula16ex3.c
 * @author Marcos Tadao Shoji (shoji@alunos.utfpr.edu.br)
 * @brief 
 * @version 0.1
 * @date 2022-03-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/*
 3) Escreva um procedimento que recebe por par�metro as 3 notas de um
aluno e uma letra. Se a letra for A, o procedimento calcula a m�dia
aritm�tica das notas do aluno, se for P, a sua m�dia ponderada (pesos: 5, 3
e 2) e se for S, a soma das notas. O valor calculado tamb�m deve ser
retornado e exibido na fun��o main.
*/

#include<stdio.h>
#include<stdlib.h>

float notas(float nota_1, float nota_2, float nota_3, char letra);//cabe�alho
void esclarecimentos();//cabe�alho

int main(){

    float recebe_nota_1;
    float recebe_nota_2;
    float recebe_nota_3;
    char recebe_tipo_media;
    float recebe_media;

    esclarecimentos();
    printf("Insira a nota 1:\n\n");
    scanf("%f", &recebe_nota_1);
    setbuf(stdin,NULL);
    printf("\nInsira a nota 2:\n\n");
    scanf("%f", &recebe_nota_2);
    setbuf(stdin,NULL);
    printf("\nInsira a nota 3:\n\n");
    scanf("%f", &recebe_nota_3);
    setbuf(stdin,NULL);
    printf("\nInsira o tipo de manipulacao:\n\n");
    scanf("%c", &recebe_tipo_media);
    setbuf(stdin,NULL);

    recebe_media = notas(recebe_nota_1, recebe_nota_2, recebe_nota_3, recebe_tipo_media);

    printf("\nO tipo de manipulacao vale: %.2f\n", recebe_media);

return 0;
}//main

float notas(float nota_1, float nota_2, float nota_3, char letra){

    float tipo_de_media;

    switch(letra){

        case 'a':

            tipo_de_media = ((nota_1 + nota_2 + nota_3)/3);
            break;

        case 'A':

            tipo_de_media = ((nota_1 + nota_2 + nota_3)/3);
            break;

        case 'p':

            tipo_de_media = (((5*nota_1)+(3*nota_2)+(2*nota_3))/10);
            break;

        case 'P':

            tipo_de_media = (((5*nota_1)+(3*nota_2)+(2*nota_3))/10);
            break;

        case 's':

            tipo_de_media = (nota_1+ nota_2+ nota_3);
            break;

        case 'S':

            tipo_de_media = (nota_1+ nota_2+ nota_3);
            break;

        default:

            printf("\nValor incorreto.\n\n");
            break;

    }//switch por letra

return tipo_de_media;
}//notas

void esclarecimentos(){

    printf("Este programa recebera 3 notas do usuario.\n\n");
    printf("Sera exibido:\n-a media ponderada\n-a media aritmetica\n-a soma das notas\n\n");
    printf("Para notas:\n\n");
    printf("Use numeros reais positivos.\n\n");
    printf("Para separacao decimal use (.).\n\n");
    printf("Para a manipulacao das notas:\n\n");
    printf("Digite:\n-(p) para media ponderada\n-(a) para media aritmetica\n-(s) para soma das notas\n\n");

return;
}//esclarecimentos
