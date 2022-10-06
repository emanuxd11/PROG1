#include <stdio.h>

int main()
{
    int op1, op2, j=0, i;
    printf("Insira um operando: ");
    scanf("%d", &op1);
    printf("Insira outro operando (potencia de base 2): ");
    scanf("%d", &op2);
    for(int i=2; i<=op2; i*=2) j++;
    printf("%d x %d = ", op1, op2);
    op1 = op1 << j;
    printf("%d", op1);         
}