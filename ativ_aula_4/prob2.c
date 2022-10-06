#include <stdio.h>

int main()
{
    char caracter;
    int numero_linhas, numero_colunas, i, j;
    printf("Insira o caracter a utilizar: ");
    scanf("%c", &caracter);
    printf("Insira o numero de linhas do retangulo: ");
    scanf("%d", &numero_linhas);
    printf("Insira o numero de colunas do retangulo: ");
    scanf("%d", &numero_colunas);

    for(i=1; i<=numero_linhas; i++)
    {
        for(j=1; j<=numero_colunas; j++)
        {
            if((i==1 || i==numero_linhas) || (j==1 || j==numero_colunas)) printf("%c", caracter);
            else printf(" "); 
        }
        printf("\n");
    }
}