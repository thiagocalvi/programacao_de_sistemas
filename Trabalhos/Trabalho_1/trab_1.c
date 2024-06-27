#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void crivoDeEratostenes(int n) {
    bool *primo = (bool *)malloc((n + 1) * sizeof(bool));
    for (int i = 0; i <= n; i++) {
        primo[i] = true;
    }
    
    primo[0],primo[1] = false; // 0 e 1 não são primos

    for (int p = 2; p * p <= n; p++) {
        if (primo[p]) {
            // Marca todos os múltiplos de p como não primos
            for (int i = p; i <= n; i += p) {
                if (i != p) {  // Não marca o próprio número primo
                    primo[i] = false;
                }
            }
        }
    }

    printf("Números primos até %d são: ", n);
    for (int i = 2; i <= n; i++) {
        if (primo[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");

    free(primo);
}

int main() {
    int n;
    printf("Digite um número: ");
    scanf("%d", &n);
    crivoDeEratostenes(n);
    return 0;
}
