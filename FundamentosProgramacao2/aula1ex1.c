/**
 * @file aula1ex1.c
 * @author Marcos Tadao Shoji (shoji@alunos.utfpr.edu.br)
 * @brief 
 * @version 0.1
 * @date 2022-03-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */
/*
1) Crie uma estrutura para representar as coordenadas de
um ponto no plano (posições X e Y). Em seguida, declare
e leia do teclado dois pontos e exiba a distância entre
eles. 
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct Coordenadas{

    float coordenada_x1, coordenada_x2;
    float coordenada_y1, coordenada_y2;
    float distancia;    

};//typedef struct

int main(){

    struct Coordenadas plano;    

    printf("Este programa recebera dois pontos.\n\n");
    printf("Em seguida o programa calculara a distancia dos pontos.\n\n");
    printf("O usuario deve informar as coordenadas x e y de cada ponto.\n\n");
    printf("Para o primeiro ponto:\n\n");
    printf("Insira a coordenada x:\n\n");
    scanf("%f", &plano.coordenada_x1);
    setbuf(stdin,NULL);
    printf("\nInsira a coordenada y:\n\n");
    scanf("%f", &plano.coordenada_y1);
    setbuf(stdin,NULL);
    printf("\nPara o segundo ponto:\n\n");
    printf("Insira a coordenada x:\n\n");
    scanf("%f", &plano.coordenada_x2);
    setbuf(stdin,NULL);
    printf("\nInsira a coordenada y:\n\n");
    scanf("%f", &plano.coordenada_y2);
    setbuf(stdin,NULL);

    plano.distancia = sqrt(pow((plano.coordenada_x2 - plano.coordenada_x1),2) + pow((plano.coordenada_y2 - plano.coordenada_y1), 2));
    printf("\nA distancia entre os pontos e de: %f", plano.distancia);

return 0;
}//main