#include <stdio.h>

int main()
{
    float tempo, tempo_total=0, tempo_max=-1, tempo_min=__FLT_MAX__;
    int total_minutos, total_segundos, total_ms;
    while(scanf("%f", &tempo)==1)
    {
        if(tempo>tempo_max)
        {
            tempo_max=tempo;
        }
        if(tempo<tempo_min)
        {
            tempo_min=tempo;
        }
        tempo_total+=tempo;
    }
    total_minutos=tempo_total/60.0;
    total_segundos=(tempo_total-(int)tempo_total)*60;
    total_ms=(tempo_total-(int)tempo_total)*1000;
    printf("\n\nTempo minimo de enchimento: %.2fs\nTempo maximo de enchimento: %.2fs", tempo_min, tempo_max);
    printf("\nTempo total: %dminutos, %d segundos e %d milesimos", total_minutos, total_segundos, total_ms);
}