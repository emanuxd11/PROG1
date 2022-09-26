#include <stdio.h>

#define N_PILOTOS 60

/****************************************************/
/*              Funcoes a implementar               */
/****************************************************/

int ler_voos(float horas[])
{
    /* problema 2.1 */
    int i=0, idpiloto;
    while(scanf("%d", &idpiloto)==1 && i<N_PILOTOS) {
        if(idpiloto>0 && idpiloto<=N_PILOTOS) {
            scanf("%f", &horas[idpiloto]);
            i++;
        }
    }
    
    return i;
}

/****************************************************/

float processa_voos(float horas[], int pilotos[], int *nPilotos)
{
    /* problema 2.2 */
    int i=0, nVoos=0, subMedia=0;
    float totHoras=0, media;
    
    for(i=1; i<=N_PILOTOS; i++) {
        if(horas[i]>0) {
            totHoras+=horas[i];
            nVoos++;
        }
    }

    media=totHoras/nVoos;

    for(i=1; i<=N_PILOTOS; i++) {
        if(horas[i]<media && horas[i]>0) {
            pilotos[subMedia++]=i;
        }
    }

    *nPilotos=subMedia;

    return media;
}

/****************************************************/
/*     Funcoes ja implementadas (nao modificar)     */
/****************************************************/

int main()
{
    float voos[N_PILOTOS+1] = {0}, media;
    int pilotos[N_PILOTOS], nRes=0, total, i;

/****************************************************/
    total = ler_voos(voos);
    printf("\nNumero total de pilotos com voo registado: %d\n", total);
/****************************************************/
    media = processa_voos(voos, pilotos, &nRes);
    printf("\nMedia de horas de voo: %.1f\n", media);
    printf("Pilotos com voos abaixo da media (%d):\n", nRes);
    for(i=0; i<nRes; i++)
        printf("%d ", pilotos[i]);
    printf("\n\n");
/****************************************************/

    return 0;
}