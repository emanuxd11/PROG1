#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXT 10
#define TSIZE 12
#define NSIZE 50

int lerEquipas(char nomes[][TSIZE], int totalPontos[]) {
    char nomeTemp[NSIZE];
    int pontosTemp, i=0, j;

    while(scanf("%s %s %s %d", nomeTemp, nomeTemp, nomeTemp, &pontosTemp)==4) {
        for(j=0; j<i; j++) {
            //verifica se o nome já foi inserido
            if(strcmp(nomeTemp, nomes[j])==0) {
                //caso já tenha sido inserido
                //incrementa os pontos e passa
                //para o próximo ciclo
                totalPontos[j]+=pontosTemp;
                break;
            }
        }
        if(i==j) {
            //caso ainda não tenha sido
            //inserido, guarda o nome em 
            //nomes[i] e os pontos em totalPontos[i];
            if(i+1>MAXT) return i;
            //se o próximo índice do ciclo for
            //maior que MAXT, a função acaba, 
            //pois significa que está prestes
            //a ler uma equipa a mais do 
            //limite máximo suportado
            strcpy(nomes[i], nomeTemp);
            totalPontos[i]=pontosTemp;
            i++;
        }
    }
    return i;
}

int melhorPontuacao(int pontos[], int n) {
    int max=-1, i, imax;
    for(i=0; i<n; i++) {
        if(pontos[i]>max) {
            imax=i;
            max=pontos[i];
        }
    }    
    return imax; 
}

int main() {
    int nequipas, mequipa;
    char equipas[MAXT][TSIZE]={0};
    int pontosEquipas[MAXT]={0};

    nequipas = lerEquipas(equipas, pontosEquipas);
    printf("Total de equipas: %d\n", nequipas);

    mequipa = melhorPontuacao(pontosEquipas, nequipas);
    printf("Equipa com maior pontuacao: %s (%d pontos)\n", equipas[mequipa], pontosEquipas[mequipa]);
}