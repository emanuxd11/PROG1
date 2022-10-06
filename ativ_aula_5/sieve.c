#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int* lista;
    int limite, i, j=2, k, alberto_contador=0;
    char op;
    
    clock_t tic = clock();

    printf("Calcular numeros primos até: ");
    scanf("%d", &limite);
    printf("Pretende visualizar a lista (s/n)? ");
    scanf(" %c", &op);

    lista = (int*)malloc(limite * sizeof(int));

    for(i=2; i<=limite; i++)
    {
        lista[i] = 1;
    }
    for(i=2; i*i<=limite; i++)
    {
        if(lista[i])
        {    
            for(j=i*i; j<=limite; j+=i) lista[j]=0;
        }
    }
    //printf("Todos os numeros primos de 2 a %d sao: ", limite);
    for(i=2; i<=limite; i++)
    {
        if(lista[i])
        {
            op == 's' ? printf("%d ", i) : 1; 
            alberto_contador++;
        }
    }

    clock_t toc = clock();
    printf("\nForam encontrados %d numeros primos em %.2lf segundos!\n", alberto_contador, (double)(toc - tic) / CLOCKS_PER_SEC);
}