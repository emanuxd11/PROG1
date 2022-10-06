#include <stdio.h>

void ordena(float notas[][2], int N);

int main()
{
    int i, j, alu[4][3];
    float media[4]={0}, notas[4][2];
    for(i=0; i<4; i++)
    {   
        printf("Insira os dados do aluno %d (n. mecanografico, nota 1 e nota 2): ", i+1);
        for(j=0; j<3; j++)
        {
            scanf("%d", &alu[i][j]);
            if(j>0) media[i]+=alu[i][j];
            if(j==2) media[i]/=2;
        }
        for(j=0; j<2; j++)
        {
            if(j<1) notas[i][j]=alu[i][0]; 
            else notas[i][j]=media[i];
        }
    }
    ordena(notas, 4); //tamanho = 4, podia usar um contador
    puts("\nNumero\tMedia");
    for(i=0; i<4; i++)
    {
        for(j=0; j<2; j++)
        {
            if(j==0) printf("%.0f\t", notas[i][j]);
            else printf("%.1f\n", notas[i][j]);
        }
    }
}

void ordena(float notas[][2], int N)
{
    int i, j, k;
    for(i=0; i<N; i++)
    {
        for(j=i; j>0; j--)
        {   
            if(notas[j][1]>notas[j-1][1]) //como sabemos que se vai comparar a segunda coluna, penso que não há problema em fazer assim
            {                             //principalmente porque o número de colunas vem fixo na definição da função
                for(k=0; k<2; k++)
                {
                    notas[j][k]=notas[j][k]+notas[j-1][k];
                    notas[j-1][k]=notas[j][k]-notas[j-1][k];
                    notas[j][k]=notas[j][k]-notas[j-1][k];
                }
            }
        }
    }
}