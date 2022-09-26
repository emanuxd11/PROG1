#include <stdio.h>
int main()
{
    int i, ano, tiragem, exemplares_vendidos, ano_min, ano_dif_max, diferenca, tiragem_min=__INT_MAX__, diferenca_max=-1;
    for(i=0; i<20; i++)
    {
        scanf("%d %d %d", &ano, &tiragem, &exemplares_vendidos);
        diferenca = tiragem-exemplares_vendidos;
        if(tiragem<tiragem_min)
        {
            tiragem_min=tiragem;
            ano_min=ano;
        }
        if(diferenca>diferenca_max)
        {
            diferenca_max=diferenca;
            ano_dif_max=ano;
        }
    }
    printf("Ano em que foram produzidos menos exemplares: %d\nAno em que a diferença entre produzidos e vendidos foi maior: %d", ano_min, ano_dif_max);
}