//@Marcos Tadao Shoji @2374200 @aula10ex8
/*
8) Utilizando a estrutura do laço for aninhado, crie um
programa que exiba a tabuada de todos os números de
1 a 10 no seguinte formato:
*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    int tabuada_do;
    int multiplicador;
    int valor_produto;

    printf("Este programa mostrara a tabuada de 1 a 10.\n");

    for(tabuada_do = 1; tabuada_do <= 10; tabuada_do++){

        for(multiplicador = 1; multiplicador <= 10; multiplicador++){

            if(multiplicador == 1){

                printf("\nTabuada do %i\n", tabuada_do);

            }//if multiplicador = 1

            valor_produto = tabuada_do * multiplicador;

            printf("%i X %i = %i\n", tabuada_do, multiplicador, valor_produto);

        }//for multiplicador n x m

    }//for tabuada do n

return 0;
}//main
