#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXSTRING 50
#define MAXREG 1000
#define LIMITE1  35.0
#define LIMITE2  25.0
#define FICHEIRO "populacao.txt"

typedef struct{
    char nome[MAXSTRING];
    char regiao[MAXSTRING];
    float altura;
    float peso;
} pessoa;

/****************************************************/
/*              Funcoes a implementar               */
/****************************************************/

float calcPercentagem(pessoa *pv, int n, char *regiao, float limite, char *nomeTabela)
{
    /* 2.1 - Implementar esta funcao */
    int i, popregiao=0, cimalimite=0;
    float imcreg[MAXREG], percent;
    pessoa pessoaacima[MAXREG];

    for(i=0; i<n; i++) {
        if(strcmp(pv[i].regiao, regiao)==0) {
            imcreg[popregiao]=pv[i].peso/((pv[i].altura/100)*(pv[i].altura/100));
            if(imcreg[popregiao++]>limite) {
                pessoaacima[cimalimite++]=pv[i];
            }
        }
    }

    percent=(float)cimalimite/popregiao*100;

    if(nomeTabela!=NULL) {
        printf("%s: \n", nomeTabela);
        printf("%19s:%12s:\t%5s:\n", "Nome", "Altura", "Peso");
        for(i=0; i<cimalimite; i++) {
            printf("%20s %12.1f %12.1f\n", pessoaacima[i].nome, pessoaacima[i].altura, pessoaacima[i].peso);
        }
    }

    return percent;
}

/****************************************************/

float calcMediana(pessoa *pv, int n)
{
    /* 2.2 - Implementar esta funcao */
    int i, j;
    pessoa aux[MAXREG], temp;
    float mediana;

    for(i=0; i<n; i++) {
        aux[i]=pv[i];   //copia o vetor pv para um vetor auxiliar, mantendo-se inalterado pv
    }

    for(i=0; i<n; i++) {
        for(j=i; j>0; j--) {
            if(aux[j].altura<aux[j-1].altura) { //ordenar vetor por altura
                temp=aux[j];
                aux[j]=aux[j-1];
                aux[j-1]=temp;
            }
        }
    }

    for(i=0; i<n; i++) {
        printf("%.1f -- %d\n", aux[i].altura, i);
    }
    printf("n=%d\n", n);

    //se estiver ordenado por ordem crescente não dá, mas decresc. dá certo
    if(n%2==0) {
        return (aux[n/2].altura+aux[n/2-1].altura)/2;
    }
    return aux[n/2].altura;
}

/****************************************************/
/*     Funcoes ja implementadas (nao modificar)     */
/****************************************************/ 

int lerEntrada(char *ficheiro, pessoa *pv, int n);
void imprimePessoas(const pessoa v[], int n );

int main()
{
    pessoa pv[MAXREG]={0};
    int   n=0;
    float media=0.0, mediana;
    float perc[MAXREG]={0};
    char *pesquisa1 = "North West";
    char *pesquisa2 = "London";

    n = lerEntrada(FICHEIRO, pv, MAXREG);
    //printf("\nEntradas lidas=%d\n", n);
    //imprimePessoas(pv, n);

    media = calcPercentagem(pv, n, pesquisa1, LIMITE1, "North West %%");
    printf("\nPercentagem IMC>%.1f (%s) = %.0f%%\n", LIMITE1, pesquisa1, media);

    media = calcPercentagem(pv, n, pesquisa2, LIMITE2, NULL);
    printf("Percentagem IMC>%.1f (%s) = %.0f%%\n", LIMITE2, pesquisa2, media);

    mediana = calcMediana(pv, n);
    printf("\nMediana Altura = %.1f\n\n", mediana);
}

int lerEntrada(char *ficheiro, pessoa *pv, int n)
{
    FILE *f;
    const char *sep = ";";
    char *token;
    char linha[200]={0};
    int  i=0, linec=0;
    
    f = fopen(ficheiro, "r");
    if(f==NULL){
        return -1;
    }

    while(fgets(linha, sizeof(linha), f) !=NULL)
    {
        if(linec>n) {
            fclose(f);
            return -1;
        }

        token = strtok(linha, sep);
        strcpy(pv[linec].nome, token);
        token = strtok(NULL, sep);
        strcpy(pv[linec].regiao, token);
        token = strtok(NULL, sep);
        pv[linec].altura= atof(token);
        token = strtok(NULL, sep);
        pv[linec].peso= atof(token);
        linec++;
    }
    fclose(f);
    return linec;
}

void imprimePessoas(const pessoa v[], int n){
    int iter =0;
    printf("Pessoas na lista:\n");
    for(iter=0; iter<2;iter++){
        printf("%18s | %25s | %.1f | %.1f\n", \
            v[iter].nome, v[iter].regiao, v[iter].altura, v[iter].peso);
    }
    iter = n-1;
    printf("\t(...)\n%18s | %25s | %.1f | %.1f\n", \
            v[iter].nome, v[iter].regiao, v[iter].altura, v[iter].peso);
}