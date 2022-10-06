#include <stdio.h>

int main()
{
    int i, ano, nproduzidos, nvendidos, dif;
    int anoMin, prodMin;
    int anoDifMax, difMax=-1;

    for(i=0; i<20; i++)
    {
        scanf("%d %d %d", &ano, &nproduzidos, &nvendidos);
        dif = nproduzidos-nvendidos;
        printf("Diferença em %d: %d\n", ano, dif);

        if(i==0 || nproduzidos < prodMin) {
            prodMin = nproduzidos;
            anoMin = ano;
        }

        if(dif > difMax) {
            difMax = dif;
            anoDifMax = ano;
        }
    }

    printf("Ano em que foram produzidos menos exemplares: %d\n", anoMin);
    printf("Ano em a diferença entre produzidos e vendidos foi maior: %d\n", anoDifMax);
}