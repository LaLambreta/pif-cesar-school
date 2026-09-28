#include <stdio.h>

int main() {
    float nota;

    do {
        printf("Digite a nota (0 a 10): ");
        scanf("%f", &nota);
        if (nota < 0 || nota > 10)
            printf("Nota invalida!\n");
    } while (nota < 0 || nota > 10);

    printf("Nota valida: %.1f\n", nota);
    return 0;
}
