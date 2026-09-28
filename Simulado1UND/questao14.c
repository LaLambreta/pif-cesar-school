#include <stdio.h>

int main() {
    int senha, i;

    for (i = 1; i <= 3; i++) {
        printf("Digite a senha: ");
        scanf("%d", &senha);

        if (senha == 2026) {
            printf("Acesso Concedido!\n");
            return 0;
        }
    }

    printf("Conta Bloqueada por Seguranca!\n");
    return 0;
}
