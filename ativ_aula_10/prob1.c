#include <stdio.h>

int recfib(int n) {
    if(n<=1) return n;
    return recfib(n-1)+recfib(n-2);
}

void opt1(int i) {
    static int control;
    printf("%d ", recfib(control));
    if(++control<i) opt1(i);
}

void opt2(int n) {
    static int control;
    printf("%d ", recfib(control));
    if(recfib(++control)<=n) opt2(n);
}

int main() {
    int op, numval, valmax, i=0;

    do {
        printf("Pretende usar numero maximo de valores(1) ou valor maximo(2)? ");
        scanf("%d", &op);
    } while(op!=1 && op!=2);

    switch(op) {
        case 1:
            printf("\nIntroduza um numero maximo de valores: ");
            scanf("%d", &numval);
            opt1(numval);
            break;
        case 2:
            printf("\nIntroduza o valor maximo: ");
            scanf("%d", &valmax);
            opt2(valmax);
            break;
    }
}