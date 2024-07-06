/**
 * @file aula14ex2.c
 * @author Marcos Tadao Shoji (shoji@alunos.utfpr.edu.br)
 * @brief 
 * @version 0.1
 * @date 2022-03-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/*
2) Elabore uma função que receba por parâmetro o sexo (caractere) e a
altura de uma pessoa (real), calcule e retorne seu peso ideal. Para isso,
utilize as fórmulas a seguir.
 Para homens: (72.7 * altura) - 58
 Para mulheres: (62.1 * altura) - 44.7
*/

#include<stdio.h>
#include<stdlib.h>

void esclarecimentos();//cabeçalho
float peso_ideal(float altura, char genero);//cabeçalho

int main(){

    float recebe_altura;
    char recebe_genero;
    float recebe_peso_ideal;

    esclarecimentos();
    printf("Informe sua altura:\n\n");
    scanf("%f", &recebe_altura);
    setbuf(stdin,NULL);
    printf("\nInforme o seu genero:\n\n");
    scanf("%c", &recebe_genero);
    setbuf(stdin,NULL);

    recebe_peso_ideal = peso_ideal(recebe_altura, recebe_genero);

    printf("\nO peso ideal do usuario vale: %.2f\n", recebe_peso_ideal);

return 0;
}//main

float peso_ideal(float altura, char genero){

    float peso_ideal_usuario;

    switch (genero){

        case 'm':

            peso_ideal_usuario = ((72.7 * altura) - 58);
            break;

        case 'M':

            peso_ideal_usuario = ((72.7 * altura) - 58);
            break;

        case 'f':

            peso_ideal_usuario = ((62.1 * altura) - 44.7);
            break;

        case 'F':

            peso_ideal_usuario = ((62.1 * altura) - 44.7);
            break;

        default:

            printf("\nValor incorreto.\n\n");
            break;

    }//switch por genero

return peso_ideal_usuario;
}//peso ideal

void esclarecimentos(){

    printf("Este programa recebera a altura e o genero do usuario.\n\n");
    printf("Sera exibido o peso ideal do usuario.\n\n");
    printf("Para altura:\n\n");
    printf("Use numeros reais positivos.\n\n");
    printf("Para separacao decimal use (.).\n\n");
    printf("Para o genero:\n\n");
    printf("Digite (f) para feminino e (m) para masculino.\n\n");

return;
}//esclarecimentos
