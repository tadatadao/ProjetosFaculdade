/**
 * @file aula2.c000000
 * @author Marcos Tadao Shoji (shoji@alunos.utfpr.edu.br)
 * @brief
 * @version 0.1
 * @date 2022-03-09
 *
 * @copyright Copyright (c) 2022
 *
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

    char cidades[5][21];
    int servidores[5][3];

    for (int linha = 0; linha < 5; linha++)
    {
        printf("Digite a cidade:\n");
        fgets(cidades[linha],20,stdin);
        cidades[linha][strcspn(cidades[linha],"\n")] = '\0';
        setbuf(stdin,NULL);
    }//for

    for (int linha = 0; linha < 5; linha++)
    {
        for (int coluna = 0; coluna < 2; coluna++)
        {
            printf("Para a cidade %s\n", cidades[linha]);
            if(coluna == 0){
                printf("Digite a quantidade de servidores ativos:\n");
                scanf("%i", &servidores[linha][coluna]);
                setbuf(stdin,NULL);
                while(servidores[linha][coluna] < 0){
                    printf("Sem numeros negativos.\n");
                    printf("Digite novamente os servidores ativos:");
                    scanf("%i",&servidores[linha][coluna]);
                    setbuf(stdin,NULL);
                }//while
            }//if
            else{
                printf("Digite a quantidade de servidores falhos:\n");
                scanf("%i", &servidores[linha][coluna]);
                setbuf(stdin,NULL);
                while(servidores[linha][coluna] < 0){
                    printf("Sem numeros negativos.\n");
                    printf("Digite novamente os servidores falhos:\n");
                    scanf("%i",&servidores[linha][coluna]);
                    setbuf(stdin,NULL);
                }//while
            }//if
        }//for coluna
    }//for linha

    for(int linha = 0; linha < 5; linha++){
        servidores[linha][2] = servidores[linha][0] + servidores[linha][1];
    }//for linha

    for (int linha = 0; linha < 5; linha++){
        printf("%-20s | %-5i | %-5i | %-5i\n", cidades[linha], servidores[linha][0], servidores[linha][1], servidores[linha][2]);
    }//for linha

    char busca_cidade[21];
    printf("\nVamos buscar por uma cidade e suas informacoes.\n\n");
    printf("Insira o nome da cidade:\n\n");
    fgets(busca_cidade, 20, stdin);
    busca_cidade[strcspn(busca_cidade, "\n")] ='\0';
    setbuf(stdin,NULL);

    for(int linha = 0; linha < 5; linha++){
        if(strcasecmp(busca_cidade, cidades[linha]) == 0){
            printf("\nA cidade %s consta na lista com %i servidores ativos %i servidores falhos e %i servidores totais\n\n", cidades[linha], servidores[linha][0], servidores[linha][1], servidores[linha][2]);
            break;
        }//if igual
        else{
            printf("\nCidade nao encontrada na lista.\n\n");
        }//else diferente
    }//for linha

    printf("Vamos buscar a cidade com maior percentual de servidores com falha.\n\n");

    float porcentagem[5];

    porcentagem[0] = servidores[0][1]/ servidores[0][2] * 100;
    porcentagem[1] = servidores[1][1]/ servidores[1][2] * 100;
    porcentagem[2] = servidores[2][1]/ servidores[2][2] * 100;
    porcentagem[3] = servidores[3][1]/ servidores[3][2] * 100;
    porcentagem[4] = servidores[4][1]/ servidores[4][2] * 100;

    float maior_porcentagem;
    int posicao;

    for(int linha = 0; linha < 4; linha++){
        if(porcentagem[linha] > porcentagem[linha+1]){
            porcentagem[linha] = maior_porcentagem;
            posicao = linha;
        }//if maior porcentagem sem linha 0
    }//for linha
    printf("A cidade com maior percentual de falhas e a cidade %s com %.2f por cento de falha.\n\n", cidades[posicao], maior_porcentagem);

return 0;
}//main
