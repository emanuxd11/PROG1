#include <stdio.h>
#include <string.h>
#define MAX 500

int palavras(char *str, char vet_palavras[][MAX]);  //devolve vetor de strings com as palavras e o número de palavras da frase
char *palavra_maior(char vet_palavras[][MAX], int num_palavras);
float tam_medio_palavra(char vet_palavras[][MAX], int num_palavras);

int main() {
    char frase[MAX], nletras[MAX], vet_palavras[MAX][MAX];
    int n_palavras;
    printf("Insira uma frase: ");
    fgets(frase, MAX, stdin);
    *strchr(frase, '\n')='\0';
    n_palavras=palavras(frase, vet_palavras);
    printf("A frase tem %d palavra%c\n", n_palavras, n_palavras!=1 ? 's' : ' ');
    printf("A maior palavra da frase e: %s\n", palavra_maior(vet_palavras, n_palavras));
    printf("O tamanho medio das palavras e: %.1f", tam_medio_palavra(vet_palavras, n_palavras));
}

int palavras(char *str, char vet_palavras[][MAX]) {
    int i=0, n=0, j=0, k=0;
    while(str[i]!='\0') {
        if(str[i]==' ' || str[i]=='\t' || str[i]=='\n') {
            if(i>0) {
                if(str[i-1]!=' ' && str[i-1]!='\t' && str[i-1]!='\n') {
                    n++;
                    vet_palavras[n][j++]='\0';
                    j=0;
                }
            }
        } else {
            vet_palavras[n][j++]=str[i];
        }
        i++;
    }
    if(str[0]!='\0') n++;
    return n;
}

char *palavra_maior(char vet_palavras[][MAX], int num_palavras) {
    int i, max=-1, tam_max=-1, tam;
    for(i=0; i<num_palavras; i++) {
        tam=strlen(vet_palavras[i]);
        if(tam>tam_max) {
            tam_max=tam;
            max=i;
        }
    }
    return vet_palavras[max];
}

float tam_medio_palavra(char vet_palavras[][MAX], int num_palavras) {
    int i, media=0;
    for(i=0; i<num_palavras; i++) {
        media+=strlen(vet_palavras[i]);
    }
    return media/(float)num_palavras;
}