#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSAGENS 500
#define MAX_PORTICOS 100
#define MAX_STR 100

typedef struct {
    char nome[MAX_STR];
    float valor;
} portico;

typedef struct {
    char matricula[MAX_STR];
    portico prt;
    int hor;
    int min;
} passagem;

/****************************************************/
/*              Funcoes a implementar               */
/****************************************************/

int filtra_matricula(passagem registos[], int nPassagens, char *matricula, passagem resultado[]) 
{
    /* problema 3.1 */
    int i, j, contPass=0;
    passagem temp;

    for(i=0; i<nPassagens; i++) {
        if(strcmp(registos[i].matricula, matricula)==0) {
            resultado[contPass++]=registos[i];
        }
    }

    for(i=0; i<nPassagens; i++) {
        for(j=i; j>0; j--) {
            if(resultado[j].prt.valor>resultado[j-1].prt.valor) {
                temp=resultado[j];
                resultado[j]=resultado[j-1];
                resultado[j-1]=temp;
            }
        }
    }

    return contPass;
}

/****************************************************/

float determinaTotais(passagem registos[], int nPassagens, char *nomeTabela)
{
    // problema 3.2
    if(nomeTabela==NULL) return 0;

    int i, j, nPorticos=0;
    float total=0;
    portico porticos[MAX_PORTICOS];

    for(i=0; i<nPassagens; i++) {
        for(j=0; j<nPorticos; j++) {
            if(strcmp(registos[i].prt.nome, porticos[j].nome)==0) {
                porticos[j].valor+=registos[i].prt.valor;
                break;
            }
        }
        if(j==nPorticos) {
            porticos[nPorticos++]=registos[i].prt;
        }
    }
    
    puts(nomeTabela);
    for(i=0; i<nPorticos; i++) {
        printf("%s - %.1f\n", porticos[i].nome, porticos[i].valor);
        total+=porticos[i].valor;
    }

    return total;
}

/****************************************************/
/*     Funcoes ja implementadas (nao modificar)     */
/****************************************************/

int ler(char *filename, passagem registos[]);

void listar(passagem registos[], int n);

void imprimir(passagem p);

int main(){
    passagem registos[MAX_PASSAGENS], resultado[MAX_PASSAGENS];
    char *matricula = "34-56-RI";
    int n, nRes;

	n = ler("porticos.txt", registos);
	/*printf("\n*** Passagens (%d) ***\n", n);
	listar(registos, n);
	printf("\n");*/

/****************************************************/
    nRes = filtra_matricula(registos, n, matricula, resultado);
	printf("\n*** Passagens de %s (%d) ***\n", matricula, nRes);
	listar(resultado, nRes);
	printf("\n");
/****************************************************/
    printf("Total de %.1f euros\n", determinaTotais(registos, n, "*** Totais de cada portico ***"));
	printf("\n\n");
/****************************************************/

    return 0;
}

int ler(char *filename, passagem registos[]){
	FILE * f;
	int nPorticos = 0, nPassagens = 0, i;
    char str[1000];
    portico porticos[MAX_PORTICOS];

    f = fopen(filename, "r");
    if(f == NULL)
		return 0;

    /* ler porticos */
    while(nPorticos < MAX_PORTICOS && fgets(str, 1000, f) != NULL)
    {
        if(strcmp(str, "fim_porticos\n") == 0)
            break;
        
        strcpy(porticos[nPorticos].nome, strtok(str, " "));
        porticos[nPorticos].valor = atof(strtok(NULL, " "));
        nPorticos++;
    }

    /* ler passagens */
    while(nPassagens < MAX_PASSAGENS && fgets(str, 1000, f) != NULL)
    {
        if(strcmp(str, "fim_passagens") == 0)
            break;

        strcpy(registos[nPassagens].matricula, strtok(str, " "));
        strcpy(registos[nPassagens].prt.nome, strtok(NULL, " "));
        registos[nPassagens].hor = atoi(strtok(NULL, " "));
        registos[nPassagens].min = atoi(strtok(NULL, " "));

        /* procura valor */
        for(int i=0; i<nPorticos; i++)
            if(strcmp(registos[nPassagens].prt.nome, porticos[i].nome) == 0)
            {
                registos[nPassagens].prt.valor = porticos[i].valor;
                break;
            }

        nPassagens++;
    }
    fclose(f);

    return nPassagens;
}

void listar(passagem registos[], int n){
    int i, j;
    
    for(i=0; i<3 && i<n; i++){
        imprimir(registos[i]);
    }
    if(n > 3)
    {
        if(n > 6)
            puts("...");
        j = i;
        if(n-3 > j)
            j = n-3;
        for (i=j; i<n; i++){
            imprimir(registos[i]);
        }
    }
}

void imprimir(passagem p){
    printf("%s - %s, %.1f, ", p.matricula, p.prt.nome, p.prt.valor);
    printf("%02d:%02d \n", p.hor, p.min);
}