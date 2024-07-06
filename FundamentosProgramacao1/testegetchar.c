#include <stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
int main()
{
   char ch;

   printf("Digite a \n");

   ch = getchar();

   if(ch == 'a')
   printf("\nO seu nome eh Fulano de Tal e seu e-mail eh talfulano@dominio.com", ch);

   else
   printf("\nEi voce digitou errado");


   return(0);
}
