//@Marcos Tadao Shoji @RA:2374200 @aula10ex4
/*
4) Crie um algoritmo que exiba todos os números pares
entre 240 e 730 inclusive.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    int numero;

    printf("Este programa mostrara os numeros pares entre 240 e 730.\n\n");

    for(numero = 240; numero <= 730; numero++){

        if(numero % 2 == 0){

            printf("%i\n", numero);

        }//if par

    }//for numeros entre 240 e 730

return 0;
}//main
