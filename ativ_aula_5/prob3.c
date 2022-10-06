#include <stdio.h>

float f(float a, float x);

int main()
{
    double a, lim_inf, lim_sup, incremento, x;
    printf("Insira o valor de a: ");
    scanf("%lf", &a);
    printf("Insira o intervalo: ");
    scanf("%lf %lf", &lim_inf, &lim_sup);
    printf("Insira o incremento: ");
    scanf("%lf", &incremento);

    if(lim_sup<lim_inf)
    {
        lim_sup+=lim_inf,
        lim_inf=lim_sup-lim_inf;
        lim_sup-=lim_inf;
    }

    for(x=lim_inf; x<=lim_sup; x+=incremento)
    {
        printf("f(%.1lf)=%.1lf\n", x, f(a, x));
    }
}

float f(float a, float x)
{
    return a*x*x;
}