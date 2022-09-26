#include <stdio.h>
#include <math.h>

int soma_binario(int A, int B);

int main()
{
    int n1, n2, a1, a2;
    printf("Insira o primeiro operando (em base 2): ");
    scanf("%d", &n1);
    printf("Insira o segundo operando (em base 2): ");
    scanf("%d", &n2);
    printf("%d + %d = %d", n1, n2, soma_binario(n1, n2));
    
}

int soma_binario(int A, int B)
{
    int c_in=0, soma=0, a, b, cont=0;
    while(A>0 || B>0)
    {
        a=A%10;
        b=B%10;
        soma += (c_in ^ a ^ b)*pow(10, cont++);
        c_in = (a & b) | (c_in & (a ^ b));
        A/=10;
        B/=10;
    }
    soma += (c_in ^ a ^ b)*pow(10, cont);
    return soma;
}