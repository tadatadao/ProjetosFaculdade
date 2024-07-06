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
/*
 4) Faça um programa que controla o consumo de energia dos
eletrodomésticos de uma casa e:
 Crie e leia 5 eletrodomésticos que contém nome (máximo 15 letras),
potência (real, em kW) e tempo ativo por dia (real, em horas).
 Leia um tempo t (em dias), calcule e mostre o consumo total na casa e
o consumo relativo de cada eletrodoméstico (consumo/consumo total)
nesse período de tempo. Apresente este último dado em porcentagem.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    char eltrodomestico[5][15];
    float potencia[5];
    float tempo_ativo[5];
    int tempo_dias[5];
    float consumo_total;
    float consumo_relativo[5];

}Consumo;

void intrucoes(){

    printf("Este programa claculara o consumo parcial e total de 5 eletrodomesticos.\n\n");
    printf("O usuario deve informar:\n-O nome de cada eletrodomestico\n-A potencia de cada eletrodomesticos\n-O tempo em horas que ficam ativos\n-O tempo em dias que o usuario deseja calcular o consumo\n\n");
    printf("Nao use numeros negativos, use numeros reais menos para os dias que devem ser inteiros.\n\n");
    printf("A potencia deve ser informada em KW.\n\n");
    printf("Nao ultrapasse o limite de 15 caracteres para o eletrodomestico.\n");

}//void intrucoes

void recebe_calcula_informa(){

    Consumo consumo;
    int linha;

    for(linha = 0; linha < 5; linha++){

        printf("\nInforme o eletrodomestico %i:\n\n", linha+1);
        fgets(consumo.eltrodomestico[linha], 15, stdin);
        consumo.eltrodomestico[linha][strcspn(consumo.eltrodomestico[linha], "\n")] = '\0';
        setbuf(stdin,NULL);

    }//for linha

    for(linha = 0; linha < 5; linha++){

        printf("\nInforme a potencia do(a) %s:\n\n", consumo.eltrodomestico[linha]);
        scanf("%f", &consumo.potencia[linha]);
        setbuf(stdin,NULL);

    }//for linha

    for(linha = 0; linha < 5; linha++){

        printf("\nInforme o tempo de funcionamento em horas do(a) %s:\n\n", consumo.eltrodomestico[linha]);
        scanf("%f", &consumo.tempo_ativo[linha]);
        setbuf(stdin,NULL);

    }//for linha

    for(linha = 0; linha < 5; linha++){

        printf("\nInforme o tempo de funcionamento em dias do(a) %s:\n\n", consumo.eltrodomestico[linha]);
        scanf("%f", &consumo.tempo_dias[linha]);
        setbuf(stdin,NULL);

    }//for linha

    for(linha = 0; linha < 5; linha++){

        consumo.consumo_relativo[linha] = ((consumo.potencia[linha] * consumo.tempo_ativo[linha]) * consumo.tempo_dias[linha]);
        printf("\nO consumo do(a) %s e de %.2f KW.\n\n", consumo.eltrodomestico[linha], consumo.consumo_relativo[linha]);

    }//for linha

}//void recebe_calcula_informa

int main(){

    intrucoes();
    recebe_calcula_informa();

return 0;
}
