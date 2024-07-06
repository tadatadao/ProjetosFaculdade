//@Marcos Tadao Shoji @aula8ex3
/*
3) Crie um algoritmo que exiba todos os números múltiplos
de 3 no intervalo de 1 a 322.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    int contador = 1;

    while (contador <= 322) {

        if (contador % 3 == 0) {

            printf("%i\n", contador);

        }//if

        contador++;

    }//while

    printf("\nNo intervalo de 1 a 322.\n\n");
    printf("Estes sao os multiplos de 3.\n");

return 0;
}//main
