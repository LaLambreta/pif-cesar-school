#include <stdio.h>

int main() {
    int n, i;
    long long int fat = 1;

    printf("Digite N: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Numero invalido!\n");
    } else {
        for (i = 1; i <= n; i++) {
            fat = fat * i;
        }
        printf("%d! = %lld\n", n, fat);
    }
    return 0;
}
