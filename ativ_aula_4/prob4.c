#include <stdio.h>

int main()
{
    int numero, digito, numero_invertido=0;

    printf("Insira um numero inteiro: ");
    scanf("%d", &numero);
    for(; numero>0; numero = numero/10)
        numero_invertido = numero_invertido*10 + numero%10;
    printf("O numero que inseiru, com os digitos invertidos, fica: %d", numero_invertido);
}