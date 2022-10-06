#include <stdio.h>
#include <string.h>
#define TAM 1000

void inverte(char *strOriginal, char *strInvertida);

int main() {
    char string[TAM], stringInv[TAM];
    printf("Insira uma frase: ");
    fgets(string, TAM, stdin);
    *strchr(string, '\n')='\0';
    inverte(string, stringInv);
    printf("Frase invertida: %s", stringInv);
}

void inverte(char *strOriginal, char *strInvertida) {
    int i, j;
    for(i=0, j=strlen(strOriginal)-1; j>=0; i++, j--) {
        strInvertida[i]=strOriginal[j];   
    }
    strInvertida[i]='\0';
}