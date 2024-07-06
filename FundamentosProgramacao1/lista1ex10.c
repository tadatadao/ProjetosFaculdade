/*
10) Desenvolva um programa que receba um valor de 1 a 99 e exiba o valor por extenso
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    int numero;
    int dezena;
    int unidade;

    printf("Este programa lera um dado numero por extenso.\n\n");
    printf("O numero deve estar no intervalo de 1 a 99.\n\n");
    printf("O numero deve ser natural.\n\n");
    printf("Insira o numero:\n\n");
    scanf("%i", &numero);
    printf("\nPor extenso o numero e:\n\n");

    if(numero >= 10 && numero <= 99){

        dezena = numero / 10;
        unidade = numero % 10;

        if(dezena == 1){

            switch(unidade) {

            case 0:
                printf("Dez\n");
                break;

            case 1:
                printf("Onze\n");
                break;

            case 2:
                printf("Doze\n");
                break;

            case 3:
                printf("Treze\n");
                break;

            case 4:
                printf("Quatorze\n");
                break;

            case 5:
                printf("Quinze\n");

            case 6:
                printf("Dezesseis\n");
                break;

            case 7:
                printf("Dezessete\n");
                break;

            case 8:
                printf("Dezoito\n");
                break;

            case 9:
                printf("Dezenove\n");
                break;

            }//switch extenso

        }//if dez e

        if(dezena == 2){

            switch(unidade) {

            case 0:
                printf("Vinte\n");
                break;

            case 1:
                printf("Vinte e um\n");
                break;

            case 2:
                printf("Vinte e dois\n");
                break;

            case 3:
                printf("Vinte e tres\n");
                break;

            case 4:
                printf("Vinte e quatro\n");
                break;

            case 5:
                printf("Vinte e cinco\n");

            case 6:
                printf("Vinte e seis\n");
                break;

            case 7:
                printf("Vinte e sete\n");
                break;

            case 8:
                printf("Vinte e oito\n");
                break;

            case 9:
                printf("Vinte e nove\n");
                break;

            }//switch extenso

        }//if vinte e

        else if(dezena == 3){

            switch(unidade) {

            case 0:
                printf("Trinta\n");
                break;

            case 1:
                printf("Trinta e um\n");
                break;

            case 2:
                printf("Trinta e dois\n");
                break;

            case 3:
                printf("Trinta e tres\n");
                break;

            case 4:
                printf("Trinta e quatro\n");
                break;

            case 5:
                printf("Trinta e cinco\n");

            case 6:
                printf("Trinta e seis\n");
                break;

            case 7:
                printf("Trinta e sete\n");
                break;

            case 8:
                printf("Trinta e oito\n");
                break;

            case 9:
                printf("Trinta e nove\n");
                break;

            }//switch extenso

        }//if trinta e

        else if(dezena == 4){

            switch(unidade) {

            case 0:
                printf("Quarenta\n");
                break;

            case 1:
                printf("Quarenta e um\n");
                break;

            case 2:
                printf("Quarenta e dois\n");
                break;

            case 3:
                printf("Quarenta e tres\n");
                break;

            case 4:
                printf("Quarenta e quatro\n");
                break;

            case 5:
                printf("Quarenta e cinco\n");

            case 6:
                printf("Quarenta e sete\n");
                break;

            case 7:
                printf("Quarenta e seis\n");
                break;

            case 8:
                printf("Quarenta e oito\n");
                break;

            case 9:
                printf("Quarenta e nove\n");
                break;

            }//switch extenso

        }//if quarenta e

        if(dezena == 5){

            switch(unidade) {

            case 0:
                printf("Cinquenta\n");
                break;

            case 1:
                printf("Cinquenta e um\n");
                break;

            case 2:
                printf("Cinquenta e dois\n");
                break;

            case 3:
                printf("Vinte e tres\n");
                break;

            case 4:
                printf("Cinquenta e quatro\n");
                break;

            case 5:
                printf("Cinquenta e cinco\n");

            case 6:
                printf("Cinquenta e sete\n");
                break;

            case 7:
                printf("Cinquenta e seis\n");
                break;

            case 8:
                printf("Cinquenta e oito\n");
                break;

            case 9:
                printf("Cinquenta e nove\n");
                break;

            }//switch extenso

        }//if cinquenta e

        if(dezena == 6){

            switch(unidade) {

            case 0:
                printf("Sessenta\n");
                break;

            case 1:
                printf("Sessenta e um\n");
                break;

            case 2:
                printf("Sessenta e dois\n");
                break;

            case 3:
                printf("Vinte e tres\n");
                break;

            case 4:
                printf("Sessenta e quatro\n");
                break;

            case 5:
                printf("Sessenta e cinco\n");

            case 6:
                printf("Sessenta e seis\n");
                break;

            case 7:
                printf("Sessenta e sete\n");
                break;

            case 8:
                printf("Vinte e oito\n");
                break;

            case 9:
                printf("Sessenta e nove\n");
                break;

            }//switch extenso

        }//if sessenta e

        if(dezena == 7){

            switch(unidade) {

            case 0:
                printf("Setenta\n");
                break;

            case 1:
                printf("Setenta e um\n");
                break;

            case 2:
                printf("Setenta e dois\n");
                break;

            case 3:
                printf("Setenta e tres\n");
                break;

            case 4:
                printf("Setenta e quatro\n");
                break;

            case 5:
                printf("Setenta e cinco\n");

            case 6:
                printf("Setenta e seis\n");
                break;

            case 7:
                printf("Setenta e sete\n");
                break;

            case 8:
                printf("Setenta e oito\n");
                break;

            case 9:
                printf("Setenta e nove\n");
                break;

            }//switch extenso

        }//if setenta e

        if(dezena == 8){

            switch(unidade) {

            case 0:
                printf("Oitenta\n");
                break;

            case 1:
                printf("Oitenta e um\n");
                break;

            case 2:
                printf("Oitenta e dois\n");
                break;

            case 3:
                printf("Oitenta e tres\n");
                break;

            case 4:
                printf("Oitenta e quatro\n");
                break;

            case 5:
                printf("Oitenta e cinco\n");

            case 6:
                printf("Oitenta e sete\n");
                break;

            case 7:
                printf("Oitenta e seis\n");
                break;

            case 8:
                printf("Oitenta e oito\n");
                break;

            case 9:
                printf("Oitenta e nove\n");
                break;

            }//switch extenso

        }//if oitenta e

        if(dezena == 9){

            switch(unidade) {

            case 0:
                printf("Noventa\n");
                break;

            case 1:
                printf("Noventa e um\n");
                break;

            case 2:
                printf("Noventa e dois\n");
                break;

            case 3:
                printf("Noventa e tres\n");
                break;

            case 4:
                printf("Noventa e quatro\n");
                break;

            case 5:
                printf("Noventa e cinco\n");

            case 6:
                printf("Noventa e seis\n");
                break;

            case 7:
                printf("Noventa e sete\n");
                break;

            case 8:
                printf("Noventa e oito\n");
                break;

            case 9:
                printf("Noventa e nove\n");
                break;

            }//switch extenso

        }//if noventa e

    }//if numero nao unico

    else if(numero >= 1 && numero <10) {

        switch(numero) {

            case 1:
                printf("Um\n");
                break;

            case 2:
                printf("Dois\n");
                break;

            case 3:
                printf("Tres\n");
                break;

            case 4:
                printf("Quatro\n");
                break;

            case 5:
                printf("Cinco\n");

            case 6:
                printf("Seis\n");
                break;

            case 7:
                printf("Sete\n");
                break;

            case 8:
                printf("Oito\n");
                break;

            case 9:
                printf("Nove\n");
                break;

        }//switch de um a nove

    }//else if numero unitario

    else {

        printf("Numero invalido.\n");

    }//else numero invalido

return 0;
}//main
