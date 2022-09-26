#include <stdio.h>
int main()
{
    int numero, numero_copia, numero_invertido=0, digito, cont_digitos=0, i, pot_digito=1, soma_pot_digitos=0, cont=0; //infinitas variáveis, que merda 
    printf("Insira um numero: ");
    scanf("%d", &numero);
    numero_copia = numero;
    for(; numero>0; numero = numero/10)
    {
        digito=numero%10;
        numero_invertido = numero_invertido*10 + digito%10;                //inverte o numero para que se possa fazer print à soma na ordem correta
        cont_digitos++;                                                    //e dá a ordem da potência
    }
    for(; numero_invertido>0; numero_invertido = numero_invertido/10)
    {
        digito = numero_invertido%10;
        pot_digito=1;
        for(i=0; i<cont_digitos; i++)                                       //calcula a potência de ordem cont_digitos de cada digito
        {
            pot_digito *= digito;
        }
        soma_pot_digitos += pot_digito;
        if(++cont<cont_digitos) 
            printf("%d^%d + ", digito, cont_digitos);                       //imprime o processo de soma
        else if(++cont>=cont_digitos)
            printf("%d^%d = %d\n",digito, cont_digitos, soma_pot_digitos);
    }
    if(soma_pot_digitos==numero_copia)                                      //resultado
        printf("O numero %d e um numero de Armstrong", numero_copia);
    else
        printf("O numero %d nao e um numero de Armstrong", numero_copia);
}