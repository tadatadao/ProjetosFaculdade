#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct
{
   int id;
   char proprietario[50];
   char rua[50];
   int numeroCasa;
} ObjetoEstatico;

typedef struct obj
{
   struct obj *prox;
   int id;
   char proprietario[50];
   char rua[50];
   int numeroCasa;
} ObjetoDinamico;

typedef struct {
   ObjetoEstatico array[10];
   int inicio;
   int fim;
   int quantidade;
} filaEstatica;

typedef struct {
   ObjetoDinamico *topo;
   int quantidade;
} filaDinamica;

void inicializarEstatico(filaEstatica f) {
   f.fim=-1;
   f.inicio=-1;
   f.quantidade=0;
}

void inicializarDinamica(filaDinamica *f) {
   f->topo=NULL;
   f->quantidade=0;
}

void inicializarVisitas(filaEstatica *f) {
   FILE *fp = fopen("visitas.txt", "r");
   for (int i = 0; i < 10; i++)
   {
      fscanf(fp, "{ %i; %[^;]; %[^;]; %i }\n", &(f->array[i].id), f->array[i].proprietario, f->array[i].rua,&(f->array[i].numeroCasa));
   }
   //{ 123; João José da Silva; Rua Maraca; 58 }
   f->fim=0;
   f->inicio=9;
}

int main(int argc, char const *argv[])
{
   filaEstatica filaVisitas;
   int quantidadeCasasConcretizadas = 0;
   
   inicializarEstatico(filaVisitas);
   inicializarVisitas(&filaVisitas);

   while(quantidadeCasasConcretizadas < 10) {
      printf("Proxima casa a ser visita:\nId: %d\nProprietário: %s\nEndereço: %s %d\n\n", filaVisitas.array[(filaVisitas.fim + 1) % 10].id,filaVisitas.array[(filaVisitas.fim + 1) % 10].proprietario, filaVisitas.array[(filaVisitas.fim + 1) % 10].rua, filaVisitas.array[(filaVisitas.fim + 1) % 10].numeroCasa);
      quantidadeCasasConcretizadas++;
   }
   return 0;
}
