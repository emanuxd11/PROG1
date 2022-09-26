#include <stdio.h>
#include <math.h>

void cartesianas_polares(float x, float y, float *r, float *theta);
void polares_cartesianas(float r, float theta, float *x, float *y);

int main() {
    float x, y, r, theta;
    printf("Insira coordenadas cartesianas: ");
    scanf("%f %f", &x, &y);
    cartesianas_polares(x, y, &r, &theta);
    printf("As coordenadas polares de (%.2f, %.2f) sao (%.2f, %.2f)", x, y, r, theta);
    polares_cartesianas(r, theta, &x, &y);
    printf("As coordenadas cartesianas de (%.2f, %.2f) sao (%.2f, %.2f)", r, theta, x, y);
}

void cartesianas_polares(float x, float y, float *r, float *theta) {
    *r=sqrt(pow(x, 2)+pow(y, 2));
    *theta=atan(y/x);
}

void polares_cartesianas(float r, float theta, float *x, float *y) {
    *x=r*cos(theta);
    *y=r*sin(theta);
}