/**
 * @file aual1ex2.c
 * @author Marcos Tadao Shoji (shoji@alunos.utfpr.edu.br)
 * @brief 
 * @version 0.1
 * @date 2022-03-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */
/*
2) Escreva um trecho de código para fazer a criação dos
novos tipos de dados conforme solicitado abaixo:
 Horário: composto de hora, minutos e segundos.
 Data: composto de dia, mês e ano.
 Compromisso: local, horário e texto que descreve o
compromisso.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{

    int hora;
    int minuto;
    int segundos;

}Horario;

typedef struct{

    int dia;
    int mes;
    int ano;

}Data;

typedef struct{

    char local[50];
    int hora, minuto, segundo;
    char descricao[200];

}Compromisso;

void instrucao(){

    printf("Ola neste programa vamos ajudar voce a programar seus compromissos.\n\\n");
    printf("Voce precisara informar o atual horario, a data atual e os detalhes do compromisso.\n\n");

}

void A(){

    Horario horario;
    printf("Insira a hora atual:\n\n");
    scanf("%i",&horario.hora);
    setbuf(stdin,NULL);
    printf("\nInsira os minutos atuais:\n\n");
    scanf("%i",&horario.minuto);
    setbuf(stdin,NULL);
    printf("\nInsira os segundos atuais:\n\n");
    scanf("%i",&horario.segundos);
    setbuf(stdin,NULL);
    printf("\nO horario atual e %i horas %i minutos %i segundos\n\n", horario.hora, horario.minuto, horario.segundos);

}

void B(){

    Data data;
    printf("Insira o dia atual:\n\n");
    scanf("%i",&data.dia);
    setbuf(stdin,NULL);
    printf("\nInsira o mes atual com valor numerico:\n\n");
    scanf("%i",&data.mes);
    setbuf(stdin,NULL);
    printf("\nInsira o ano atual:\n\n");
    scanf("%i",&data.ano);
    setbuf(stdin,NULL);
    printf("\nA data atual e %i/%i/%i\n\n", data.dia, data.mes, data.ano);

}

void C(){

    Compromisso compromisso;
    printf("Informe o local do compromisso:\n\n");
    fgets(compromisso.local, 49, stdin);
    compromisso.local[strcspn(compromisso.local, "\n")] = '\0';
    setbuf(stdin,NULL);
    printf("\nInforme o horario do compromisso no formato hora:minuto:segundo, use valores numericos.\n\n");
    scanf("%i:%i:%i",&compromisso.hora,&compromisso.minuto,&compromisso.segundo);
    setbuf(stdin,NULL);
    printf("\nDescreva brevemente o compromisso marcado:\n\n");
    fgets(compromisso.descricao, 199, stdin);
    compromisso.descricao[strcspn(compromisso.descricao, "\n")] = '\0';
    printf("\nO local e %s, no horario %i:%i:%i, com descricao %s\n\n", compromisso.local, compromisso.hora, compromisso.minuto, compromisso.segundo, compromisso.descricao);

}

int main(){

    instrucao();
    A();
    B();
    C();

return 0;
}
