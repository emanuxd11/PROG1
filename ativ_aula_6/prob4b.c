#include <stdio.h>
#include <stdlib.h>

int contaRepeticao(int v[], int tamanhoVetor, int numero);

int main()
{
    int *v, i, numpesq, n_elem;
    printf("Insira o numero de elementos do conjunto: ");
    scanf("%d", &n_elem);
    v = (int*)malloc(n_elem * sizeof(int));
    for(i=0; v[i-1]>=0; i++)
    {
        printf("\nInsira um numero: ");
        scanf("%d", &v[i]);
    }
    printf("\nInsira o numero a pesquisar: ");
    scanf("%d", &numpesq);
    printf("\nA maior sequencia com o numero %d tem tamanho %d", numpesq, contaRepeticao(v, n_elem, numpesq));
}

int contaRepeticao(int v[], int tamanhoVetor, int numero)
{
    int i, cont=0, max=0;
    for(i=0; i<tamanhoVetor; i++)
    {
        if(v[i]==numero) cont++;
        else cont=0;
        if(cont>max)
            max = cont;
    }
    return max;
}