//@Marcos Tadao Shoji @RA:2374200 @prova1
/*
Voc� foi contratado pela Riot Games para elaborar partes do novo sistema do League of Legends.
Para isso exiba, uma �nica vez, um menu (5 pontos) com duas op��es:

Seja bem vindo ao sistema League of Legends
a) Verifica n�vel (Tier)
b) Calculo do taxa de vit�rias (winrate)

E pe�a a op��o desejada ao usu�rio

a) (10 pontos) Na primeira op��o, o programa deve receber a pontua��o do MMR e informar em qual n�vel do jogador seguindo a seguinte l�gica:

N�vel Bronze: MMR abaixo de 1090
N�vel Prata: MMR de 1090 a 1409
N�vel Ouro: MMR de 1410 a 1719
N�vel Platina: MMR de 1720 a 2019
N�vel Diamante: MMR de 2020 a 2500
N�vel Desafiante: MMR acima de 2500

b) (15 pontos) Na segunda op��o,
o programa deve receber o resultado de v�rias partidas por meio da letra V para indicar vit�ria
e D para derrota. A cada entrada o sistema deve exibir a taxa de vit�rias (winrate) com uma casa decimal,
que � o porcentual de vit�rias considerando todas as partidas recebidas at� o momento,
e em seguida deve solicitar uma nova entrada.
O sistema finalizar ao receber a letra F, situa��o na qual deve exibir:
O total de partidas, total de vit�rias, total de derrotas e o winrate final.

taxa de vitoria = (vitorias / vitorias + derrotas) * 100

*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    char opcao;//op��o do menu
    int pontuacao;//pontua��o do jogador
    float taxa_de_vitoria;
    char vitoria_derrota;//V ou v para vitoria; D ou d para derrota
    float contador_partidas;
    float contador_vitorias;
    float contador_derrotas;
    int loop = 0;//loop infinito

    printf("Seja bem vindo ao sistema League of Legends.\n\n");
    printf("No menu abaixo escolha uma opcao.\n\n");
    printf("a) Verifica n�vel (Tier)\nb) Calculo do taxa de vitorias (winrate)\n\n");
    printf("Entre com sua escolha.\n\n");
    scanf("%c", &opcao);
    setbuf(stdin,NULL);

    switch(opcao){

    case 'a':

        printf("\nEntao vamos verificar seu tier.\n\n");
        printf("Digite sua pontuacao (MMR):\n\n");
        scanf("%i", &pontuacao);

        if(pontuacao < 0){

            printf("\nSem pontuacao negativa.\n\n");

        }//if pontua��o invalida

        else if(pontuacao >= 0 && pontuacao < 1090){

            printf("\nVoce possui tier bronze.\n\n");

        }//else if bronze

        else if(pontuacao >= 1090 && pontuacao <= 1409){

            printf("\nVoce possui tier prata.\n\n");

        }//else if prata

        else if(pontuacao >= 1410 && pontuacao <= 1719){

            printf("\nVoce possui tier ouro.\n\n");

        }//else if ouro

        else if(pontuacao >= 1720 && pontuacao <= 2019){

            printf("\nVoce possui tier platina.\n\n");

        }//else if platina

        else if(pontuacao >= 2020 && pontuacao < 2500){

            printf("\nVoce possui tier diamante.\n\n");

        }//else if diamante

        else if(pontuacao >= 2500){

            printf("\nVoce possui tier desafiante.\n\n");

        }//else if desafiante
        break;

    case 'b':

        printf("\nEntao vamos calcular sua taxa de vitorias.\n\n");
        printf("Digite 'V' em caso de vitoria e 'D' em caso de derrota.\n\n");
        printf("Para encerrar o programa digite 'F'.\n\n");

        do{

            printf("Digite o resultado da partida (V/D):\n\n");
            scanf("%c", &vitoria_derrota);
            setbuf(stdin,NULL);

            if(vitoria_derrota == 'V' || vitoria_derrota == 'v'){

                contador_vitorias++;

            }//vitoria

            else if(vitoria_derrota == 'D' || vitoria_derrota == 'd'){

                contador_derrotas++;

            }//derrota

            else if(vitoria_derrota == 'F' || vitoria_derrota == 'f'){

                break;

            }//encerra

            contador_partidas++;

            taxa_de_vitoria = (contador_vitorias / contador_partidas) * 100;

            printf("\nSeu winrate e: %.1f\n\n", taxa_de_vitoria);

        }while(loop >= 0);

        printf("O total de partidas foi: %.1f\n\n", contador_partidas);
        printf("O total de derrotas foi: %.1f\n\n", contador_derrotas);
        printf("O total de vitorias foi: %.1f\n\n", contador_vitorias);
        printf("A taxa de vitoria foi: %.1f", taxa_de_vitoria);

    case 'A':

        printf("\nEntao vamos verificar seu tier.\n\n");
        printf("Digite sua pontuacao (MMR):\n\n");
        scanf("%i", &pontuacao);

        if(pontuacao < 0){

            printf("\nSem pontuacao negativa.\n\n");

        }//if pontua��o invalida

        else if(pontuacao >= 0 && pontuacao < 1090){

            printf("\nVoce possui tier bronze.\n\n");

        }//else if bronze

        else if(pontuacao >= 1090 && pontuacao <= 1409){

            printf("\nVoce possui tier prata.\n\n");

        }//else if prata

        else if(pontuacao >= 1410 && pontuacao <= 1719){

            printf("\nVoce possui tier ouro.\n\n");

        }//else if ouro

        else if(pontuacao >= 1720 && pontuacao <= 2019){

            printf("\nVoce possui tier platina.\n\n");

        }//else if platina

        else if(pontuacao >= 2020 && pontuacao < 2500){

            printf("\nVoce possui tier diamante.\n\n");

        }//else if diamante

        else if(pontuacao >= 2500){

            printf("\nVoce possui tier desafiante.\n\n");

        }//else if desafiante
        break;

    case 'B':

        printf("\nEntao vamos calcular sua taxa de vitorias.\n\n");
        printf("Digite 'V' em caso de vitoria e 'D' em caso de derrota.\n\n");
        printf("Para encerrar o programa digite 'F'.\n\n");

        do{

            printf("Digite o resultado da partida (V/D):\n\n");
            scanf("%c", &vitoria_derrota);
            setbuf(stdin,NULL);

            if(vitoria_derrota == 'V' || vitoria_derrota == 'v'){

                contador_vitorias++;

            }//vitoria

            else if(vitoria_derrota == 'D' || vitoria_derrota == 'd'){

                contador_derrotas++;

            }//derrota

            else if(vitoria_derrota == 'F' || vitoria_derrota == 'f'){

                break;

            }//encerra

            contador_partidas++;

            taxa_de_vitoria = (contador_vitorias / contador_partidas) * 100;

            printf("\nSeu winrate e: %.1f\n\n", taxa_de_vitoria);

        }while(loop >= 0);

        printf("O total de partidas foi: %.1f\n\n", contador_partidas);
        printf("O total de derrotas foi: %.1f\n\n", contador_derrotas);
        printf("O total de vitorias foi: %.1f\n\n", contador_vitorias);
        printf("A taxa de vitoria foi: %.1f", taxa_de_vitoria);

    default:

        printf("\nFoi cometido um erro, respeite as regras.\n\n");

    }//switch

return 0;
}//main
