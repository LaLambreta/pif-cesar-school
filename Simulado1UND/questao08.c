#include <stdio.h>
#include <math.h>

#define PI 3.14159265

int main() {
    double r, area, volume;

    printf("Digite o raio: ");
    scanf("%lf", &r);

    area = 4 * PI * pow(r, 2);
    volume = (4.0 / 3.0) * PI * pow(r, 3);

    printf("Area: %.3f\n", area);
    printf("Volume: %.3f\n", volume);
    return 0;
}
