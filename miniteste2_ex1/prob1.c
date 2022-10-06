#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TSIZE 50
#define MAXATLETAS 36
#define DISTMAX 10.0
#define DESCONTO 7.0

/****************************************************/
/*              Funcoes a implementar               */
/****************************************************/

/* Guarda nomes completos dos atletas no vetor de strings nomes e as suas 
 * pontuacoes na mesma posicao no vetor distancia.
 * Retorna o numero de atletas lidos.
 * Nota: a informacao da origem e’ lida, mas nao guardada. 
 */
/*int lerAtletas(char nomes[][TSIZE], float distancia[]){
    int i=0;
    char origem[TSIZE], nome1[TSIZE], nome2[TSIZE];

    while(scanf(" %s %s", origem, nome1)==2 && i<MAXATLETAS) {
        strcpy(nomes[i], nome1);
        if(strcmp(origem, "Galia")) { 
            strcat(nomes[i], " ");
            scanf(" %s", nome1);
            strcat(nomes[i], nome1);
        }
        scanf(" %f", &distancia[i]);
        i++;
    }

	return i;
}*/

int lerAtletas(char nomes[][TSIZE], float distancia[]){
    //outra solução para a 1.1, sugestão do monitor na aula prática
    int i=0;
    char linha[TSIZE], *origem;
    while(fgets(linha, TSIZE, stdin)!=NULL && i<MAXATLETAS) {
        origem=strtok(linha, "\t");
        strcpy(nomes[i], strtok(NULL, "\t"));
        distancia[i]=atof(strtok(NULL, "\n"));
        i++;
    }
	return i;
}

/* Identifica quais sao os atletas romanos infratores (>10m) e 
 * penaliza em 7 metros a distancia desses atletas.
 * Retorna numero de correcoes feitas.
 */
int corrigeTabela(char nomes[][TSIZE], float distancia[], int nAtleta){
    int i, nomesCorrigidos=0, len;
    for(i=0; i<nAtleta; i++) {
        len=strlen(nomes[i]);
        if(nomes[i][len-2]=='u' && nomes[i][len-1]=='s' && distancia[i]>10) {
            distancia[i]-=7.0;
            nomesCorrigidos++;
        }
    }
	return nomesCorrigidos;
}

/****************************************************/
/*     Funcoes ja implementadas (nao modificar)     */
/****************************************************/
 
void imprimePontuacoes(float distancias[], int n);

int main() {
	char nomes[MAXATLETAS][TSIZE];
	float distancias[MAXATLETAS];
	int nAtletas, nCorrigidos;

	nAtletas = lerAtletas(nomes, distancias);
	printf("Numero de atletas lidos: %d\n", nAtletas);

	nCorrigidos = corrigeTabela(nomes, distancias, nAtletas);
	printf("Numero de valores corrigidos: %d\n", nCorrigidos);
	printf("Vetor corrigido:\n");
	imprimePontuacoes(distancias, nAtletas);

	return 0;
}

void imprimePontuacoes(float distancias[], int n){
	int i=0;
	for(; i<n; i++){
		if( (2*i+1) == MAXATLETAS)
			printf("\n");
		printf("%2.1f ", distancias[i] );
	}
}