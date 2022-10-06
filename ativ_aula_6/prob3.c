#include <stdio.h>
#include <stdlib.h>

void preencher_vetor(float v[], int n);
void imprimir_vetor(float v[], int n);
float avg(float x[]);
float max(float x[]);
float min(float x[]);

int main()
{
    float v[10];
    preencher_vetor(v, 10);
    printf("Media: %.1f\nMaximo: %.1f\nMinimo: %.1f", avg(v), max(v), min(v));
    imprimir_vetor(v, 10);
}

void preencher_vetor(float v[], int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("\nInsira o %d elemento: ", i+1);
        scanf("%f", &v[i]);
    }
}

void imprimir_vetor(float v[], int n)
{
    int i;
    printf("\nO vetor lido foi: {");
    for(i=0; i<n; i++)
    {
        printf("%.1f", v[i]);
        if(i>=0 && i<n-1) printf(", ");
    }
    printf("}");
}

float avg(float x[])
{
    int i;
    float soma=0;
    for(i=0; i<10; i++)
        soma+=x[i];
    return soma/10;   
}
float min(float x[])
{
    int i;
    double min=x[0];
    for(i=0; i<10; i++)
        if((double)x[i]<=min) min=x[i];
    return min;
}
float max(float x[])
{
    int i;
    double max=x[0];
    for(i=0; i<10; i++)
        if((double)x[i]>=max) max=x[i];
    return max;
}