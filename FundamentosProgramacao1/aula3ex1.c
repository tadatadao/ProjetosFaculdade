#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
int main(){
char nome[40] = "Marcos Tadao Shoji";
char email[50] = "shoji@alunos.utfpr.edu.br";
char tecla;
printf("Ola Fulano eu sei que voce ja sabe mas aqui esta o meu nome e o meu email\n\n");
printf("Nome: %s\n",nome);
printf("e-mail: %s\n\n\n",email);
printf("Agora meu caro amigo Fulano por gentileza aperte a tecla a para que revelar seu nome e email\n");
tecla = getchar();
if(tecla == 'a')
    printf("\nNome: Fulano de Tal\ne-mail: talfulano@dominio.com\n\n", tecla);
else
     printf("\nEi voce digitou errado\n\n");
return 0;
}
