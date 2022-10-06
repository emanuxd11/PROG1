#include <stdio.h>
#include <stdlib.h>

void multiEspecial(int n, int v1[], int v2[], int vRet[]);
void preencher_vetor(int v[], int n);
void imprimir_vetor(int v[], int n);

int main()
{
    int *v1, *v2, *vRet, n_elem;
    printf("\nInsira o numero de elementos dos vetores: ");
    scanf("%d", &n_elem);
    v1=(int*)malloc(n_elem * sizeof(int));
    v2=(int*)malloc(n_elem * sizeof(int));
    vRet=(int*)malloc(n_elem * sizeof(int));
    printf("\nPrimeiro vetor:\n");
    preencher_vetor(v1, n_elem);
    printf("\nSegundo vetor:\n");
    preencher_vetor(v2, n_elem);
    multiEspecial(n_elem, v1, v2, vRet);
    printf("\nMultiplicacao especial: ");
    imprimir_vetor(vRet, n_elem);
    puts("\n");
}

void preencher_vetor(int v[], int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("Insira o %d elemento: ", i+1);
        scanf("%d", &v[i]);
    }
}

void imprimir_vetor(int v[], int n)
{
    int i;
    printf("{");
    for(i=0; i<n; i++)
    {
        printf("%.d", v[i]);
        if(i>=0 && i<n-1) printf(", ");
    }
    printf("}");
}

void multiEspecial(int n, int v1[], int v2[], int vRet[])
{
    int i;
    for(i=0; i<n; i++)
        vRet[i]=v1[i]*v2[n-i-1];
}