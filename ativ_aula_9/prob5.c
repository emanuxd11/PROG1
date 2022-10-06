#include <stdio.h>

void quociresto(int dividendo, int divisor, int *quociente, int *resto);

int main() {

    int a=10, b=7, c=a, quociente, resto;
    
    quociresto(a, b, &quociente, &resto);
    printf("%d", quociente);

}

void quociresto(int dividendo, int divisor, int *quociente, int *resto) {

    while(dividendo>divisor) {
        dividendo-=divisor;
    }

    *quociente=dividendo;

    while(dividendo-divisor>=0) {
        dividendo-=divisor;
    }
    *resto=dividendo;
}