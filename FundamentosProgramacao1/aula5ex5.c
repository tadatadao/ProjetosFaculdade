/*
5) Sabendo que a função sqrt(valor), que está na biblioteca
math.h retorna a raiz quadrada do valor, calcule a raiz
quadrada de um número que o usuário digitar.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    double valor;
    double raiz_valor;

    printf("Este programa pode calcular raizes quadradas.\n\n");
    printf("Informe o valor numerico para o calculo da raiz quadrada.\n\n");
    printf("Lembre-se de usar (.) para quebra decimal\n");
    scanf("%lf", &valor);
    /*
    Para evitar um erro caso seja colocado um valor negativo
    na variável valor foi utilizado situação if/eslse.
    */
    if (valor < 0) {
        printf("\nSem raiz de valor negativo por favor\n");
    }//if

    else if(valor >= 0) {
            raiz_valor = sqrt(valor);//sqrt é a função de raiz quadrada
            printf("\nA raiz quadrada do valor informado e: %lf\n", raiz_valor);
    }//else


return 0;
}//main
