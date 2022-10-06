#include <stdio.h>

int main()
{
    float distancia, vel_carro, limite_vel, tempo_legal, tempo_vel_furiosa, tempo_poupado;
    printf("Insira a distancia: ");
    scanf("%f", &distancia);
    printf("Insira a velocidade do carro: ");
    scanf("%f", &vel_carro);
    printf("Insira o limite de velocidade: ");
    scanf("%f", &limite_vel);
    
    tempo_poupado = (distancia/limite_vel-distancia/vel_carro)*60;

    printf("Poupa %.0f minutos", tempo_poupado);

}