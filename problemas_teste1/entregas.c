#include <stdio.h>

int main()
{
    int i, numero_encomenda, tempo_total=0;
    float total_blovo=0, total_uverits=0, tempo_medio;
    char zona;

    for(i=1; scanf("%d %c", &numero_encomenda, &zona)==2; i++)
    {
        switch(zona)
        {
            case 'A': printf("\nEncomenda %d - blovo", i);
            total_blovo+=3.5;
            tempo_total+=21;
            break;
            case 'B': printf("\nEncomenda %d - blovo", i);
            total_blovo+=4.25;
            tempo_total+=24;
            break;
            case 'C': printf("\nEncomenda %d - uverits", i);
            total_uverits+=3.25;
            tempo_total+=15;
            break;
            case 'D': printf("\nEncomenda %d - uverits", i);
            total_uverits+=3.5;
            tempo_total+=23;
            break;
            case 'E': printf("\nEncomenda %d - blovo", i);
            total_blovo+=4.0;
            tempo_total+=24;
            break;
        }
    }
    tempo_medio=(float)tempo_total/(i-1);
    printf("\n\nCusto total na uverits: %.2f euros\nCusto total na blovo: %.2f euros", total_uverits, total_blovo);
    printf("\nTempo médio das entregas: %d minutos e %.0f segundos\n", (int)tempo_medio, (tempo_medio-(int)tempo_medio)*60);
}