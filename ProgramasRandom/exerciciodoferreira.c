#include <stdio.h>
#define MAX 99999
#define LIM 10000000

int numIguais(int a, int b);
int divisores(int n, int vret[]);
int somaParImpar(int v[], int tam, int *somaPar, int *somaImpar);

int main() {
    int numero, vet_divisores[MAX], num_divisores, somaPar, somaImpar;
    for(numero=0; numero<LIM; numero++) {
        num_divisores=divisores(numero, vet_divisores);
        somaParImpar(vet_divisores, num_divisores, &somaPar, &somaImpar);
        if(numIguais(somaPar, somaImpar)) {
            printf("%d\n", numero);
        }
    }
    printf("^todos os numeros verdes entre 0 e %d", LIM);
}

int numIguais(int a, int b) {
    return a==b ? 1 : 0;
}

int divisores(int n, int vret[]) {
    if(n<0) return -1;
    int i, tam=0;
    for(i=1; i<=n; i++) {
        if(n%i==0) {
            vret[tam++]=i;
        }
    }
    return tam;
}

int somaParImpar(int v[], int tam, int *somaPar, int *somaImpar) {
    int i;
    *somaPar=0;
    *somaImpar=0;
    for(i=0; i<tam; i++) {
        if(v[i]%2==0) *somaPar+=v[i];
        else *somaImpar+=v[i];
    }
}