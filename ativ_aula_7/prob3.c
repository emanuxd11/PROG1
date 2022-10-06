#include <stdio.h>
int main()
{
    int i, j, alu[4][3];
    float media[4]={0};
    for(i=0; i<4; i++)
    {   
        printf("Insira os dados do aluno %d (n. mecanografico, nota 1 e nota 2): ", i+1);
        for(j=0; j<3; j++)
        {
            scanf("%d", &alu[i][j]);
            if(j>0) media[i]+=alu[i][j];
        }
        media[i]/=2;
    }
    puts("\nNumero\tNota 1\tNota 2\tMedia");
    for(i=0; i<4; i++)
    {   
        for(j=0; j<3; j++)
        {
            if(j==0) printf("%05d\t", alu[i][j]);
            else printf("%d\t", alu[i][j]);
            if(j==2) printf("%.1f\n", media[i]);
        }
    }
}