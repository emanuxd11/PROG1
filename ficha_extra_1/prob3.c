#include <stdio.h>

int main()
{
    int l1c1, l1c2, l1c3, l2c1, l2c2, l2c3, l3c1, l3c2, l3c3, coluna1, coluna2, coluna3, diag_principal;
    printf("Primeira linha: ");
    scanf("%d %d %d", &l1c1, &l1c2, &l1c3);
    printf("Segunda linha: ");
    scanf("%d %d %d", &l2c1, &l2c2, &l2c3);
    printf("Terceira linha: ");
    scanf("%d %d %d", &l3c1, &l3c2, &l3c3);

    coluna1 = l1c1+l2c1+l3c1;
    coluna2 = l2c1+l2c2+l2c3;
    coluna3 = l3c1+l3c2+l3c3;
    diag_principal = l1c1+l2c2+l3c3;

    printf("\nQuadrado: \n|%d|%d|%d|\n|%d|%d|%d|\n|%d|%d|%d|\n\n", l1c1, l1c2, l1c3, l2c1, l2c2, l2c3, l3c1, l3c2, l3c3);

    if(coluna1 == coluna2 && coluna2 == coluna3 && coluna3 == diag_principal)
        printf("E um quadrado magico com a soma: %d\n", diag_principal);
    else
        printf("Nao e um quadrado magico.\n");
}