#include <stdio.h>
#include <math.h>

double dist(float x1, float x2, float y1, float y2);
void colisao(double dist, float r1, float r2);

int main()
{
    float x1, x2, y1, y2, r1, r2;
    printf("Insira as coordenadas do centro da primeira bola e o seu raio: ");
    scanf("%f %f %f", &x1, &y1, &r1);
    printf("Insira as coordenadas da segunda bola e o seu raio: ");
    scanf("%f %f %f", &x2, &y2, &r2);
    colisao(dist(x1, x2, y1, y2), r1, r2);
}

double dist(float x1, float x2, float y1, float y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

void colisao(double dist, float r1, float r2)
{
    if(dist<r1+r2) printf("As bolas estao em colisao.");
    else printf("As bolas nao estao em colisao.");
}