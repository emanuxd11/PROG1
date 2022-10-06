#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int aleatorio_entre(int limite_inferior, int limite_superior);

int main()
{
    srand(time(NULL));
    int numero_lancamentos, numero_seis=0;
    printf("Insira o numero de lancamentos: ");
    scanf("%d", &numero_lancamentos);

    while(numero_lancamentos>0)
    {
        if(aleatorio_entre(1, 6) == 6)
        {
            numero_seis++;
        }
        numero_lancamentos--;
    }
    printf("A face com numero seis saiu %d vezes!", numero_seis);
}

int aleatorio_entre(int limite_inferior, int limite_superior)
{
    return rand()%limite_superior+limite_inferior;
}