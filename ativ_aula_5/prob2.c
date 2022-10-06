#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int numero_lancamentos, numero_seis=0;
    printf("Insira o numero de lancamentos: ");
    scanf("%d", &numero_lancamentos);

    while(numero_lancamentos>0)
    {
        if(rand()%6+1 == 6)
        {
            numero_seis++;
        }
        numero_lancamentos--;
    }
    printf("A face com numero seis saiu %d vezes!", numero_seis);
}