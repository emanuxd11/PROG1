#include <stdio.h>

int hoursMin(int totalMins, int *hours, int *minutes);

int main() {
    int min, horas, minutos;
    printf("Insira o total de minutos: ");
    scanf("%d", &min);
    if(hoursMin(min, &horas, &minutos)) {
        printf("%d minutos correspondem a %02dh:%02dm e e superior a 1 dia", min, horas, minutos);
    } else {
        printf("%d minutos correspondem a %02dh:%02dm e nao e superior a 1 dia", min, horas, minutos);
    }
}

int hoursMin(int totalMins, int *hours, int *minutes) {
    *hours=totalMins/60;
    *minutes=(int)((totalMins/60.0-*hours)*60);
    return totalMins>3600 ? 1 : 0;
}