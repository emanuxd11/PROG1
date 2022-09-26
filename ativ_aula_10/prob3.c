#include <stdio.h>

int proximofib() {
    static int termo_m1=1, termo_m2=0;
    int termo=termo_m1+termo_m2;
    termo_m2=termo_m1;
    termo_m1=termo;
    return termo;
}

int main() {
    int n_chamada=1;
    char op;
    do {
        printf("chamada %d -> %d\n", n_chamada++, proximofib());
        printf("Pretende continuar?(s/n) ");
        scanf(" %c", &op);
    } while(op!='n' && op!='N');
}