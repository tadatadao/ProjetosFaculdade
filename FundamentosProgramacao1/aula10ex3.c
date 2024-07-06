//@Marcos Tadao Shoji @RA:2374200 @aula10ex3
/*
3) Crie um algoritmo que exiba todos os números múltiplos
de 5 no intervalo de 1 a 500.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    int numero;

    printf("Este programa mostrara os multiplos de 5 no intervalo entre 1 e 500.\n\n");

    for(numero = 1; numero <= 500; numero++){

        if(numero % 5 == 0){

            printf("%i\n", numero);

        }//if multiplo de 5

    }//for numeros entre 1 e 500

return 0;
}//main
