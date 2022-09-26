#include <stdio.h>

int main()
{
    int id, tempoTotal=0, tempoMedio, nEncomendas=0;
    char zona;
    float totalUverits=0, totalBlovo=0;

    while(scanf("%d %c", &id, &zona) == 2)
    {
        switch (zona)
        {
        case 'A':
            tempoTotal += 21;
            totalBlovo += 3.5;
            break;
        case 'B':
            tempoTotal += 24;
            totalBlovo += 4.25;
            break;
        case 'C':
            tempoTotal += 15;
            totalUverits += 3.25;
            break;
        case 'D':
            tempoTotal += 23;
            totalUverits += 3.5;
            break;
        case 'E':
            tempoTotal += 24;
            totalBlovo += 4;
            break;
        }
        nEncomendas++;
    }

    printf("Custo total na uverits: %.2f\n", totalUverits);
    printf("Custo total na blovo: %.2f\n", totalBlovo);
    tempoMedio = tempoTotal*60.0/nEncomendas;
    printf("Tempo médio das entregas: %d minutos e %d segundos\n", tempoMedio/60, tempoMedio%60);
}