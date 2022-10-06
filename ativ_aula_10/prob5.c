#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_MAX 100

typedef struct {
    char desig[TAM_MAX], marca[TAM_MAX], modelo[TAM_MAX];
    float preco;
    int stock; 
} artigo;

int leArtigos(artigo armazem[], char *nomeFicheiro) {
    int i=0;
    FILE *f;
    f=fopen(nomeFicheiro, "r");
    do {
        fscanf(f, "%s %s %s %f %d", armazem[i].desig, armazem[i].marca, armazem[i].modelo, &armazem[i].preco, &armazem[i].stock);
        i++;
    } while(!feof(f));
    fclose(f);
    return i;
}

int totalArtigos(artigo armazem[], int n, char *marca, char *modelo) { //n é suposto ser o número de total de artigos, certo?
if(n<=0 || n>TAM_MAX) {
        puts("Erro, tamanho inválido!");
        return -1;
    }
    int i;
    for(i=0; i<n; i++) {
        if(strstr(armazem[i].marca, marca)!=NULL && strstr(armazem[i].modelo, modelo)!=NULL) {
            return armazem[i].stock;
        }
    }
}

void alertaArtigos(artigo armazem[], int n) {
    if(n<=0 || n>TAM_MAX) {
        puts("Erro, tamanho inválido!");
        return;
    }
    int i;
    puts("-------------------------------------------------------------");
    puts("Atencao! Há poucos exemplares em stock dos seguintes artigos:\n");
    for(i=0; i<n; i++) {
        if(armazem[i].stock<10) {
            printf("%s %s %s --> %d unidades em stock\n", armazem[i].desig, armazem[i].marca, armazem[i].modelo, armazem[i].stock);
        }
    }
    puts("-------------------------------------------------------------");
}

void ordenaArtigos(artigo armazem[], int n/*, char *nomeFicheiro*/) { //alterar para que modifique o próprio ficheiro
    if(n<=0 || n>TAM_MAX) {
        puts("Erro, tamanho inválido!");
        return;
    }
    int i, j;
    artigo aux;
    for(i=0; i<n; i++) {
        for(j=i; j>0; j--) {
            if(armazem[j].stock<armazem[j-1].stock) {
                aux=armazem[j];
                armazem[j]=armazem[j-1];
                armazem[j-1]=aux;
            }
        }
    }
    for(i=0; i<n; i++) {
        printf("%s %s %s %.2f %d\n", armazem[i].desig, armazem[i].marca, armazem[i].modelo, armazem[i].preco, armazem[i].stock);
    }
}

int main() {
    artigo armazem[TAM_MAX];
    int i, n=leArtigos(armazem, "artigos.txt");

    //printf("Há %d exemplares do modelo desejado\n\n", totalArtigos(armazem, n, "SuperTV", "S-30"));

    alertaArtigos(armazem, n);
    ordenaArtigos(armazem, n);

    /*printf("leu %d artigos\n", n);
    for(i=0; i<n; i++) {
        printf("%s %s %s %.2f %d\n", armazem[i].desig, armazem[i].marca, armazem[i].modelo, armazem[i].preco, armazem[i].stock);
    }*/
}