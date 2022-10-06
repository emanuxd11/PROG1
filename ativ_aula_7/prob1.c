#include <stdio.h>
#define TAM 5

int procuraTodos(int v[], int N, int x, int posicoes[]);

int main()
{
    int i, v[TAM], posicoes[TAM]={0}, valproc, dimpos;
    for(i=0; i<TAM; i++)
    {
        printf("Insira o %d elemento: ", i+1);
        scanf("%d", &v[i]);
    }
    printf("\nInsira o elemento a procurar: ");
    scanf("%d", &valproc);
    dimpos=procuraTodos(v, TAM, valproc, posicoes);
    printf("O valor foi encontrado %d vezes nas seguintes posicoes:", dimpos);
    for(i=0; i<TAM; i++)
        if(posicoes[i]!=0) printf("\n%d", posicoes[i]);
    puts("\n\n");
    
}

int procuraTodos(int v[], int N, int x, int posicoes[])
{
    int i, cont=0;
    for(i=0; i<N; i++)
    {
        if(v[i]==x) 
        {
            posicoes[i]=i+1;
            cont++;
        }
    }
    return cont;
}