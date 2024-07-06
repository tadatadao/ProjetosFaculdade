/*
9) Faça um programa que receba o dia, mês e ano de uma data
e informe se é uma data válida ou não
*/

#include <stdio.h>
#include <stdlib.h>

/*
Lembrando que fevereiro tem 28 ou 29 dias dependendo de ano bissexto
Anos bissextos são anos múltiplos e 4 e não múltiplos de 100 ou múltiplos de 400
Janeiro, Março, Maio, Julho, Agosto, Outubro e Dezembro tem 31 dias
Abril, Junho, Setembro e Novembro tem 30 dias.
*/

int main() {

    int dia;
    int mes;
    int ano;

    printf("Este programa identificara se determinada data e valida.\n\n");
    printf("Tome como base o calendario gregoriano.\n\n");
    printf("Ao inserir a data utilize o formato:\n\n");
    printf("Dia/Mes/Ano\n\n");
    printf("Exemplo:\n\n");
    printf("21/10/2021\n\n");
    printf("Para vinte e um de outubro de dois mil e vinte um.\n\n");
    printf("Nao use: numeros negativos, numeros irracionais, dia ou mes sendo zero.\n\n");
    printf("Agora digite a data:\n\n");
    scanf("%i/%i/%i", &dia, &mes, &ano);

    if (ano >= 0){

        if(mes >= 1 && mes <= 12){

            if((dia >= 1 && dia <= 31) && (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)){

                printf("\nData valida.\n");

            }//if mes com 31 dias

            else if((dia >= 1 && dia <= 30) && (mes == 4 || mes == 6 || mes == 9 || mes == 11)){

                printf("\nData valida.\n");

            }//else if mes com 30 dias

            else if((dia >= 1 && dia <= 28) && (mes == 2)){

                printf("\nData valida.\n");

            }//else if fevereiro com 28 dias

            else if((dia >= 1 && dia <= 29) && (mes == 2) && ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0))){

                printf("\nData valida.\n");

            }//else if fevereiro com 29 dias

            else {

                printf("\nDia invalido.\n");

            }//else dia invalido

        }//if mes valido

        else{

            printf("\nMes invalido.\n");

        }//else mes invalido

    }//if ano valido

    else{

        printf("\nAno invalido.\n");

    }//else ano invalido

return 0;
}//main
