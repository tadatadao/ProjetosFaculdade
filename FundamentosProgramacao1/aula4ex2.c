/*
2) Uma conta de caderneta de poupança foi aberta com um
depósito de R$ 500,00. Imagine que esta conta é remunerada
em 1% de juros ao mês. Qual será o valor da conta após três
meses?
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
Para calcular juros compostos o montante é igual ao capital investido multiplicado
pela soma de um mais a taxa de juros inicial elevado ao tempo
*/

int main(){

    float capital;
    float taxa_de_juros;
    float tempo;
    float montante;
    capital = 500;
    taxa_de_juros = 0.01;
    tempo = 3;
    montante = capital * (pow(1 + taxa_de_juros, tempo));
    printf("Para sabermos o montante de um juros de taxa um por cento,\ncapital inicial de 500 reais em tres meses usamos a formula:\n");
    printf("montante = capital * (1 + taxa de juros) elevado ao tempo\n\n");
    printf("o resultado do montante vale %f reais\n",montante);

return 0;

}//main
