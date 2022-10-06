#include <stdio.h>
#define PI 3.14159
 
int fatorial(int n);
float potencia(float a, int b);
float vabs(float x);
float seno(float x, float tolerancia);

int main() {
    float x, tolerancia;
    printf("Insira o valor de x: ");
    scanf("%f", &x);
    printf("Insira o valor da tolerancia: ");
    scanf("%f", &tolerancia);
    printf("sin(%.2f) = %f", x, seno(x, tolerancia));
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

float seno(float x, float tolerancia) {
    int n=1, neg=0;
    float sin=0, termo=0;

    while(vabs(x)>2*PI) {
        if(x>0) x-=2*PI;
        else x+=2*PI;
    }

    if(x<0) {
        if(x>-PI) neg=1;
        x+=PI;
    } else if(x>0) {
        if(x>PI) neg=1;
        x-=PI;
    }

    if(vabs(x)>PI/2) {
        if(x>0) x=PI/2-(x-PI/2);
        else x=PI/2+(x+PI/2);
    }

    do {
        sin+=termo;
        termo=potencia(-1, n+1)*(potencia(vabs(x), 2*n-1)/fatorial(2*n-1));
        n++;
    } while(vabs(termo)>=tolerancia);

    return neg ? -sin : sin;
}