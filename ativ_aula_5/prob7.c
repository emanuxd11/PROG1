#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double alea()
{
    return (double)rand()/RAND_MAX;
}

int main()
{
    int M=0, N, i;
    double x, y;
    printf("Insira o numero de pontos: ");
    scanf("%d", &N);
    srand(time(NULL));
    for(i=0; i<N; i++)
    {
        x = alea();
        y = alea();
        if(x*x + y*y < 1)
        {
            M++;
        }            
        printf("\npi = %f", (double)4*M/N);

    }
}