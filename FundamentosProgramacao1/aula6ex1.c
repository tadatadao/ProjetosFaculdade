/*
1) Faça um programa que receba como entrada a nota de
um aluno. O programa deve exibir “aprovado” caso a nota
seja igual ou superior a 6, ou exibir “reprovado” caso
contrário.
*/
#include <stdio.h>
#include <stdlib.h>

int main() {

    double nota;

    printf("Ola professor bem vindo ao sistema da UTFPR.\n\n");
    printf("Vamos consumir nosso elixir da vida?\n\n");
    printf("Sim, lagrimas de alunos! Delicia!\n\n");
    printf("Vamos determina:r\n\n");
    printf("Se com a nota inserida o aluno foi aprovado ou reprovado.\n\n");
    printf("Insira a nota do aluno (lembre-se de usar (.) como quebra decimal):\n\n");
    scanf("%lf", &nota);

    if (nota < 6) {
        printf("\nYes!! Reprovado, que nos de muito elixir da vida!\n");
    }//if
    else if (nota >= 6) {
        printf("\nFoi Aprovado... mantenha a calma ainda vamos pegar ele.\n");
    }//else
/*
É só uma brincadeira!
Isso não reflete minha opinião pessoal.
*/
return 0;
}//main
