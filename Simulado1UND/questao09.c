#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c, p, area;

    printf("Digite os tres lados: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    p = (a + b + c) / 2.0;
    area = sqrt(p * (p - a) * (p - b) * (p - c));

    printf("Area: %.2f\n", area);
    return 0;
}
