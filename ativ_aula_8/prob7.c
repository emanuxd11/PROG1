#include <stdio.h>

float serieQ(int n);
float serieA(int n);
int potencia(int a, int b);

int main() {
    int n;
    printf("Insira o valor de n: ");
    scanf("%d", &n);
    printf("Q(%d)=%.2f e A(%d)=%.4f", n, serieQ(n), n, serieA(n));
}

int potencia(int a, int b) {
    int i;
    float res;
    for(i=0, res=1; i<b; i++) {
        res*=a;
    }   
    return res;
}

float serieQ(int n) {
    int i;
    float res=0;
    for(i=1; i<=n; i++) {
        res+=1.0/potencia(i, 2);
    }
    return res;
}

float serieA(int n) {
    int i;
    float res=0;
    for(i=1; i<=n; i++) {
        res+=potencia(-1, i+1)*1.0/potencia(2, i);
    }
    return res;
}