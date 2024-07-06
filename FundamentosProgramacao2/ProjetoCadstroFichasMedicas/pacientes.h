#ifndef PACIENTES_H
#define PACIENTES_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
   
   char nomes_pacientes[100];
   char enfermidades[100];
   int idades;
   int id;
   float alturas;
   float pesos;

}Pacientes;

void cadastra_paciente(Pacientes);//funcao que cadastra os dados dos pacientes

#endif