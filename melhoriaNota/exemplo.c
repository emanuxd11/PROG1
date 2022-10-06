#include <stdio.h>
#include <string.h>
#include <ctype.h>

int contaAlg(char *frase) {
    int i=0, alga=0;
    while(frase[i++]!='\0') {
        if(isdigit(frase[i])) {
            alga++;
        }
    }
    return alga;
}

int main() {
    char resultado[100]="";
    char frase[]="Boas pessoal, eu sou o Tiagovski555 e sou um azeiteiro do crl!!!";
    sprintf(resultado, "A frase tem %d algarismos", contaAlg(frase));
    puts(resultado);
}