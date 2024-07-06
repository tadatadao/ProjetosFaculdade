/**
 * @file simulado.c
 * @author Marcos Tadao Shoji (shoji@alunos.utfpr.edu.br)
 * @brief Você foi contratado pela Riot Games para elaborar partes do sistema sistema de Ranking do League of Legends. Para isso:

Os tiers são: Bronze, Prata, Ouro, Platina, Diamante e Desafiante. Para organizar os níveis utilize uma enumeração.

f) Utilizando uma função recursiva, calcule a soma de todas as partidas (vitórias e derrotas) de todos os jogadores.

Cada um dos itens de B a E deve ser implementada em uma função diferente.
Não é permitido o uso de variáveis globais.
Nas funções extras, caso necessário, utilize parâmetros adicionais.
 * @version 0.1
 * @date 2022-04-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define J 2

//a) Defina um tipo e estrutura para salvar os dados de jogadores para um Ranking. Cada jogador possui: nome, vitórias, derrotas, tier(nível) e pontos.

typedef struct{
    
    char nomes[50];
    int vitorias;
    int derrotas;
    int tier;
    int pontos;
    float winrate;

}Jogadores;

typedef enum{

    BRONZE =1,
    PRATA,
    OURO,
    PLATINA,
    DIAMANTE,
    DESAFIANTE 

}Tier;

void instrucoes(){

    printf("Este programa recebera do usario dados de 6 jogadores de LOL.\n\n");
    printf("Os dados sao:\n-O nome.\n-Quantidade de vitorias.\n-Quantidade de derrotas.\n-O tier do jogador.\n-Os pontos do jogador.\n\n");
    printf("Em seguida o programa calculara e mostrara o winrate de cada jogador.\n\n");
    printf("Apos sera exibida uma tabela de lideres por tier.\n\n");
    printf("Na sequencia o usuario podera buscar informacoes de um jogador pelo nome.\n\n");
    printf("Por ultimo o programa calculara a soma de partidas jogadas de todos os jogadores.\n\n");
    printf("Lembre-se de nunca inserir numeros negativos.\n\n");
    printf("Existe um limite de 49 caracteres para os nomes.\n\n");
    printf("Existe um limite de 19 caracteres para o tier.\n");

return;
}//instrucoes

//b) Receba do teclado e armazene os dados de 6 jogadores. Não devem ser permitidos valores negativos, novos valores devem ser solicitados caso necessário.

void preenche(Jogadores jog[]){

    for (int linha = 0; linha < J; linha++){
        
        printf("\nDigite o nome do jogador (%i):", linha+1);
        fgets(jog[linha].nomes, 49, stdin);
        jog[linha].nomes[strcspn(jog[linha].nomes, "\n")] = '\0';
        setbuf(stdin,NULL);
        
    }//for linha

    for (int linha = 0; linha < J; linha++){
        
        printf("\nDigite a quantidade de vitorrias do jogador (%s):", jog[linha].nomes);
        scanf("%i", &jog[linha].vitorias);
        setbuf(stdin,NULL);
        
        while(jog[linha].vitorias < 0){

            printf("\nSem valores negativos, tente de novo.\n\n");
            printf("Insira a quantidade de vitorias:\n\n");
            scanf("%i", &jog[linha].vitorias);
            setbuf(stdin,NULL);        

        }//while negativo
        
    }//for linha

    for (int linha = 0; linha < J; linha++){
        
        printf("\nDigite a quantidade de derrotas do jogador (%s):", jog[linha].nomes);
        scanf("%i", &jog[linha].derrotas);
        setbuf(stdin,NULL);

        while(jog[linha].vitorias < 0){

            printf("\nSem valores negativos, tente de novo.\n\n");
            printf("Insira a quantidade de vitorias:\n\n");
            scanf("%i", &jog[linha].derrotas);
            setbuf(stdin,NULL);        

        }//while negativo
        
    }//for linha

    for (int linha = 0; linha < J; linha++){
        
        printf("\nDigite o tier do jogador (%s):", jog[linha].nomes);
        scanf("%i", &jog[linha].tier);
        setbuf(stdin,NULL);
        
    }//for linha

    for (int linha = 0; linha < J; linha++){
        
        printf("\nDigite a quantidade de pontos do jogador (%s):", jog[linha].nomes);
        scanf("%i", &jog[linha].pontos);
        setbuf(stdin,NULL);

        while(jog[linha].vitorias < 0){

            printf("\nSem valores negativos, tente de novo.\n\n");
            printf("Insira a quantidade de vitorias:\n\n");
            scanf("%i", &jog[linha].pontos);
            setbuf(stdin,NULL);        

        }//while negativo
        
    }//for linha

    printf("\n");


return;
}//preenche
    
/*c) Exiba uma tabela alinhada com o nome e a taxa de vitórias (winrate) de cada jogador
winrate = vitórias / (vitórias+derrotas) * 100.
Cada calculo deve ser feito por meio de uma função adicional que recebe o número de vitórias e derrotas via cópia e retorna o winrate.*/

float taxa_vitorias(int vitorias, int derrotas){

    float winrate;

    winrate = (float)(vitorias) / (derrotas + vitorias) * 100;

return winrate;
}//winrate

void imprime_c(Jogadores jog[]){

    for(int linha = 0; linha < J; linha++){

        jog[linha].winrate = taxa_vitorias(jog[linha].vitorias, jog[linha].derrotas);

    }//for linha

    for(int linha = 0; linha < J; linha++){

        printf("Jogador: %-20s | Winrate: %-5.2f%%\n", jog[linha].nomes, jog[linha].winrate);

    }//for linha

return;
}//imprime c

//d) Exiba uma tabela com os líderes (maior número de pontos) de cada um dos tiers.
//Para isso, faça uma função extra que receba um tier e retorne uma estrutura do tipo Jogador com os dados do líder.

//percorrer os tiers
//verificar existencia do tier
//achar lider

void mostra_tier(int tier){

    switch(tier){

        case BRONZE:
            
            printf("Rank: Bronze.\n");
            break;

        case PRATA:
            
            printf("Rank: Prata.\n");
            break;

        case OURO:
            
            printf("Rank: Ouro.\n");
            break;

        case PLATINA:
            
            printf("Rank: Platina.\n");
            break;

        case DIAMANTE:
            
            printf("Rank: Diamante.\n");
            break;

        case DESAFIANTE:
            
            printf("Rank: Desafiante.\n");
            break;

        default:

            break;

    }//switch tier

}//mostra tier

int checa_tier(Jogadores jog[], int tier){

    int tier_vazio = 1;

    for(int linha = 0; linha < J; linha++){

        if(jog[linha].tier == tier){

            tier_vazio = 0;
            
        }//if tier existe

    }//for linha

return tier_vazio;
}//checa tier

Jogadores lider(Jogadores jog[], int tier){

    Jogadores topzera;
    int armazena_pontos = 0;

    for(int linha = 0; linha < J; linha++){

        if(jog[linha].tier == tier){

            if(armazena_pontos < jog[linha].pontos){

                armazena_pontos = jog[linha].pontos;

                topzera = jog[linha];

            }//if achar maior

        }//if mesmo tier

    }//for linha

return topzera;
}//lider

void placar_lideres(Jogadores jog[]){

    for(int tier = BRONZE; tier <= DESAFIANTE; tier++){

        int tier_vazio = 1;

        tier_vazio = checa_tier(jog, tier);

        Jogadores topzera = lider(jog, tier);

        if(tier_vazio == 0){

            mostra_tier(tier);
            printf("Nome: %s\n", topzera.nomes);
            printf("Vitorias: %i\n", topzera.vitorias);
            printf("Derrotas: %i\n", topzera.derrotas);
            printf("Pontos: %i\n", topzera.pontos);
            printf("Winrate: %.2f\n\n", topzera.winrate);

        }//if tier nao vazio

    }//for tier

return;
}//exibe tabela

//e) Faça a busca de um jogador pelo nome digitado. 
//A busca deve ser feita por uma função adicional que recebe o nome e retorna os dados de vitórias, derrotas, tier e pontos via referência.

void busca_nome(Jogadores jog[], char* procura_nome, int* vitorias, int* derrotas, int* tier, int* pontos){  



return;
}//busca nome

void imprime_dados(Jogadores jog[]){

    char procura_nome[50];
    int vitorias, derrotas, tier, pontos;

    printf("\nDigite o nome de um jogador:");
    fgets(procura_nome, 49, stdin);
    procura_nome[strcspn(procura_nome, "\n")] = '\0';
    setbuf(stdin, NULL);

    for(int linha = 0; linha < J; linha++){

        if(strcasecmp(procura_nome, jog[linha].nomes) == 0){

            vitorias = jog[linha].vitorias;
            derrotas = jog[linha].derrotas;
            tier = jog[linha].tier;
            pontos = jog[linha].pontos;

        }//if igual

    }//for linha

    busca_nome(jog, &procura_nome, &vitorias, &derrotas, &tier, &pontos);

return;
}//imprime dados

int main(){

    Jogadores jog[J];
   
    instrucoes();
    preenche(jog);
    imprime_c(jog);
    printf("\n");
    placar_lideres(jog);
    printf("\n");   

return 0;
}//main