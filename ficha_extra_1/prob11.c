#include <stdio.h>

int main()
{
    int h, ciclo, count_3=0, i, count, count_i;
    printf("Insira a altura da arvore: ");
    scanf("%d", &h);
    for (ciclo=1; ciclo<=h; ciclo++)
    {
        count=0, count_i=0;
        while(count<=2*(h-ciclo))
        {   
            if(count!=0) printf(" ");
            count++;
        }   
        while(count_i<=2*ciclo-2)
        {
            if(count_i<=2*ciclo-count_i-1)
            {
                printf("%d%c", count_i+1, ciclo==1 ? ' ' : '_');
                i=1;
            }
            else
            {
                printf("%d%c", ciclo-i, ciclo-i==1 ? ' ' : '_');
                i++;
            }
            count_i++;
        }
        printf("\n");
    }
}