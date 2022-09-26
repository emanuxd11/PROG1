#include <stdio.h>
#include <time.h>

void fibiter(int ntermos) {
    int i;
    unsigned long long int termo1=0, termo2=1, termo=0;
    for(i=0; i<ntermos; i++) {
        printf("%lld ", termo);
        termo=termo1+termo2;
        termo2=termo1;
        termo1=termo;
    }
}

unsigned int recfib(int n) {
    if(n<=1) return n;
    return recfib(n-1)+recfib(n-2);
}

void recfibcicl(int i) {
    static int control;
    printf("%d ", recfib(control));
    if(++control<i) recfibcicl(i);
}

int main() {
    int numelem=100;
    clock_t tic, toc;
    double tempo_iter, tempo_recu;

    /*tic=clock();
    fibiter(numelem);
    toc=clock();
    tempo_iter=(double)(toc-tic)/CLOCKS_PER_SEC;*/

    tic=clock();
    recfibcicl(numelem);
    toc=clock();
    tempo_recu=(double)(toc-tic)/CLOCKS_PER_SEC;

    printf("\n\nO metodo iterativo demorou %.2lfs a calcular %d elementos da serie de Fibonacci"
           "e o metodo recursivo demourou %.2lfs", tempo_iter, numelem, tempo_recu);
}
    