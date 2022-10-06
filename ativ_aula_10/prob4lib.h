#ifndef _PROB4LIB_H
#define _PROB4LIB_H 

#include <stdio.h>
#include <math.h>

typedef struct {
    double x, y;
} complexo;

complexo le_complexo(complexo c);

void escreveComplexo(complexo c);

complexo somaComplexo(complexo c1, complexo c2);

double modComplexo(complexo c);

double arg(complexo c);

#endif