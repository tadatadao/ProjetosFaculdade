/*
2) Fazer um programa para ler as coordenadas x e y de dois pontos
e calcular a distância entre os dois pontos no plano, através da seguinte fórmula:

d=√(x2−x1)2+(y2−y1)2
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    double coordenada_x1;
    double coordenada_y1;
    double coordenada_x2;
    double coordenada_y2;
    double distancia_entre_pontos;

    printf("Vamos calcular a distancia entre dois pontos no plano cartesiano?\n\n");
    printf("Insira o x do primeiro ponto:\n\n");
    scanf("%lf", &coordenada_x1);
    printf("\nInsira o y do primeiro ponto:\n\n");
    scanf("%lf", &coordenada_y1);
    printf("\nInsira o x do segundo ponto:\n\n");
    scanf("%lf", &coordenada_x2);
    printf("\nInsira o y do segundo ponto:\n\n");
    scanf("%lf", &coordenada_y2);

    distancia_entre_pontos = sqrt(pow(coordenada_x2 - coordenada_x1,2) + pow(coordenada_y2 - coordenada_y1,2));

    printf("\nA distancia ente os pontos e: %lf\n\n", distancia_entre_pontos);

return 0;
}
