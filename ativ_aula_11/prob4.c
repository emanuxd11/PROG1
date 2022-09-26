#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NMAX 100
#define DMAX 31
#define TMAX 15

typedef struct {
    char nome[NMAX];
    int ativos[DMAX];
} tarefas;

int leTarefas(tarefas tarefa[], char *filename) {
    int i=0, j;
    char linha[NMAX], *nome;
    FILE *f;
    f=fopen(filename, "r");

    while(fgets(linha, NMAX, f)!=NULL && i<TMAX) {
        strcpy(tarefa[i].nome, strtok(linha, " "));
        for(j=0; j<DMAX; j++) {
            tarefa[i].ativos[j]=atoi(strtok(NULL, " "));
            if(tarefa[i].ativos[j]==-1) break;
        }
        i++;
    }
    
    fclose(f);
    return i;
}

int dMaxTaref(tarefas tarefa[], int n) {
    int dia, nTarefa, max=-1, diaMax=0;
    int tarefasDia[DMAX]={0};

    for(nTarefa=0; nTarefa<n; nTarefa++) {
        for(dia=0; dia<DMAX; dia++) {

            if(tarefa[nTarefa].ativos[dia]==-1) {
                break;
            } else if(tarefa[nTarefa].ativos[dia]!=0) {
                tarefasDia[dia]++;
            }

            if(tarefasDia[dia]>max) {
                max=tarefasDia[dia];
                diaMax=dia+1;
            }
        }
    }

    return diaMax;
}

int maxTermin(tarefas tarefa[], int n) {
    int dia, nTarefa, max=-1, diaMax=0;
    int tarefasAcabadas[DMAX]={0};

    for(nTarefa=0; nTarefa<n; nTarefa++) {
        for(dia=0; dia<DMAX; dia++) {

            if(tarefa[nTarefa].ativos[dia]==-1) {
                break;
            } else if(tarefa[nTarefa].ativos[dia+1]==-1) {
                tarefasAcabadas[dia]++;
            }

            if(tarefasAcabadas[dia]>max) {
                max=tarefasAcabadas[dia];
                diaMax=dia+1;   
            }
        }   
    }

    return diaMax;
}

int trabMax(tarefas tarefa[], int n) {
    int dia, nTarefa, max=-1, tMax=0;
    int nTrab[DMAX]={0};

    for(nTarefa=0; nTarefa<n; nTarefa++) {
        
        for(dia=0; dia<DMAX; dia++) {
            if(tarefa[nTarefa].ativos[dia]==-1) {
                break;
            }
            nTrab[nTarefa]+=tarefa[nTarefa].ativos[dia];         
        }

        if(nTrab[nTarefa]>max) {
            max=nTrab[nTarefa];
            tMax=nTarefa;
        }
    }

    return tMax;
}

int main() {
    int nTarefas, diaMax, diaTermin, maxOcup;
    tarefas tarefa[TMAX];
    
    nTarefas=leTarefas(tarefa, "tarefas.txt");
    diaMax=dMaxTaref(tarefa, nTarefas);
    printf("\nDia com mais tarefas: %d\n", diaMax);
    diaTermin=maxTermin(tarefa, nTarefas);
    printf("Dia com mais tarefas concluidas: %d\n", diaTermin);
    maxOcup=trabMax(tarefa, nTarefas);
    printf("Tarefa que ocupou mais trabalhadores: %s\n", tarefa[maxOcup].nome);
}