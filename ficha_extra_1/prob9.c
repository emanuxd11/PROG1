#include <stdio.h>

int main()
{
    int numero, fator=2, numero_copia, soma=1, multiplo=1;
    printf("Insira um numero: ");
    scanf("%d", &numero);
    numero_copia = numero;
    printf("1 + ");
    for(; numero>1; numero%fator!=0 ? fator++ : fator)
    {
        if(numero%fator == 0)
        {
            numero = numero/fator;
            soma += fator;
            multiplo *= fator;
            if(multiplo!=numero_copia) printf("%d + ", fator);
            else if(multiplo>=numero_copia) printf("%d = %d\n", fator, soma);
        }
    }
    if(soma==numero_copia) 
        printf("O numero %d e um numero perfeito.", numero_copia);
    else 
        printf("O numero %d nao e um numero perfeito.", numero_copia);
}