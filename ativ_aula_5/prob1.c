#include <stdio.h>

float pesoideal(float altura, char sexo);

int main()
{
    float altura;
    char sexo;
    printf("Insira a altura: ");
    scanf("%f", &altura);
    printf("Insira o sexo (M/F): ");
    scanf(" %c", &sexo);

    printf("O peso ideal para esta pessoa e de %f kg.", pesoideal(altura, sexo));
}

float pesoideal(float altura, char sexo)
{
    if(sexo == 'f' || sexo == 'F') return 62.1*altura-44.7;
    return 72.7*altura-58;
}
