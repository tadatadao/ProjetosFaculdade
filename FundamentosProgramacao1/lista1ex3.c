/*
4)Faça um programa que receba 3 idades distintas e mostre: a idade da pessoa mais velha;
a idade da pessoa mais nova e a média das 3 idades.
O programa deve considerar e informar o caso de 2 ou 3 pessoas terem a mesma idade.
*/
#include <stdio.h>
#include <stdlib.h>

int main() {

    float idade_pessoa1;
    float idade_pessoa2;
    float idade_pessoa3;
    float media_das_idades;

    printf("Vamos bricar com idades de 3 pessoas distintas.\n\n");
    printf("Insira a idade da primeira pessoa:\n\n");
    scanf("%f", &idade_pessoa1);
    printf("\nInsira a idade da segunda pessoa:\n\n");
    scanf("%f", &idade_pessoa2);
    printf("\nInsira a idade da terceira pessoa:\n\n");
    scanf("%f", &idade_pessoa3);

    if (idade_pessoa1 == idade_pessoa2 == idade_pessoa3) {
        printf("\nAs idades sao iguais: %f anos.\n\n", idade_pessoa1);
        printf("A media das idades e: %f anos\n", idade_pessoa1);
    }//if idades iguais

        else if (idade_pessoa3 > idade_pessoa2 && idade_pessoa2 > idade_pessoa1) {
            printf("\nAs idades do mais velho para o mais novo e:\n\n");
            printf("%f anos, %f anos, %f anos\n\n", idade_pessoa3, idade_pessoa2, idade_pessoa1);

            media_das_idades = (idade_pessoa1 + idade_pessoa2 + idade_pessoa3) / 3;

            printf("A media das idades vale: %f anos\n\n", media_das_idades);
        }//else idade3 > idade2 > idade1

            else if (idade_pessoa3 > idade_pessoa1 && idade_pessoa1 > idade_pessoa2) {
                printf("\nAs idades do mais velho para o mais novo e:\n\n");
                printf("%f anos, %f anos, %f anos\n\n", idade_pessoa3, idade_pessoa1, idade_pessoa2);

                media_das_idades = (idade_pessoa1 + idade_pessoa2 + idade_pessoa3) / 3;

                printf("A media das idades vale: %f anos\n\n", media_das_idades);
            }//else idade3 > idade1 > idade2

                else if (idade_pessoa1 > idade_pessoa2 && idade_pessoa2 > idade_pessoa3) {
                    printf("\nAs idades do mais velho para o mais novo e:\n\n");
                    printf("%f anos, %f anos, %f anos\n\n", idade_pessoa1, idade_pessoa2, idade_pessoa3);

                    media_das_idades = (idade_pessoa1 + idade_pessoa2 + idade_pessoa3) / 3;

                    printf("A media das idades vale: %f anos\n", media_das_idades);
                }//else idade1 > idade2 > idade3

                    else if (idade_pessoa1 > idade_pessoa3 &&idade_pessoa3 > idade_pessoa2) {
                        printf("\nAs idades do mais velho para o mais novo e:\n\n");
                        printf("%f anos, %f anos, %f anos\n\n", idade_pessoa1, idade_pessoa3, idade_pessoa2);

                        media_das_idades = (idade_pessoa1 + idade_pessoa2 + idade_pessoa3) / 3;

                        printf("A media das idades vale: %f anos\n\n", media_das_idades);
                    }//else idade1 > idade3 > idade2

                        else if (idade_pessoa2 > idade_pessoa3 && idade_pessoa3 > idade_pessoa1) {
                            printf("\nAs idades do mais velho para o mais novo e:\n\n");
                            printf("%f anos, %f anos, %f anos\n\n", idade_pessoa2, idade_pessoa3, idade_pessoa1);

                            media_das_idades = (idade_pessoa1 + idade_pessoa2 + idade_pessoa3) / 3;

                            printf("A media das idades vale: %f anos\n", media_das_idades);
                        }//else idade2 > idade3 > idade1

                            else if (idade_pessoa2 > idade_pessoa1 && idade_pessoa1 > idade_pessoa3) {
                                printf("\nAs idades do mais velho para o mais novo e:\n\n");
                                printf("%f anos, %f anos, %f anos\n\n", idade_pessoa2, idade_pessoa1, idade_pessoa3);

                                media_das_idades = (idade_pessoa1 + idade_pessoa2 + idade_pessoa3) / 3;

                                printf("A media das idades vale: %f anos\n", media_das_idades);
                            }//else idade2 > idade1 > idade3

                                else if (idade_pessoa3 == idade_pessoa2 && idade_pessoa3 > idade_pessoa1) {
                                    printf("\nDuas idades sao iguais\n\nn");
                                    printf("As idades dos mais velhos e do mais novo e:\n\n");
                                    printf("%f anos e %f anos.\n\n", idade_pessoa3, idade_pessoa1);

                                    media_das_idades = (idade_pessoa1 + idade_pessoa2 + idade_pessoa3) / 3;

                                    printf("A media das idades vale: %f anos\n", media_das_idades);
                                }//else idade3 = idade2 > idade1

                                    else if (idade_pessoa3 == idade_pessoa2 && idade_pessoa3 < idade_pessoa1) {
                                        printf("\nDuas idades sao iguais\n\nn");
                                        printf("A idades do mais velho e dos mais novos e:\n\n");
                                        printf("%f anos e %f anos.\n\n", idade_pessoa1, idade_pessoa3);

                                        media_das_idades = (idade_pessoa1 + idade_pessoa2 + idade_pessoa3) / 3;

                                        printf("A media das idades vale: %f anos\n", media_das_idades);
                                    }//else idade3 = idade2 < idade1

                                        else if (idade_pessoa2 == idade_pessoa1 && idade_pessoa2 > idade_pessoa3) {
                                            printf("\nDuas idades sao iguais\n\nn");
                                            printf("As idades dos mais velhos e do mais novo e:\n\n");
                                            printf("%f anos e %f anos.\n\n", idade_pessoa2, idade_pessoa3);

                                            media_das_idades = (idade_pessoa1 + idade_pessoa2 + idade_pessoa3) / 3;

                                            printf("A media das idades vale: %f anos\n", media_das_idades);
                                        }//else idade2 = idade1 > idade3

                                            else if (idade_pessoa2 == idade_pessoa1 && idade_pessoa2 < idade_pessoa3) {
                                                printf("\nDuas idades sao iguais\n\nn");
                                                printf("A idade do mais velho e dos mais novos e:\n\n");
                                                printf("%f anos e %f anos.\n\n", idade_pessoa3, idade_pessoa2);

                                                media_das_idades = (idade_pessoa1 + idade_pessoa2 + idade_pessoa3) / 3;

                                                printf("A media das idades vale: %f anos\n", media_das_idades);
                                            }//else idade2 = idade1 < idade3

                                                else if (idade_pessoa1 == idade_pessoa3 && idade_pessoa1 > idade_pessoa2) {
                                                    printf("\nDuas idades sao iguais\n\nn");
                                                    printf("As idades dos mais velhos e do mais novo e:\n\n");
                                                    printf("%f anos e %f anos.\n\n", idade_pessoa1, idade_pessoa2);

                                                    media_das_idades = (idade_pessoa1 + idade_pessoa2 + idade_pessoa3) / 3;

                                                    printf("A media das idades vale: %f anos\n", media_das_idades);
                                                }//else idade1 = idade3 > idade2

                                                    else if (idade_pessoa1 == idade_pessoa3 && idade_pessoa1 < idade_pessoa2) {
                                                        printf("\nDuas idades sao iguais\n\nn");
                                                        printf("A idade do mais velho e dos mais novos e:\n\n");
                                                        printf("%f anos e %f anos.\n\n", idade_pessoa2, idade_pessoa1);

                                                        media_das_idades = (idade_pessoa1 + idade_pessoa2 + idade_pessoa3) / 3;

                                                        printf("A media das idades vale: %f anos\n", media_das_idades);
                                                    }//else idade1 = idade3 < idade2


return 0;
}//main
