#include<stdio.h>
#include<stdlib.h>
int main(){
    int a = 1;//primeira variavel
    int b = 2;//segunda variavel
    int aux = 0;//variavel auxiliar para inversao de valores
    printf("a tem valor inicial %i\n",a);
    printf("b tem valor inicial %i\n\n\n",b);
    aux = a;//igualando variavel auxiliar a 'a'
    a = b;//igualando variavel 'a' a 'b'
    b = aux;// igualando variavel 'b' a auxiliar
    /*
    auxiliar igual a 'a' ou seja igual a 1
    'a' igual a 'b' ou seja a igual a 2
    'b' igual a auxiliar ou seja igual a 1
    */
    printf("a tem valor final %i\n",a);
    printf("b tem valor final %i\n",b);
    return 0;
}
