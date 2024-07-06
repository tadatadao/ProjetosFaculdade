/**
 * @aula16ex2
 * @Marcos Tadao Shoji (shoji@alunos.utfpr.edu.br)
 * @brief
 * @version 0.1
 * @date 2022-03-23
 *
 * @copyright Copyright (c) 2022
 *
 */

/*2)Elabora uma função que receba por parâmetro o sexo (caractere) e a altura de uma pessoa (real), calcule e retorne o seu peso ideal. Para isso, utilize as fórmulas a seguir.
-Para homens (72.7 * altura) - 58
-Para mulheres (62.1 * altura) - 44.7
*/

#include<stdio.h>
#include<stdlib.h>

void instrucoes();
float calcula(char genero, float altura);

int main(){

    char informa_genero;
    float informa_altura;
    float recebe_peso_ideal;

    instrucoes();
    printf("Informe o genero da pessoa com uma caractere\n-(f) para feminino\n-(m) para masculino\n\n");
    scanf("%c", &informa_genero);
    setbuf(stdin,NULL);
    printf("\nInforme a altura da pessoa:\n\n");
    scanf("%f", &informa_altura);
    setbuf(stdin,NULL);
    recebe_peso_ideal = calcula(informa_genero, informa_altura);
    printf("\nO peso ideal da pessoa e: %.2fKg\n", recebe_peso_ideal);

return 0;
}//main

void instrucoes(){

    printf("Este programa informara o peso ideal de uma pessoa.\n\n");
    printf("Para isso o usuario deve informar o genero e a altura da pessoa em numeros reais nao negativos.\n\n");
    printf("A altura deve ser informada em metros.\n\n");

return;
}//void instrucoes

float calcula(char genero, float altura){

    float peso_ideal;

    if(genero == 'f' || genero == 'F'){

        peso_ideal = (62.1 * altura) - 44.7;

    }//if feminino

    if(genero == 'm' || genero == 'M'){

        peso_ideal = (72.7 * altura) - 58;

    }//if masculino

return peso_ideal;
}//float calcula
