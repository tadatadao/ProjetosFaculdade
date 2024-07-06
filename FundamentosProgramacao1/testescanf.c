#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char nome[15];
    char genero[15];
    char nome_rival[15];

    printf("Opa ola! Bem vindo ao mundo de pokemon!\n\n");
    printf("Eu me chamo Carvalho! As pessoas me chamam de professor pokemon!\n\n");
    printf("Esse mundo e habitado por criaturas que chamamos de pokemnon!\n\n");
    printf("Para alguns, pokemons sao como pets. Para outros, uma ferramenta de batalha.\n\n");
    printf("Eu...Bem eu estudo os pokemons como profissao.\n\n");
    printf("Estou meio ruim da vista, voce e menino ou menina?\n\n");
    scanf("%s", &genero);
    printf("\nHahaha, estava brincando com voce eu sei que voce e %s...\n\n", genero);
    printf("Agora, qual o seu nome?\n\n");
    scanf("%s", &nome);
    printf("\nCerto! Entao seu nome e %s!\n\n", nome);
    printf("Este e o meu neto. Ele e o seu rival desde que voce nasceu.\n\n");
    printf("...Ahh, qual era o nome dele mesmo?\n\n");
    scanf("%s", &nome_rival);
    printf("\nMas e claro que e %s, como se eu fosse esquecer o nome do meu neto...\n\n", nome_rival);
    printf("%s! Sua propria lenda pokemon esta prestes a ter inicio!\n\n", nome);
    printf("Um mundo inteiro de sonhos e aventuras junto de seu pokemon lhe aguardam!\n\n");
    printf("VAMOS LA!\n");


return 0;
}

