#include <stdio.h>

float custo(char zona, int servico); 

int main()
{
    int i, n_encomenda, servico, tempo_total=0;
    char zona_entrega;
    float custo_uverits=0, custo_blovo=0, tempo_medio;
    for(i=1; scanf("%d %c", &n_encomenda, &zona_entrega)==2; i++)
    {
        switch(zona_entrega)
        {
            case 'A': printf("Encomenda %d - blovo", i);
            custo_blovo += 3.5;
            tempo_total += 21;
            break;
            case 'B': printf("Encomenda %d - blovo", i);
            custo_blovo += 4.25;
            tempo_total += 24;
            break;
            case 'C': printf("Encomenda %d - uverits", i);
            custo_uverits += 3.25;
            tempo_total += 15;
            break;
            case 'D': printf("Encomenda %d - uverits", i);
            custo_uverits += 3.5;
            tempo_total += 23;
            break;
            case 'E': printf("Encomenda %d - blovo", i);
            custo_blovo += 4.0;
            tempo_total += 24;
            break;
        }
    }
    tempo_medio=tempo_total/i;
    printf("\nCusto total na uverits: %.2f\nCusto total na blovo: %.2f", custo_uverits, custo_blovo);
    printf("\nTempo medio das entregas: %d minutos e %d segundos", (int)tempo_medio, (tempo_medio-(int)tempo_medio)*60);
}

float custo(char zona, int servico)
{

}