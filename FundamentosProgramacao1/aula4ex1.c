/*
1) Escreva um programa para determinar a quantidade de litros
de combustível gastos em uma viagem por um automóvel que
faz 12 km/litro. Para isso, sabe-se que o tempo gasto na viagem
é de 35 min e a velocidade média do automóvel é 80 km/h.
convertendo min para h o tempo é de 0.58h
*/

#include<stdio.h>
#include<stdlib.h>

int main(){

        /* para determinar distância percorrida
         multiplica-se a velocidade pelo tempo.
         */
         float velocidade;
         float tempo;
         float distancia;
         velocidade = 80;
         tempo = 0.58;
         distancia = velocidade * tempo;
         printf("Sabemos que a velocidade media vale 80km/h e que tempo foi de 0.58h\n\n");
         printf("Ao multiplicar a velocidade media pelo tempo obtemos a distancia %fkm\n\n",distancia);
         /* agora com a distancia basta fazermos uma proporção entre o consumo e a distancia
         12km=1l 35km=x x=35/12l*/
         float consumo_do_carro;
         float consumo_total;
         consumo_do_carro = 12;
         consumo_total = distancia / consumo_do_carro;
         printf("Sabemos que o a autonomia do automovel vale 12km/L\n\n");
         printf("Entao o consumo da viajem foi de %fL\n\n",consumo_total);


return 0;

}
