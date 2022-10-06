#include <stdio.h>
#include "datas.h"

int main() {
    data d, novadata;
    int salto;
    char dataextenso[100];
    printf("Insira uma data (dd/mm/yy): ");
    scanf("%d %d %d", &d.dia, &d.mes, &d.ano);
    printf("Insira o numero de dias que pretende saltar em relacao a data inserida: ");
    scanf("%d", &salto);
    novadata=somaDias(d, salto);
    escreveData(dataextenso, novadata);
    printf("%s", dataextenso);
}