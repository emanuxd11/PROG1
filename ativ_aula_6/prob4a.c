#include <stdio.h>

int contaRepeticao(int v[], int tamanhoVetor, int numero);

int main()
{
    int v[999], i, numpesq, n_elem=0;
    for(i=0; v[i-1]>=0; i++)
    {
        printf("\nInsira um numero: ");
        scanf("%d", &v[i]);
        n_elem++;
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