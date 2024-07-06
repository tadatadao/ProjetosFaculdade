/**
 * @file aula17ex3
 * @author Marcos Tadao Shoji (shoji@alunos.utfpr.edu.br)
 * @brief
 * @version 0.1
 * @date 2022-03-25
 *
 * @copyright Copyright (c) 2022
 *
 */

/*
 3) Crie um Sistema de Gerenciamento de Bandas seguindo os seguintes
passos:
 a) Defina uma estrutura que irá representar bandas de música. Essa estrutura deve
ter o nome da banda, que tipo de música ela toca, o número de integrantes e em que
posição do ranking essa banda está dentre as suas 5 bandas favoritas;
 b) Crie uma função para preencher as 5 estruturas de bandas criadas no exemplo
passado. Após criar e preencher, exiba todas as informações das bandas/estruturas.
 c) Crie uma função que peça ao usuário um número de 1 até 5. Em seguida, seu
programa deve exibir informações da banda cuja posição no seu ranking é a que foi
solicitada pelo usuário;
 d) Crie uma função que peça ao usuário um tipo de música e exiba as bandas com
esse tipo de música no seu ranking.
 e) Crie uma função que peça o nome de uma banda ao usuário e diga se ela está
entre suas bandas favoritas ou não;
 f) Agora junte tudo e crie um menu com as opções de preencher as estruturas e
todas as opções das questões passadas.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int count = 2;

//item a------------------------------------------------------------------------------------------------------------------------------------------------------------

typedef struct{

    char nome_banda[5][41];
    char tipo_musica[5][31];
    int numero_integrantes[5];
    int ranking[5];

}Musica;

void instrucoes(){

    printf("Este programa recebera do usuario suas 5 bandas favoritas e:\n");
    printf("-O tipo de musica tocada pela banda.\n");
    printf("-O numero de integrantes da banda.\n");
    printf("-Em qual ranking a banda ocupa entre as 5 favoritas.\n\n");
    printf("O usuario pode digitar um numero entre 1 e 5 para procurar as informacoes da banda segundo o seu ranking.\n\n");
    printf("O usuario pode buscar as bandas por tipo de musica.\n\n");
    printf("O usuario pode informar um nome de uma banda e o programa informara se a banda esta ou nao entre as favoritas.\n\n");
    printf("Ha um limite de 40 caracteres para banda.\n\n");
    printf("Ha um limite de 30 caracteres para o tipo de musica.\n\n");
    printf("Use numeros inteiros nao negativos e maiores que zero.\n");

return;
}//instrucoes

//item b------------------------------------------------------------------------------------------------------------------------------------------------------------

void preenche_exibe(Musica* mus){

    for(int linha = 0; linha < count; linha ++){

        printf("\nDigite o nome da banda (%i):\n\n", linha+1);
        fgets(mus->nome_banda[linha], 40, stdin);
        mus->nome_banda[linha][strcspn(mus->nome_banda[linha], "\n")] = '\0';
        setbuf(stdin,NULL);

    }//for linha

    for(int linha = 0; linha < count; linha ++){

        printf("\nPara a banda %s digite o tipo de musica:\n\n", mus->nome_banda[linha]);
        fgets(mus->tipo_musica[linha], 40, stdin);
        mus->tipo_musica[linha][strcspn(mus->tipo_musica[linha], "\n")] = '\0';
        setbuf(stdin,NULL);

    }//for linha

    for(int linha = 0; linha < count; linha ++){

        printf("\nPara a banda %s digite numero de integrantes da banda:\n\n", mus->nome_banda[linha]);
        scanf("%i", &mus->numero_integrantes[linha]);
        setbuf(stdin,NULL);

    }//for linha

    for(int linha = 0; linha < count; linha ++){

        printf("\nPara a banda %s digite a posicao no seu rankig de favoritos:\n\n", mus->nome_banda[linha]);
        scanf("%i", &mus->ranking[linha]);
        setbuf(stdin,NULL);

    }//for linha

    printf("\n");

return;
}//preenche_exibe

//item c------------------------------------------------------------------------------------------------------------------------------------------------------------


void busca_ranking(Musica* mus){

    int informa_ranking;

    printf("\nDigite o ranking da banda que voce deseja saber as informacoes:\n\n");
    scanf("%i", &informa_ranking);
    setbuf(stdin,NULL);

    for(int linha = 0; linha < count; linha++){

        if(mus->ranking[linha] == informa_ranking){

            printf("\nA banda %s, toca %s tipo de musica, possui %i membros na banda e ocupa %i posicao no seu ranking pessoal.\n\n", \
            mus->nome_banda[linha], mus->tipo_musica[linha], mus->numero_integrantes[linha], mus->ranking[linha]);

        }//if ranking igual

    }//for linha

return;
}//busca_ranking

//item d------------------------------------------------------------------------------------------------------------------------------------------------------------

void busca_tipo(Musica* mus){

    char recebe_tipo[31];
    int auxiliar = 0;

    printf("O usuario vai informar o tipo de musica para o porgrama filtrar as bandas.\n\n");
    printf("Os tipos de musica validos sao:\n");

    for (int linha = 0; linha < count; linha++){
    
        printf("\n-%s", mus->tipo_musica[linha]);
    
    }//for linha
    
    printf("\n\nDigite um tipo de musica valido:\n\n");
    fgets(recebe_tipo, 30, stdin);
    recebe_tipo[strcspn(recebe_tipo, "\n")] = '\0';
    setbuf(stdin, NULL);
    printf("\n");

    for(int linha = 0; linha < count; linha++){

        if(strcasecmp(recebe_tipo, mus->tipo_musica[linha]) == 0){

            printf("A banda %s toca o tipo de musica %s\n\n", mus->nome_banda[linha], mus->tipo_musica[linha]);
            auxiliar = 1;

        }//if existe

    }//for linha

        if(auxiliar == 0){

            printf("Para o tipo de musica %s nao ha bandas.\n\n", recebe_tipo);

        }//if nao existe

return;
}//busca_tipo

//item e------------------------------------------------------------------------------------------------------------------------------------------------------------

void procurar_banda(Musica* mus){

    int auxiliar = 0;
    char recebe_banda[41];

    printf("O programa ira procurar se a banda entrada pelo usuario esta entre as favoritas ou nao.\n\n");
    printf("Digite o nome de uma banda:\n\n");
    fgets(recebe_banda, 40, stdin);
    recebe_banda[strcspn(recebe_banda,"\n")] = '\0';
    setbuf(stdin, NULL);
    printf("\n");

    for(int linha = 0; linha < count; linha++){

        if(strcasecmp(recebe_banda, mus->nome_banda[linha]) == 0){

            printf("A banda %s esta entre as favoritas.\n\n", mus->nome_banda[linha]);
            auxiliar = 1;

        }//if favoritos

    }//for linha

    if(auxiliar == 0){

        printf("A banda %s nao esta entre as favoritas.\n\n", recebe_banda);

    }//if nao favoritos

}//procurar_banda

//item f------------------------------------------------------------------------------------------------------------------------------------------------------------

void menu(Musica* mus){
    
    int repete = 0;
    int opcao;

    while (repete >= 0){        

        printf("Escolha uma opcao de 1 a 4 no menu abaixo:\n\n");
        printf("(1)-Procura a informacao da banda pelo ranking do usuario.\n");
        printf("(2)-Busca as bandas por tipo de musica.\n");
        printf("(3)-Digite o nome de uma banda e o programa busca entre as favoritas.\n");
        printf("(4)-Finaliza o programa.\n\n");
        scanf("%i",&opcao);
        setbuf(stdin, NULL);

        switch (opcao){

        case 1: 

            busca_ranking(&*mus);

            break;

        case 2:

            busca_tipo(&*mus);

            break;

        case 3:

            procurar_banda(&*mus);

            break;

        case 4:

            printf("\nFinalizando programa.\n\n");

            repete = -1;

            break;
        
        default:

            printf("\nOpcao invalida tente de novo.\n\n");

        }//switch opcao

    }//while repete

}//menu

int main(){

    Musica mu;

    instrucoes();
    preenche_exibe(&mu);

    for(int linha = 0; linha < count; linha++){

        printf("\nA banda %s, toca %s tipo de musica, possui %i membros na banda e ocupa %i posicao no seu ranking pessoal.\n\n", \
        mu.nome_banda[linha], mu.tipo_musica[linha], mu.numero_integrantes[linha], mu.ranking[linha]);

    }//for linha

    menu(&mu);

return 0;
}//main

