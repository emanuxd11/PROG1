#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXFILMES 4000
#define TSIZE 150
#define CSIZE 30
#define MAXPAISES 20
#define DECADA_PESQUISA 1970
#define PAIS_PESQUISA "Poland"

typedef struct {
    unsigned int id;
    char titulo[TSIZE];
    char origem[MAXPAISES][CSIZE];
    unsigned int ano, duracao;
} filme;

/****************************************************/
/*              Funcoes a implementar               */
/****************************************************/

int maisLongo(filme catalogo[], int n) {
    /* problema 2.1 */
    int i, max=0, imax=0;
    for(i=0; i<n; i++) {
        if(catalogo[i].duracao>max) {
            max=catalogo[i].duracao;
            imax=i;
        }
    }
    return imax;
}

int listaDecada(filme catalogo[], int n, int decada) {
    /* problema 2.2 */
    int i, cont=0, anofilmes[10]={0};
    FILE *f;
    f=fopen("infodecada.txt", "w");

    for(i=0; i<n; i++) {
        if(catalogo[i].ano>=decada && catalogo[i].ano<decada+10) {
            cont++;
            anofilmes[catalogo[i].ano-decada]++;
        }
    }

    fprintf(f, "Informacao da decada %d (total = %d filmes)\n", decada, cont);
    for(i=0; i<10; i++) {
        fprintf(f, "%d - %d\n", decada+i, anofilmes[i]); //guarda no ficheiro infodecada.txt as informações
        printf("%d - %d\n", decada+i, anofilmes[i]); //printf no terminal só para poder visualizar sem ter de abrir o ficheiro
    }
    
    fclose(f);

    if(cont>0) return cont;
    return -1;
}

int pesquisaPorPais(filme catalogo[], int n, char *pais, filme resultado[]) {
    /* problema 2.3 */
    int i, j, nfilmes=0;
    filme aux;

    for(i=0; i<n; i++) {
        for(j=0; j<MAXPAISES; j++) {
            if(strcmp(catalogo[i].origem[j], pais)==0) {
                resultado[nfilmes++]=catalogo[i];
                //printf("%s\n", catalogo[i].origem[j]);
                break;
            }
        }
    }

    for(i=0; i<nfilmes; i++) {
        for(j=i; j>0; j--) {
            if(resultado[j].duracao>resultado[j-1].duracao) {
                aux=resultado[j];
                resultado[j]=resultado[j-1];
                resultado[j-1]=aux;
            }
        }
    }
    
    return nfilmes;
}

/****************************************************/
/*     Funcoes ja implementadas (nao modificar)     */
/****************************************************/ 

int ler(char *filename, filme catalogo[]);

void listar(filme catalogo[], int n);

void imprimir(filme f);

int main(){
    filme catalogo[MAXFILMES] = {0}, resultado[MAXFILMES];
	int nfilmes, nres, duracao;
    int posMax;

	nfilmes = ler("catalogo.txt", catalogo);
	/*printf("\n*** Filmes (%d) ***\n", nfilmes);
	listar(catalogo, nfilmes);
	printf("\n");*/

    posMax = maisLongo(catalogo, nfilmes);
    if(posMax != -1)
    {    
        printf("\n*** Filme mais longo (duracao %d minutos) ***\n\n", catalogo[posMax].duracao);
        imprimir(catalogo[posMax]);
    }
    else
    	printf("\n*** Filme mais longo (duracao -- minutos) ***\n\n---");    
	printf("\n");

    printf("\nInformacao da decada %d (total = %d filmes)\n", DECADA_PESQUISA, listaDecada(catalogo, nfilmes, DECADA_PESQUISA));
	printf("\n");

	nres = pesquisaPorPais(catalogo, nfilmes, PAIS_PESQUISA, resultado);
	printf("\n*** Filmes com origem %s (%d) ***\n\n", PAIS_PESQUISA, nres);
    listar(resultado, nres);
	printf("\n");

	return 0;
}

int ler(char *filename, filme catalogo[]){
	FILE * f;
	int n = 0;
    char linha[1000];
    char paises[MAXPAISES*CSIZE];

    f = fopen(filename, "r");
    if(f == NULL)
		return 0;

	while((n < MAXFILMES) && fgets(linha, 1000, f) != NULL){
        linha[strlen(linha)-1]='\0';
        catalogo[n].id = atoi(strtok(linha, "\t"));
        strcpy(catalogo[n].titulo, strtok(NULL, "\t"));
        strcpy(paises, strtok(NULL, "\t"));
        catalogo[n].ano = atoi(strtok(NULL, "\t"));
        catalogo[n].duracao = atoi(strtok(NULL, "\t"));
        
        int npaises=0;
        char *pais;
        strcpy(catalogo[n].origem[0], strtok(paises, ","));
        while((pais = strtok(NULL, ",")) != NULL)
            strcpy(catalogo[n].origem[npaises++], pais+1);
        n++;
    }

    fclose(f);
    return n;
}

void listar(filme catalogo[], int n){
    int i, j;
    
    for(i=0; i<3 && i<n; i++){
        imprimir(catalogo[i]);
    }
    if(n > 3)
    {
        if(n > 6)
            puts("...");
        j = i;
        if(n-3 > j)
            j = n-3;
        for (i=j; i<n; i++){
            imprimir(catalogo[i]);
        }
    }
}

void imprimir(filme f){
    int i=1;
    printf("%d - %s ", f.id, f.titulo);
    printf("| %s", f.origem[0]);
    while(strlen(f.origem[i]) != 0)
    {
        printf(", %s", f.origem[i]);
        i++;
    }
    printf(" | %d | %d\n", f.ano, f.duracao);
}