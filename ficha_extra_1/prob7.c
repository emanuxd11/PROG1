#include <stdio.h>

int main()
{
    int inicio, fim, soma=0, i;
    float media;

    printf("Insira o numero inicial: ");
    scanf("%d", &inicio);
    printf("Insira o numero final: ");
    scanf("%d", &fim);

    for(i=inicio; i<=fim; i++) soma+=i;
    printf("A soma de todos os numeros inteiros entre %d e %d e igual a: %d e a media e igual a: %.1f", inicio, fim, soma, (inicio+fim)/2.0);
}