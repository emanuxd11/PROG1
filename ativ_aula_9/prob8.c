#include <stdio.h>
#include <string.h>
#define MAX 100

int conta(char *frase, char *palavra);

int main() {
    char frase[MAX], palavra[MAX];
    while(1) {
        printf("\nInsira uma frase: ");
        fgets(frase, MAX, stdin);
        *strchr(frase, '\n')='\0';
        if(*frase=='.') break;
        printf("Insira uma palavra: ");
        fgets(palavra, MAX, stdin);
        *strchr(palavra, '\n')='\0';
        printf("palavra = %s e strlen(palavra) = %ld\n", palavra, strlen(palavra));
        printf("Encontrou %d vezes!\n", conta(frase, palavra));
    }
}

int conta(char *frase, char *palavra) {
    int i, j, cont=0;
    for(i=0; i<strlen(frase); i++) {
        for(j=0; j<strlen(palavra); j++) {
            printf("%c = %c ?", frase[i+j], palavra[j]);
            if(frase[i+j]!=palavra[j]) break;
        }
        if(j==strlen(palavra)) cont++;
    }
    return cont;
}