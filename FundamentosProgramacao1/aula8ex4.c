//@Marcos Tadao Shoji @aula8ex4
/*
4) Crie um algoritmo que exiba todos os números pares
entre 240 e 730 inclusive.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    int contador_par = 240;

    while (contador_par >= 240 && contador_par <= 720) {

        if(contador_par % 2 == 0) {

            printf("%i\n", contador_par);

        }//if

        contador_par++;

    }//while

    printf("\nNo intervalo de 240 a 720.\n\n");
    printf("Estes sao os numeros pares\n");

return 0;
}//main
