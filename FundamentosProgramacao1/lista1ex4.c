/*
3) Faça um programa que tenha como entrada:
o número de horas, minutos e segundos atuais,
informe quantos segundos faltam para chegar terminar o dia.
*/
#include <stdio.h>
#include <stdlib.h>

int main() {

    int hora;
    int minuto;
    int segundo;
    int conversao_hora_segundo;
    int conversao_minuto_segundo;
    int segundos_totais;
    int segundos_em_um_dia = 86400;
    int quanto_falta;

    printf("Vamos descobrir quantos segundos faltam para terminar o dia.\n\n");
    printf("Informe as horas atuais:\n\n");
    scanf("%i", &hora);
    printf("\nInforme os minutos atuais:\n\n");
    scanf("%i", &minuto);
    printf("\nInforme os segundos atuais:\n\n");
    scanf("%i", &segundo);

    conversao_hora_segundo = hora * 3600;
    conversao_minuto_segundo = minuto * 60;
    segundos_totais = segundo + conversao_hora_segundo + conversao_minuto_segundo;
    quanto_falta = segundos_em_um_dia - segundos_totais;

    printf("\nFaltam %i segundos para terminar o dia.\n", quanto_falta);

return 0;
}
