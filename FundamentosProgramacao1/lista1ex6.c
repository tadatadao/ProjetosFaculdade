/*
6) Um professor maluco da UTFPR avalia seus alunos da seguinte maneira:

3 provas (com peso 20 cada)
10 pontos para trabalhos menores durante o semestre
1 projeto de um jogo com peso 30

A média regular do aluno será dada pela soma das notas das 3 provas, nos projetos menores e do projeto do game.
O aluno que atingir a nota igual ou superior a 60 estará aprovado, caso contrário,
o aluno deverá realizar um exame onde a nota mínima necessária será dada pela fórmula:

NotaMinima = 120 – Média regular

O aluno aprovado via exame terá média final igual a 60 registrado no sistema.

Faça um programa que receba a nota das 3 provas, 1 nota dos projetos menores e 1 nota do projeto do game (todas as notas entre 0 e 100)
e informe se o aluno está aprovado ou terá que realizar o exame.
Em caso de exame o sistema deverá solicitar a nota do exame e informar se o aluno está aprovado ou reprovado e qual sua nota final (com uma casa decimal).
*/
#include <stdio.h>
#include <stdlib.h>

/*
Nota mínima do exame = 120 - média regular
É a mesma coisa que
Média regular + nota do exame / 2
*/

int main() {

    float prova1;
    float prova2;
    float prova3;
    float projetos_menores;
    float projeto_game;
    float media_final;
    float exame;
    float media_exame;

    printf("Ola docente da UTFPR!\n\n");
    printf("Vamos descobrir qual a situcao do aluno na disciplina.\n\n");
    printf("Informe abaixo em escala de zero a cem (usar (.) para quebra decimal):\n\n");
    printf("A nota da prova um:\n\n");
    scanf("%f", &prova1);
    printf("\nA nota da prova 2:\n\n");
    scanf("%f", &prova2);
    printf("\nAnota da prova 3:\n\n");
    scanf("%f", &prova3);
    printf("\nA media dos projetos menores:\n\n");
    scanf("%f", &projetos_menores);
    printf("\nA nota do projeto de game:\n\n");
    scanf("%f", &projeto_game);

    media_final = ((prova1 * 0.2) + (prova2 * 0.2) + (prova3 * 0.2) + (projetos_menores * 0.1) + (projeto_game * 0.3));

    if (media_final >= 60) {
        printf("\nOtimo o aluno foi aprovado.\n\n");
        printf("Sua media foi: %.1f\n", media_final);
    }//if aprovado

        else {
            printf("\nO aluno precisou de fazer o exame.\n\n");
            printf("Informe a nota do exame:\n\n");
            scanf("%f", &exame);

            media_exame = (media_final + exame) / 2;

                if (media_exame >= 60) {
                    printf("\nO aluno foi aprovado.\n\n");
                    printf("A media de todo aluno aprovado em exame e de 60.\n");
                }//if aprovado no exame

                    else {
                        printf("\nO aluno foi reprovado.\n\n");
                        printf("A media final do aluno foi: %.1f\n", media_exame);
                    }//else reprovado

        }//else exame

return 0;
}//main
