#include <stdio.h>

int main()
{
    long int numero;
    int i=0, digito, soma=0, multiplo_de_10=10, checksum_digit;
    printf("Insira um EAN-13 (sem checksum): ");
    scanf("%ld", &numero);
    while(numero>0)
    {
        digito = numero%10;
        numero = numero/10;
        if(i%2) soma+=digito;
        else soma+=digito*3;
        i++;
    }
    for(i=1; multiplo_de_10<soma; i++) multiplo_de_10 = 10*i;
    printf("Checksum digit = %d", multiplo_de_10-soma);
}