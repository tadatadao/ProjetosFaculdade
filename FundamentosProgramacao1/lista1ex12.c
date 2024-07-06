/*
12) Técnicos analisam a perda da massa do Xenônio-135
e descobriram que o tempo de meia vida desse radioisótopo é de 9h.
Crie um algoritmo para
receber a massa inicial em gramas e retorne o tempo necessário para que a massa deste material seja menor que 1 grama.
Caso o tempo exceda 24h a resposta deve ser dada em dias (Ex.: 2 dias e 6 horas).
Obs.: O algoritmo deve calcular o tempo para várias massas, finalizando ao receber uma massa igual a zero ou negativa.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    float massa_xenonio;
    int contador;
    int tempo;
    int dias;
    int horas;
    int loop = 0;

    printf("Este programa determinara quando o Xenonio-135 tera menos de 1g.\n\n");
    printf("Sera usado o decaimento meia vida de radioisotopo.\n\n");
    printf("A meia vida do Xenonio-135 e de 9h.\n\n");
    printf("O usuario deve inserir a massa inicial em gramas.\n\n");
    printf("Para usar quebra decimal use (.).\n\n");
    printf("O pograma recebera quantas massas iniciais o usuario desejar.\n\n");
    printf("Para enecerrar o programa insira um valor de massa inicial menor ou igual a zero.\n");

    do{

        contador = 0;

        printf("\nInsira a massa inicial do Xenonio-135:\n\n");

        scanf("%f", &massa_xenonio);

        if(massa_xenonio <= 0){

            printf("\nFinalizando programa.\n");
            break;

        }//if finalizar programa

        else if(massa_xenonio > 0 && massa_xenonio < 1){

            printf("\nValor menor que 1g.\n\n");
            printf("Fora do intervalo de calculo.\n");
            break;

        }//else sem meia vida

        else if(massa_xenonio >= 1) {

            while(massa_xenonio >= 1){

                massa_xenonio = (massa_xenonio / 2);

                printf("\n%.2fg\n", massa_xenonio);

                contador++;

            }//while meia vida

            tempo = contador * 9;

            if(tempo < 24){

                printf("\nO tempo decorrido para que o Xenonio-135 tenha menos de 1g foi:\n\n");
                printf("%i horas\n", tempo);

            }//tempo em horas

            else if(tempo >= 24){

                dias = tempo / 24;
                horas = tempo - (dias * 24);

                printf("\nO tempo decorrido para que o Xenonio-135 tenha menos de 1g foi:\n\n");
                printf("%i dias e %i horas\n", dias, horas);

            }//else tempo em horas

        }//else meia vida

    }while(loop >= 0);//do while

}//main
