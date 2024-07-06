//@Marcos Tadao Shoji @2374200 @prova2
//ITEM ELIMINADO = (g)
/*
Na tarde de ontem, 06 de dezembro, alguns servidores da Amazon (AWS) pararam de funcionar.
Com isso, diversos serviços ficaram indisponíveis. Dentre eles, os servidores da Riot responsáveis pelos jogos League of Legends, Valorant e Wild Rift.


Você foi convocado em uma missão de emergência para ajudar a identificar os locais das falhas e reestabelecer os serviços.

Para isso, faça um programa que armazene os dados de 5 cidades onde estão localizados os servidores com problemas, cada cidade possui: nome (20 caracteres), quantidade de servidores ativos(inteiro), quantidade de servidores com problemas (inteiro) e quantidade total de servidores(inteiro).

Para isso, faça:

a) Faça um programa que receba os dados das 5 cidades: nome(strings), a quantidade de servidores ativos e a quantidade de servidores com falha
( salvos nas duas primeiras colunas de uma matriz de inteiros 5x3).
Os valores não podem ser negativos, solicite novos valores enquanto o usuário digite valores inválidos.

b) Utilizando estruturas de repetição, calcule a quantidade total de servidores em cada cidade e salve na última coluna da matriz;

c) Exiba em formato de tabela (com colunas alinhas separadas por | ) os nomes, as 3 quantidades de servidores de todos as cidades.

d) Receba um nome de uma cidade e busque ela na lista, todos os dados de seus servidores (apenas 1 vez).
Exiba uma mensagem informando também caso não encontre o nome buscado.

e) Exiba o nome da cidade e a porcentagem da cidade que tem o maior percentual de servidores com problemas (duas casas decimais).

f) Utilizando estrutura de repetição, calcule e exiba o percentual total de servidores ativos e de servidores com problemas.

g) Acrescente o texto "Defeated" ao final da string do nome todas as cidades que têm o número de servidores com problemas maiores que os servidores ativos.
Em seguida exiba o nome de todas as cidades (alteradas ou não).
Ex: "São Paulo" -> "São Paulo Defeated"

Obs.:

Os itens devem ser executados sequencialmente (Não é um menu);
Para obtenção da nota máxima, faça cada item, de A a G, em uma função separada. Não utilize variáveis globais.
Sempre que possível, utilize estruturas de repetição;
Bônus do Professor:

Por estar se esforçando e cursando uma universidade em um ano de pandemia, você acumulou Influence Points (IP) com o professor.
Com isso, você ganhou o bônus de escolher, obrigatoriamente, um dos itens de "C" a "G" para ser eliminado da questão.
Indique o item eliminado com um comentário em seu código
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

    int linha;//contrução de repetição
    int coluna;//construção de repetição
    int comparacao;//compara strings
    float porcentagem[5];//porcentagem de falha para cada cidade
    float maior_indice;//maior porcentagem de falha
    char cidade_maior[30];//cidade com maior por centagem de falha
    int matriz_servidores[5][3];//matriz com dados dos servidores
    int servidores_ativos;
    int servidores_falha;
    int servidores_totais;
    char cidades[5][30];
    char recebe_cidade[30];//cidade para exibir dados de servidores
    int soma_servidores_ativos;
    int soma_servidores_falha;
    int soma_servidores_totais;
    float porcentagem_total_servidores_ativos;
    float porcentagem_total_servidores_falha;

    printf("Ha um problemas com os servidores.\n\n");
    printf("Insira 5 cidades com problemas.\n");

    for(linha = 0; linha < 5; linha++){

        printf("\nInsira o nome da cidade:\n\n");
        fgets(cidades[linha], 30, stdin);
        cidades[linha][strcspn(cidades[linha], "\n")] = '\0';
        setbuf(stdin, NULL);

    }//for cidades

    for(linha = 0; linha < 5; linha++){

        for(coluna = 0; coluna < 2; coluna++){

            printf("\nPara a cidade %s:\n\n", cidades[linha]);
            printf("Insira nas posicoes [0] a quantidade de servidores ativos.\n\n");
            printf("Nas posicoes [1] a quantidade de servidores com falha.\n\n");
            printf("Use apenas numeros naturais.\n\n");
            printf("Insira na posicao [%i]:\n\n", coluna);
            scanf("%i", &matriz_servidores[linha][coluna]);
            setbuf(stdin,NULL);

            if(matriz_servidores < 0){

                printf("\nAPENAS NUMEROS NATURAIS!!\n\n");
                printf("Tente de novo, ULTIMA CHANCE:\n\n");
                scanf("%i", &matriz_servidores[linha][coluna]);
                setbuf(stdin,NULL);

            }//if negativo

        }//for coluna

    }//for linha

    for(linha = 0; linha < 5; linha++){

        matriz_servidores[linha][2] = matriz_servidores[linha][0] + matriz_servidores[linha][1];

    }//for soma servidores

    for(linha = 0; linha < 5; linha++){

        printf("\ncidade:%-15s |servidores ativos: %4i |servidores com falha: %4i |servidores totais: %4i\n", cidades[linha], matriz_servidores[linha][0], matriz_servidores[linha][1], matriz_servidores[linha][2]);

    }//for exibe

    printf("\nInsira a cidade cujo deseja buscar informacoes:\n\n");
    fgets(recebe_cidade, 30, stdin);
    recebe_cidade[strcspn(recebe_cidade,"\n")] = '\0';
    setbuf(stdin,NULL);

    for(linha = 0; linha < 5; linha++){

        comparacao = strcasecmp(recebe_cidade, cidades[linha]);

        if(comparacao == 0){

            printf("\ncidade:%-15s |servidores ativos: %4i |servidores com falha: %4i |servidores totais: %4i\n", cidades[linha], matriz_servidores[linha][0], matriz_servidores[linha][1], matriz_servidores[linha][2]);

        }//if exibe

        else{

            printf("\nCidade nao encontrada.\n\n");

        }//else erro

    }//for linha

    for(linha = 0; linha < 5; linha++){

        porcentagem[linha] = (((float)matriz_servidores[linha][1] * 100) / (matriz_servidores[linha][2]));

    }//for linha

    float salva_valor = porcentagem[0];

    for(linha = 0; linha < 5; linha++){

        if(porcentagem[linha] >= salva_valor){

            maior_indice = porcentagem[linha];
            strcpy(cidade_maior, cidades[linha]);

        }//if compara

        salva_valor = porcentagem[linha];

    }//for linha

    printf("\nO maior indice de falhas e da cidade: %s com %.2f porcento de falha\n\n", cidade_maior, maior_indice);

    soma_servidores_ativos = matriz_servidores[0][0];
    soma_servidores_falha = matriz_servidores[0][1];
    soma_servidores_totais = matriz_servidores[0][2];

    for(linha = 1; linha < 5; linha++){

        soma_servidores_ativos = soma_servidores_ativos + matriz_servidores[linha][0];
        soma_servidores_falha = soma_servidores_falha + matriz_servidores[linha][1];
        soma_servidores_totais = soma_servidores_totais + matriz_servidores[linha][2];

    }//for linha

    porcentagem_total_servidores_ativos = (((float)100 * soma_servidores_ativos) / (soma_servidores_totais));
    porcentagem_total_servidores_falha = (((float)100 * soma_servidores_falha) / (soma_servidores_totais));

    printf("A porcentagem de todos os servidores:\n\n");
    printf("Ativos e de: %.2f\n\n", porcentagem_total_servidores_ativos);
    printf("Com falha e de: %.2f\n", porcentagem_total_servidores_falha);

return 0;
}//main
//ITEM ELIMINADO = (g)
