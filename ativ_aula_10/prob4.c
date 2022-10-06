#include "prob4lib.h"

int main() {
    complexo z, w, s;
    puts("Complexo z: ");
    z=le_complexo(z);
    puts("Complexo w: ");
    w=le_complexo(w);
    s=somaComplexo(z, w);
    escreveComplexo(s);
    printf("\nModulo de z+w = %.2lf", modComplexo(s));
    printf("\narg(z+w) = %.2lf", arg(s));
}