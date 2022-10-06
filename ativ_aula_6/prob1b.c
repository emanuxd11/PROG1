//com n lançamentos
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int resultado();

int main()
{
    int j, i, nlanca, *resultados;
    srand(time(NULL));
    printf("Insira o numero de lancamentos: ");
    scanf("%d", &nlanca);
    resultados = (int*)malloc(nlanca * sizeof(int));
    printf("Histograma correspondente a %d lancamentos: ", nlanca);
    for(i=0; i<nlanca; i++)
    {   
        printf("\n%d - ", i+1);
        resultados[i] = 1+rand()%6;
        for(j=0; j<resultados[i]; j++)
            printf("*");
    }
}