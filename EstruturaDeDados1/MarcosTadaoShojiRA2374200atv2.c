/**
    Marcos Tadao Shoji
    RA:2374200
    4 periodo
    UTFPR Apucarana
    Engemharia de Computacao
    Versao final
    Instrucoes: Elabore um programa que realize a conversao de numeros decimais (nao negativos) para numeros hexa-
    decimais usando Pilha Dinamica. O programa deve permitir que:

    • O usuario digitar um numero decimal (N ≥ 0);
    • Efetuar sucessivas divisoes por 16 e armazenar os restos destas divisoes na pilha (veja o esboco da
      ideia na Figura 1);
    • Na ultima divisao, armazenar tambem o quociente que sera o elemento do topo;
    • Imprimir a pilha, pois ela contera o valor de N em base hexadecimal.
*/

//bibliotecas
#include <stdio.h>
#include <stdlib.h>

typedef struct numHexa{

    char elemento;//elemento
    struct numHexa *proximo;//aponta para o proximo

}NumHexa;//estrutura numero hexadecimal

typedef struct pilhaHexa{

    NumHexa *topo;//topo da pilha
    int qtd;//quantidade de elementos

}PilhaHexa;//estrutura pilha

void instrucoes(){

    printf("\nO programa realiza conversao de um numero decimal em hexadecimal.\n");
    printf("Use apenas numeros: positivos, inteiros, maiores ou iguais zero.\n");

}//instrucoes para usuario

void iniciaPilha (PilhaHexa *pilha) {

    pilha->topo = NULL;//iniccializacao importante, topo aponta para null

}//iniciaPilha

void pushPilhaHexa (PilhaHexa *pilha, char ch){

    NumHexa *auxiliar = (NumHexa*) malloc(sizeof(NumHexa));//alocacao dinamica
    auxiliar->elemento = ch;//montagem da pilha dinamica elemento reccebe um numero caractere (tipo char)
    auxiliar->proximo = pilha->topo;//proximo aponta para topo que tem null
    pilha->topo = auxiliar;//topo aponta para auxiliar

}//pushPilhaHexa

//funcao definindo uma base hexadecimal
int baseHexa(int numero){

    if(numero < 10){
        numero += 48;//caracteres de 0 a 9 em ascii
    }
    else{
            numero += 87;//caracteres de A a F em ascii
    }

    return numero;//funcao tipo int, retorna numero

}//base

//funcao de conversao
void converteDecToHexa(PilhaHexa *pilha, int numero){

    int resto;
    int quociente = numero;

    while (numero >= 16) {

        resto = numero % 16;//salva o resto da divisao po 16
        pushPilhaHexa(pilha, baseHexa(resto));//insere na pilha
        numero /= 16;//salva o quociente sa divisao por 16
        quociente = numero;//atribui na variavel quociente

    }//conversao de decimal para hexadecimal

    pushPilhaHexa(pilha, baseHexa(quociente));

}//converteDecToHexa

void printPilha(PilhaHexa pilha){

    NumHexa *aux = pilha.topo;

    while (aux != NULL) {

        printf("%c", aux->elemento);
        aux = aux->proximo;

    }

}//printPilha

void destroiPilha(PilhaHexa *pilha){

    while(pilha->topo != NULL){

        NumHexa *aux = pilha->topo;//auxiliar recebe o topo da pilha
        pilha->topo = aux->proximo;//topo aponta para o proximo elemento
        free(aux);//liberou o auxiliar o auxiliar fica sem nada
        aux = pilha->topo;//atribui o topo da pilha ao auxiliar novamente
        pilha->qtd--;//decrementa quantidade de elementos

    }

    pilha->qtd = 0;

}//termina destroi

int main(){

    instrucoes();

    PilhaHexa pilha;

    int numero_usuario, opcao;

    do{

        iniciaPilha(&pilha);
        printf("Digite um numero em base decimal: ");
        scanf("%d", &numero_usuario);
        setbuf(stdin, NULL);

        while(numero_usuario < 0){

            printf("\nEntrada invalida, numeros inteiros positivos, maiores ou iguais a zero.\n");
            printf("Digite um numero em base decimal: ");
            scanf("%d", &numero_usuario);
            setbuf(stdin, NULL);
            printf("\n");

        }//tratamento de erro de usuario

        converteDecToHexa(&pilha, numero_usuario);

        printf("\n\n");
        printPilha(pilha);

        printf("\n\n");

        printf("Deseja converter outro numero? (1 - Sim, 0 - Nao): ");//opcao se usuario deseja ou nao converter mais numeros
        scanf("%d", &opcao);
        setbuf(stdin,NULL);

    }while(opcao == 1);//tratamento para usuario converter quantidade de numeros desejados

    destroiPilha(&pilha);//libera memoria

    return 0;

}//fim da main
