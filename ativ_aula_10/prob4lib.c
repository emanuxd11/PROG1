#include <stdio.h>
#include <math.h>
#include "prob4lib.h"

complexo le_complexo(complexo c) {
    printf("Insira a parte real: ");
    scanf("%lf", &c.x);
    printf("Insira a parte imaginaria: ");
    scanf("%lf", &c.y);
    return c;
}

void escreveComplexo(complexo c) {
    printf("z = %.2f + i%.2f", c.x, c.y);
}

complexo somaComplexo(complexo c1, complexo c2) {
    complexo res;
    res.x=c1.x+c2.x;
    res.y=c1.y+c2.y;
    return res;
}

double modComplexo(complexo c) {
    return sqrt(pow(c.x, 2)+pow(c.y, 2));
}

double arg(complexo c) {
    return atan2(c.y, c.x);
}