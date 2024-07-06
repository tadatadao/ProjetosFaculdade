//@Marcos Tadao Shoji @aula8ex8
/*
8) Faça um menu que mostre 3 opções
Menu do programa:
1 - Teste 1
2 - Teste 2
3 – Sair do programa
Digite sua opção:
 A primeira opção imprime o texto “Teste1” e mostra o menu novamente.
 A segunda opção imprime “Teste2” e mostra o menu novamente.
 A terceira opção finaliza o programa.
 Caso digite uma opção diferente, deve mostrar uma mensagem de erro e
mostrar o menu novamente.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    int opcao;

    printf("Olhe o menu abaixo!\n\n");
    printf("MENU:\n1--------Teste1\n2--------Teste2\n3--------Finalizar o programa\n\n");
    printf("Agora escolha uma opcao entre (1), (2) ou (3):\n\n");

    while (opcao != 3) {

        scanf("%i", &opcao);

        if (opcao == 1) {

            printf("\nTeste 1\n\n");
            printf("MENU:\n1--------Teste1\n2--------Teste2\n3--------Finalizar o programa\n\n");
            printf("Agora escolha novamente entre (1), (2) ou (3):\n\n");

        }//if (1)

            else if (opcao == 2) {

                printf("\nTeste 2\n\n");
                printf("MENU:\n1--------Teste1\n2--------Teste2\n3--------Finalizar o programa\n\n");
                printf("Agora escolha novamente entre (1), (2) ou (3):\n\n");

            }//else (2)

                else {

                    printf("\nOpcao fora do menu, tente de novo.\n\n");
                    printf("MENU:\n1--------Teste1\n2--------Teste2\n3--------Finalizar o programa\n\n");
                    printf("Agora escolha novamente entre (1), (2) ou (3):\n\n");

                }//else erro

    }//while

return 0;
}//main
