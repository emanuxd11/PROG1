#include <stdio.h>
#define MAX 10

void imprime(int v[], int n);
int le_inverte(int v1[], int v2[]);

int main()
{
    int v1[MAX], v2[MAX], n;
    n = le_inverte(v1, v2);
    printf("\nVetor inserido: ");
    imprime(v1, n);
    printf("Vetor invertido: ");
    imprime(v2, n);
}  

int le_inverte(int v1[], int v2[])
{
    int i, j;
    printf("Insira valores para o vetor (MAX 100, termina ao inserir -1):\n");
    for(i=0; i<MAX; i++)
    {   
        scanf("%d", &v1[i]);
        if(v1[i]==-1) break;
    }
    j=i-1;
    for(i=0; j-i>=0; i++)
        v2[i] = v1[j-i];
    return i;
}

void imprime(int v[], int n)
{
    int i;
    for(i=0; i<n; i++)
        printf("\npos %d -> %d", i+1, v[i]);
    printf("\n\n");
}