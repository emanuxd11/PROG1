//só com 30 lançamentos
#include <stdio.h>
#include <stdlib.h>
#include <time.h>  
#define LANCA 30

int resultado();

int main()
{
    int j, i, resultados[LANCA];
    srand(time(NULL));
    printf("Histograma correspondente a %d lancamentos: ", LANCA);
    for(i=0; i<LANCA; i++)
    {   
        printf("\n%d - ", i+1);
        resultados[i] = 1+rand()%6;
        for(j=0; j<resultados[i]; j++)
            printf("*");
    }
}