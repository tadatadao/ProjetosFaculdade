/**
 * @file aula17ex2.c
 * @author Marcos Tadao Shoji (shoji@alunos.utfpr.edu.br)
 * @brief 
 * @version 0.1
 * @date 2022-03-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/*
2) Reescreva o exercício anterior utilizando a estrutura horário
(contendo hora, minuto e segundo) e passando a estrutura por
referência. Utilize o seguinte protótipo da função:
void converteHorario(int total_segundos, Horario* hor)
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct{

    int hora, min, seg;

}Horario;

 void instrucoes(){

    printf("Este programa recebrera do usuario uma quantidade inteira e nao negativa de segundos.\n\n");
    printf("A seguir o programa ira exibir a conversao dos segundos no formato hora : min : seg.\n\n");

 return;
 }//instrucoes

 void converteHorario(int total_segundos, Horario* hor){

    int resto_hora, resto_minuto;

    hor->hora = total_segundos / 3600;//converte segundos em hora
    resto_hora = total_segundos % 3600;//salva o resto da divisao
    hor->min = resto_hora / 60;//minutos e o resto da hora
    resto_minuto = resto_hora % 60;//salva o resto da divisao
    hor->seg = resto_minuto;//segundos e o resto do minuto

 return;
 }//converteHorario

 int main(){

    Horario hora;
    
    int total_segundos;

    instrucoes();

    printf("Insira a quantidade de segundos a ser convertida:\n\n");
    scanf("%i", &total_segundos);
    setbuf(stdin,NULL);

    converteHorario(total_segundos, &hora);

    printf("\nA conversao de horario fica: %i : %i : %i\n", hora.hora, hora.min, hora.seg);
    
 return 0;
 }//main
