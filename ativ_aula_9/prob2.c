#include <stdio.h>

void ordena(int *valorA, int *valorB, int *valorC);

int main() {
    int a, b, c;
    printf("Insira 3 valores inteiros: ");
    scanf("%d %d %d", &a, &b, &c);
    ordena(&a, &b, &c);
    printf("Valores a, b e c ordenados por ordem crescente: %d %d %d\n", a, b, c);
}

void ordena(int *valorA, int *valorB, int *valorC) {
    if(*valorA>*valorB) {
        *valorA+=*valorB;
        *valorB=*valorA-*valorB;
        *valorA-=*valorB;
    }
    if(*valorC<*valorB) {
        *valorC+=*valorB;
        *valorB=*valorC-*valorB;
        *valorC-=*valorB;
    } 
    if(*valorB<*valorA) {
        *valorB+=*valorA;
        *valorA=*valorB-*valorA;
        *valorB-=*valorA;
    }
}