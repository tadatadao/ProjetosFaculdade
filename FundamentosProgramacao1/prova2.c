//@Marcos Tadao Shoji @2374200 @prova2
/*
Na tarde de ontem, 06 de dezembro, alguns servidores da Amazon (AWS) pararam de funcionar.
Com isso, diversos servi�os ficaram indispon�veis. Dentre eles, os servidores da Riot respons�veis pelos jogos League of Legends, Valorant e Wild Rift.


Voc� foi convocado em uma miss�o de emerg�ncia para ajudar a identificar os locais das falhas e reestabelecer os servi�os.

Para isso, fa�a um programa que armazene os dados de 5 cidades onde est�o localizados os servidores com problemas, cada cidade possui: nome (20 caracteres), quantidade de servidores ativos(inteiro), quantidade de servidores com problemas (inteiro) e quantidade total de servidores(inteiro).

Para isso, fa�a:

a) Fa�a um programa que receba os dados das 5 cidades: nome(strings), a quantidade de servidores ativos e a quantidade de servidores com falha
( salvos nas duas primeiras colunas de uma matriz de inteiros 5x3).
Os valores n�o podem ser negativos, solicite novos valores enquanto o usu�rio digite valores inv�lidos.

b) Utilizando estruturas de repeti��o, calcule a quantidade total de servidores em cada cidade e salve na �ltima coluna da matriz;

c) Exiba em formato de tabela (com colunas alinhas separadas por | ) os nomes, as 3 quantidades de servidores de todos as cidades.

d) Receba um nome de uma cidade e busque ela na lista, todos os dados de seus servidores (apenas 1 vez).
Exiba uma mensagem informando tamb�m caso n�o encontre o nome buscado.

e) Exiba o nome da cidade e a porcentagem da cidade que tem o maior percentual de servidores com problemas (duas casas decimais).

f) Utilizando estrutura de repeti��o, calcule e exiba o percentual total de servidores ativos e de servidores com problemas.

g) Acrescente o texto "Defeated" ao final da string do nome todas as cidades que t�m o n�mero de servidores com problemas maiores que os servidores ativos.
Em seguida exiba o nome de todas as cidades (alteradas ou n�o).
Ex: "S�o Paulo" -> "S�o Paulo Defeated"

Obs.:

Os itens devem ser executados sequencialmente (N�o � um menu);
Para obten��o da nota m�xima, fa�a cada item, de A a G, em uma fun��o separada. N�o utilize vari�veis globais.
Sempre que poss�vel, utilize estruturas de repeti��o;
B�nus do Professor:

Por estar se esfor�ando e cursando uma universidade em um ano de pandemia, voc� acumulou Influence Points (IP) com o professor.
Com isso, voc� ganhou o b�nus de escolher, obrigatoriamente, um dos itens de "C" a "G" para ser eliminado da quest�o.
Indique o item eliminado com um coment�rio em seu c�digo
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

    int linha;
    int coluna;
    int matriz_servidores[5][3];
    int servidores_ativos;
    int servidores_falha;
    int servidores_totais;
    char cidades[5][30];

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

            printf("\nPara a cidade %s:\n\n", cidades[linha][30]);
            printf("\nInsira nas posicoes [0] a quantidade de servidores ativos.\n\n");
            printf("Nas posicoes [1] a quantidade de servidores com falha.\n\n");
            printf("\nInsira na posicao [%i]:\n\n", coluna);
            scanf("%i", &matriz_servidores[linha][coluna]);
            setbuf(stdin,NULL);

        }//for coluna

    }//for linha

    for(linha = 0; linha < 5; linha++){

        matriz_servidores[linha][2] = matriz_servidores[linha][0] + matriz_servidores[linha][1];

    }

return 0;
}//main

