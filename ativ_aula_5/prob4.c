#include <stdio.h>
#include <math.h>

float dist(float x1, float x2, float y1, float y2);

int main()
{
    float x1, x2, y1, y2;
    printf("Insira as coordenadas do primeiro ponto: ");
    scanf("%f %f", &x1, &y1);
    printf("Insira as coordenadas do segundo ponto: ");
    scanf("%f %f", &x2, &y2);
    printf("A distancia entre os pontos e igual a %.2f", dist(x1, x2, y1, y2));
}

float dist(float x1, float x2, float y1, float y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}