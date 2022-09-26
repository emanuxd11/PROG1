#include <stdio.h>

float custo(char zona, int servico)
{
    switch(zona)
    {
    case 'A':
        if(servico == 0)
            return 5.25;
        return 3.5;
    case 'B':
        if(servico == 0)
            return 4.5;
        return 4.25;
    case 'C':
        if(servico == 0)
            return 3.25;
        return 5;
    case 'D':
        if(servico == 0)
            return 3.5;
        return 4.5;
    case 'E':
        if(servico == 0)
            return 4.75;
        return 4;
    }
    return 0;
}

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
            totalBlovo += custo(zona, 1);
            break;
        case 'B':
            tempoTotal += 24;
            totalBlovo += custo(zona, 1);
            break;
        case 'C':
            tempoTotal += 15;
            totalUverits += custo(zona, 0);
            break;
        case 'D':
            tempoTotal += 23;
            totalUverits += custo(zona, 0);
            break;
        case 'E':
            tempoTotal += 24;
            totalBlovo += custo(zona, 1);
            break;
        }
        nEncomendas++;
    }

    printf("Custo total na uverits: %.2f\n", totalUverits);
    printf("Custo total na blovo: %.2f\n", totalBlovo);
    tempoMedio = tempoTotal*60.0/nEncomendas;
    printf("Tempo médio das entregas: %d minutos e %d segundos\n", tempoMedio/60, tempoMedio%60);
}