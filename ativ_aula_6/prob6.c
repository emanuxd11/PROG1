#include <stdio.h>
#define tamanho 15

void imprimir_vetor(int v[], int n);

int main()
{
    int i, j, v[tamanho];
    for(i=0; i<tamanho; i++)
    {
        printf("\nInsira o elemento %d: ", i+1);
        scanf("%d", &v[i]);
        for(j=i; j>0; j--)
        {   
            if(v[j]<v[j-1])
            {
                v[j]=v[j]+v[j-1];
                v[j-1]=v[j]-v[j-1];
                v[j]=v[j]-v[j-1];
            }
        }
        printf("Vetor: ");
        imprimir_vetor(v, i+1);
    }
}

void imprimir_vetor(int v[], int n)
{
    int i;
    printf("{");
    for(i=0; i<n; i++) 
    {
        printf("%d", v[i]);
        if(i>=0 && i<n-1) printf(", ");
    }
    printf("}");
}