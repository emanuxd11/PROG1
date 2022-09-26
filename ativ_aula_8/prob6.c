#include <stdio.h>

int numero_cont(int a, int b);

int main() {
    int a, b;
    printf("Insira a: ");
    scanf("%d", &a);
    printf("Insira b: ");
    scanf("%d", &b);
    if(numero_cont(a, b)) {
        printf("%d esta contido em %d", b, a);
    } else {
        printf("%d nao esta contido em %d", b, a);
    }
}

int numero_cont(int a, int b) {
    int i, j, a1, b1, ndigia, ndigib, digia[11], digib[11], cont=0;
    for(i=0; i<ndigia; i++) {
        for(j=0; j<ndigib; j++) {
            if(digia[i+j]!=digib[j]) break;
        }
        if(j==ndigib) return 1;
    }
    return 0;
}