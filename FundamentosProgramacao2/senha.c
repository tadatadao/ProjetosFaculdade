#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int main(){

   char senha_aleatoria[200][6];

   srand((unsigned)time(NULL));

   for(int l = 0; l < 200; l++){

      for(int i = 0; i < 6; i++){

         senha_aleatoria[l][i] = 'a' + (char)(rand() % 26);

      }

   }

   FILE *arquivo = fopen("senha.txt", "w");

   for(int l = 0; l < 200; l++){

      for(int i = 0; i < 6; i++){

         fputc(senha_aleatoria[l][i], arquivo);

      }

      fputc('\n', arquivo);

   }

   fclose(arquivo);

return 0;
}