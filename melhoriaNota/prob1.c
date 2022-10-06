#include <stdio.h>
#include <string.h>
#define MAXPED 100

int main() {   
    char bebida;
    int quantidade, i=0, totalCaf=0, totalLeite=0;
    float receita=0;

    while(scanf(" %c %d", &bebida, &quantidade)==2 && i<MAXPED) {
        printf("%d\n", i);
        if(bebida=='C') {
            totalCaf+=quantidade;
            receita+=quantidade*0.65;
        } else if (bebida=='L') {
            totalLeite+=quantidade;
            receita+=quantidade*0.50;
        }
        i++;
    }

    printf("Receita total foi de %.2f euros.\n", receita);
    printf("Foram pedidos %d cafes e %d leites.\n", totalCaf, totalLeite);
    if(totalCaf>totalLeite) {
        printf("A bebida preferida dos clientes e' cafe.");
    } else if(totalCaf<totalLeite) {
        printf("A bebida preferida dos clientes e' cafe.");
    } else {
        printf("Os clientes bebem tanto cafe' como leite.");
    }
}