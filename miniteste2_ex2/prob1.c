#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXSTR 50
#define MAXV 100

/****************************************************/
/*              Funcoes a implementar               */
/****************************************************/

int vabs(int x) {
    return x<0 ? -x : x;
}

int lerPalavras(char palavras[][MAXSTR])  {
    /* 1.1 - Implementar esta função */
    char temp[MAXSTR];
    int i=0;
    while(scanf("%s", temp)==1 && i<MAXV) {
        if(strlen(temp)<=6) {
            strcpy(palavras[i++], temp);
        }
    }
    return i;
}

int nL(char *string) { 
//função que devolve o comprimento de uma string sem contar espaços
    int i, length=0;
    for(i=0; i<strlen(string); i++) {
        if(string[i]!=' ' && string[i]!='\t' && string[i]!='\n' && string[i]!='\0') {
            length++;
        }
    }
    return length;
}

int nM(char *string) {
    int i, count=0;
    for(i=0; i<strlen(string); i++) {
        if(string[i]>'A' && string[i]<'Z') {
            count++;
        }
    }
    return count;
}

int calcCriterio(char nomes[][MAXSTR], int n, int CQ[]) {    
    /* 1.2 - Implementar esta função */
    int i, min=__INT_MAX__, imin=__INT_MAX__;
    //os nomes ficam diferentes dos do enunciado
    //aparentemente, como estou em linux, pode dar diferente
    for(i=0; i<n; i++) {
        CQ[i]=vabs(25-nL(nomes[i]))-nM(nomes[i]);
        //printf("%s -> %d\n", nomes[i], CQ[i]);
        if(CQ[i]<min) {
            min=CQ[i];
            imin=i;
        }
    }
    return imin;
}

/****************************************************/
/*     Funcoes ja implementadas (nao modificar)     */
/****************************************************/ 

void geraNomes(char nomes[][MAXSTR], int n, char nomeCompleto[][MAXSTR]);
void imprimeNomes(char nomes[][MAXSTR], int n);
void imprimeNomeECriterio(char nome[][MAXSTR], int criterio[], int n, int max);

int main() {
    char nomes[MAXV][MAXSTR]={0};
    char nomeCompleto[MAXV][MAXSTR]={0};
    int  criterioQ[MAXV]={0};
    int  n=0, pos;

    n = lerPalavras(nomes);
    if(n > 0)
        printf("\nExistem %d palavras (%s ate' %s)\n\n", n, nomes[0], nomes[n-1]);
    else {
        printf("\nForam lidas 0 palavras.\n\n");
        return 1;
    }
    geraNomes(nomes, 10, nomeCompleto);
    pos = calcCriterio(nomeCompleto, 5, criterioQ);
    imprimeNomeECriterio(nomeCompleto, criterioQ, 5, pos);
    printf("\n");

    return 0;
}

void geraNomes(char palavras[][MAXSTR], int n, char nomesCompletos[][MAXSTR]) {
    char nome[MAXSTR];
    int i, j;
    srand(100);

    for(i=0; i<MAXV; ){
        strcpy( nome, palavras[rand()%n] );
        strcat( nome, " " );
        strcat( nome, palavras[rand()%n] );
        for(j=0; j<i; j++)
            if(strcmp(nomesCompletos[j], nome) == 0)
                break;
        if(j==i)
            strcpy(nomesCompletos[i++], nome);
    }
}

void imprimeNomes(char nomes[][MAXSTR], int n){
    int iter=0;
    for(iter=0; iter<n; iter++)
        printf("%s\n", nomes[iter] );
}

void imprimeNomeECriterio(char nome[][MAXSTR], int criterio[], int n, int pos){
    int iter=0;
    for(iter=0; iter<n; iter++)
    {
        printf("%15s - %3d", nome[iter], criterio[iter] );
        printf(pos == iter ? " <--\n" : "\n");
    }
}