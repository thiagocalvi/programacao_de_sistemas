#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 6400
#define BITS_PER_BYTE 8

// cria a tabela de consulta
void buildPrimeTable(unsigned char *primeTable) {
    memset(primeTable, 0xFF, MAX / BITS_PER_BYTE); // marca todos como primos

    for (int i = 2; i * i <= MAX; i++) {
        if ((primeTable[i / BITS_PER_BYTE] & (1 << (i % BITS_PER_BYTE))) != 0) {
            for (int j = i * i; j <= MAX; j += i) {
                primeTable[j / BITS_PER_BYTE] &= ~(1 << (j % BITS_PER_BYTE));
            }
        }
    }
}

// consultar se um número é primo
int isPrime(unsigned char *primeTable, int num) {
    if (num < 2 || num > MAX) return 0;
    return (primeTable[num / BITS_PER_BYTE] & (1 << (num % BITS_PER_BYTE))) != 0;
}

int main() {
    unsigned char *primeTable = (unsigned char *)malloc(MAX / BITS_PER_BYTE);
    if (primeTable == NULL) {
        printf("Erro de alocação de memória\n");
        return 1;
    }

    buildPrimeTable(primeTable);

    // exemplo
    int num;
    printf("Digite um número entre 2 e 6400 para verificar se é primo: ");
    scanf("%d", &num);

    if (isPrime(primeTable, num)) {
        printf("%d é primo.\n", num);
    } else {
        printf("%d não é primo.\n", num);
    }

    free(primeTable);
    return 0;
}