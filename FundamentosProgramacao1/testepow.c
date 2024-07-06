#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    double a;
    double b;
    double c;
    double x1;
    double x2;

    printf("Entre a\n");
    scanf("%lf", &a);
    printf("Entre b\n");
    scanf("%lf", &b);
    printf("Entre c\n");
    scanf("%lf", &c);

    x1 = (-b + (sqrt((pow(b,2)) - (4 * a * c)))) / (2 * a);
    x2 = (-b - (sqrt((pow(b,2)) - (4 * a * c)))) / (2 * a);

    printf("Os valores de x sao: %.2lf e %.2lf\n", x1, x2);

return 0;
}
