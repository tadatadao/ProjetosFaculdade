/**
 * @file aula17ex1
 * @author Marcos Tadao Shoji (shoji@alunos.utfpr.edu.br)
 * @brief
 * @version 0.1
 * @date 2022-03-25
 *
 * @copyright Copyright (c) 2022
 *
 */

 /*
 1)Escreva um programa que receba um número inteiro representando a quantidade a quantidade total de segundos e usando passagem de parâmetros por referência, converta a quantidade informadade segundos
 em horas, minutos e segundos. Imprima o resultado da conversão no formato HH:MM:SS. Utilize o seguinte protótipo da função:
 void converteHora(int total_segundos, int* hora, int* min, int* seg)
 */

 #include<stdio.h>
 #include<stdlib.h>

 void instrucoes(){

    printf("Este programa recebrera do usuario uma quantidade inteira e nao negativa de segundos.\n\n");
    printf("A seguir o programa ira exibir a conversao dos segundos no formato hora : min : seg.\n\n");

 return;
 }//instrucoes

 void converteHora(int total_segundos, int* hora, int* min, int* seg){

    int resto_hora;
    int resto_minuto;

    *hora = total_segundos / 3600;//converte segundos em hora
    resto_hora = total_segundos % 3600;//salva o resto da divisao
    *min = resto_hora / 60;//minutos e o resto da hora
    resto_minuto = resto_hora % 60;//salva o resto da divisao
    *seg = resto_minuto;//segundos e o resto do minuto

 return;
 }//converteHora

 int main(){

    int total_segundos, hora, min, seg;

    instrucoes();

    printf("Insira a quantidade de segundos a ser convertida:\n\n");
    scanf("%i", &total_segundos);
    setbuf(stdin,NULL);

    converteHora(total_segundos, &hora, &min, &seg);

    printf("\nA conversao fica : %i : %i : %i\n", hora, min, seg);

 return 0;
 }//main
