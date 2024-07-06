#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    double valor;
    double raiz_valor;

    printf("Este programa pode calcular raizes quadradas.\n\n");
    printf("Informe o valor numerico para o calculo da raiz quadrada.\n\n");
    printf("Lembre-se de usar (.) para quebra decimal\n");
    scanf("%lf", &valor);

    raiz_valor = sqrt(valor);

    printf("\nA raiz quadrada do valor informado e: %lf\n", raiz_valor);

return 0;
}
