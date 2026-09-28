#include <stdio.h>

int main() {
    int total, h, m, s;

    printf("Digite os segundos: ");
    scanf("%d", &total);

    h = total / 3600;
    m = (total % 3600) / 60;
    s = total % 60;

    printf("%d hora(s), %d minuto(s) e %d segundo(s)\n", h, m, s);
    return 0;
}
