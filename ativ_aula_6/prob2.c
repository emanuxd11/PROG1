#include <stdio.h>
#include <stdlib.h>

void preencher_vetor(float v[], int n);
float somatorio_vetor(float v[], int n);
void imprimir_vetor(float v[], int n);

int main()
{
    int n_elem;
    float *v;
    v = malloc(n_elem * sizeof(float));
    printf("Insira o numero de elementos a armazenar: ");
    scanf("%d", &n_elem);
    preencher_vetor(v, n_elem);
    imprimir_vetor(v, n_elem);
    printf("\ne a soma dos seus elementos e %.1f", somatorio_vetor(v, n_elem));
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

float somatorio_vetor(float v[], int n)
{
    int i, soma=0;
    for(i=0; i<n; i++)
        soma+=v[i];
    return soma;
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