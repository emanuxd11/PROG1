#include <stdio.h>

int main()
{
    int n, i, con=1,times=1, pertence=0;
    printf("Escreva o número para ver se faz parte da sequência de Connell\n");
    scanf("%d", &n);
    if (n==con)
    {
        pertence=1;
    }
    else
    {
    while(n!=con && times!= 100)
    {
        con+=1;
        if(n==con)
        {
            pertence=1;
            break;
        }
        else
        {
        for(i=times;i<0;i--)
        {
            con+=2;
            if(n==con)
            {
                is=1;
                break;
            }
        }
        times++;
        }
    }
    }
    if(is==1)
    {
        printf("O número inserido pertence à sequência de Connell\n");
    }
    else printf("O número inserido não pertence à sequência de Connell\n");
    return 0;
}
