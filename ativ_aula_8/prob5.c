#include <stdio.h>
#define PI 3.14159
 
int fatorial(int n);
float potencia(float a, int b);
float vabs(float x);
float seno(float x, float tolerancia, int *termos);

int main() {
    float x, tolerancia;
    int numero_termos;
    printf("Insira o valor de x: ");
    scanf("%f", &x);
    printf("Insira o valor da tolerancia: ");
    scanf("%f", &tolerancia);
    printf("sin(%.2f) = %f", x, seno(x, tolerancia, &numero_termos));
    printf(" (%d termos da serie)", numero_termos);
}

int fatorial(int n) {
    int i, res;
    for(i=1, res=1; i<=n; i++) {
        res*=i;
    }
    return res;
}

float potencia(float a, int b) {
    int i;
    float res;
    for(i=0, res=1; i<b; i++) {
        res*=a;
    }   
    return res;
}

float vabs(float x) {
    return x<0 ? -x : x;
}

float seno(float x, float tolerancia, int *termos) {
    int n=1;
    float sin=0, termo=0;
    while(x>2*PI) {
        x-=2*PI;    //converte ângulo para o intervalo [0; 2PI]
    }
    if(x>PI) x=-x+PI;    //converte ângulo de [0; 2PI] para o primeiro ou segundo quadrante 
    if(x>PI/2) x=PI/2-(x-PI/2);    //converte ângulo do segundo quadrante para o primeiro  



    do {
        sin+=termo;
        termo=potencia(-1, n+1)*(potencia(x, 2*n-1)/fatorial(2*n-1));
        n++;
    } while(vabs(termo)>=tolerancia);
    *termos=n-2;


    return sin;
} //-2.85841
  //-4.42841
  //