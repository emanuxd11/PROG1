#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int sum_v(float x[], int n, float vRet[]);
float range_v(float x[], int n);
int diff_v(float x[], int n, float vRet[]);
void preencher_vetor(float v[], int n);
void imprimir_vetor(float v[], int n);

int main()
{
    float *v, *vRet; 
    int n_elem, n_elem2, tamanho_vRet;
    printf("Insira o tamanho do vetor: ");
    scanf("%d", &n_elem);
    n_elem2 = n_elem%2==0 ? n_elem/2 : n_elem/2+1;
    v = malloc(n_elem * sizeof(float));
    vRet = malloc(n_elem2 * sizeof(float));
    preencher_vetor(v, n_elem);
    tamanho_vRet = sum_v(v, n_elem, vRet);  //definir o tamhanho pq é pedido no exercício
    printf("\nVetor Soma: ");
    imprimir_vetor(vRet, tamanho_vRet);
    printf("\nGama: %.2f", range_v(v, n_elem));
    diff_v(v, n_elem, vRet);
    printf("\nVetor Desvio Max Par: ");
    imprimir_vetor(vRet, tamanho_vRet);
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
    printf("{");
    for(i=0; i<n; i++)
    {
        printf("%.1f", v[i]);
        if(i>=0 && i<n-1) printf(", ");
    }
    printf("}");
}

int sum_v(float x[], int n, float vRet[])
{
    int i;
    for(i=0; i<n; i++)
        vRet[i]=x[2*i]+x[2*i+1];
    return n%2==0 ? n/2 : n/2+1;
}

float range_v(float x[], int n)
{
    int i;
    float max=x[0], min=x[0];
    for(i=0; i<n; i++)
    {
        if(x[i]>max) max=x[i];
        if(x[i]<min) min=x[i];
    }
    return max-min;
}

int diff_v(float x[], int n, float vRet[])
{
    int i;
    float aux;
    for(i=0; i<n; i++)
    {    
        aux = sqrt(x[2*i]*x[2*i+1]);
        vRet[i]=vRet[i]-aux-(int)(vRet[i]-aux);
    }
    return n%2==0 ? n/2 : n/2+1;
}