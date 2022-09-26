#include <stdio.h>

int *vmaior(int *valor1, int *valor2);

int main() {
    int a, b;
    printf("Insira dois numeros inteiros: ");
    scanf("%d %d", &a, &b);
    printf("Os enderecos das variaveis sao os seguintes: %p e %p\n", &a, &b);
    printf("O endereco do maior valor e %p\n", vmaior(&a, &b));
}

int *vmaior(int *valor1, int *valor2) {
    return *valor1>*valor2 ? valor1 : valor2;
}