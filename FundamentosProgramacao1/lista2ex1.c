/*
1) Crie um algoritmo que imprima uma tabela de conversão de polegadas para centímetros.
Deseja-se que na tabela conste valores de 1 polegada até 20 polegadas inteiras.
(Para isso considere: 1 polegada = 2,54 cm)
*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    int polegada[20];
    float centimetro[20];
    int linha;
    int linha_1;

    polegada[0] = 1;

    for(linha = 0, linha_1 = 1; linha_1 < 20; linha++, linha_1++){

        polegada[linha_1] = polegada[linha] + 1;

    }//for valida polegada

    for(linha = 0; linha < 20; linha++){

        centimetro[linha] = polegada[linha] * 2.54;

    }//for converte para centimetro

    for(linha = 0; linha < 20; linha++){

        printf("\n[%i] polegadas vale: %.2fcm\n", polegada[linha], centimetro[linha]);

    }//for imprime valores

return 0;
}//main
