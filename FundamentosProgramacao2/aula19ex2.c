/**
 * @file aula19ex2.c
 * @author Marcos Tadao Shoji (shoji@alunos.urfpr.edu.br)
 * @brief 2) Crie um programa que contenha um vetor float (tamanho 10). Imprima o
          endereço de cada posição desse vetor.
 * @version 0.1
 * @date 2022-05-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

void instrucoes(){

    printf("Este programa mostrara o enderece de memoria de um vetor com 10 posicoes.\n");

return;
}//instrucoes

void ponteiroVetor(float vetor[]){

    for(int linha = 0; linha < 10; linha++){

        printf("\nO endereco de memoria da posicao %i eh: %p\n", linha, vetor+linha);

    }//for linha

return;
}//ponteiro vetor

int main(){

    float vetor[10];

    instrucoes();

    ponteiroVetor(vetor);

return 0;
}//main