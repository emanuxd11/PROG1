#include <stdio.h>
#define ARRMAX 69

typedef struct {
    int boas;
    char vski[ARRMAX];
} atuamae;

void funcaofixe(atuamae *prima) {
    printf("Insira boas: ");
    scanf("%d", &(*prima).boas); //&prima->boas
    printf("Insira vski: ");
    scanf("%s", prima->vski);
}

int main() {
    atuamae avo;
    
    funcaofixe(&avo);
    printf("%d -> %s B)", avo.boas, avo.vski);
}