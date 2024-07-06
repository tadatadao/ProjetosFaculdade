#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char sim_nao;
    printf("Responda com s ou n\n\n");
    scanf("%c", &sim_nao);

    switch(sim_nao){

        case 'n':
        printf("\nentao nao\n");
        break;

        case 's':
        printf("\nentao sim\n");
        break;

        default:
        printf("\neu disse s ou n\n");

    }

return 0;
}
