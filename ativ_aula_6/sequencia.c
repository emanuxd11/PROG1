#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define NUM 50

void menu_opcao(unsigned int *opcao);
int lerSeq(int v[]);
void escreverSeq(int v[], int n);
int minSeq(int v[], int n);
int maxSeq(int v[], int n);
void minmaxSeq(int v[], int n, int *min, int *max);
double mediaSeq(int v[], int n);
double desviopSeq(int v[], int n);
int parimparSeq(int v[], int n);

int main()
{
    unsigned int opcao, fim=0;
    int sequencia[NUM], numelem = 0, min, max, parimpar;
    double media, desviop;
    do
    {
		menu_opcao(&opcao);
		switch (opcao)
        {
			case 1: numelem = lerSeq(sequencia); break;
			case 2: escreverSeq(sequencia, numelem);
                    printf("\n\nPrima tecla para continuar.\n");
                    getchar();
                    getchar();
                    break;
			case 3: minmaxSeq(sequencia, numelem, &min, &max); 
                    system("clear");
                    printf("\n\nMínimo da sequência: %d\n", min);
                    printf("\nMáximo da sequência: %d\n", max);
                    printf("\n\nPrima tecla para continuar.\n");
                    getchar();
                    getchar();
                    break;
			case 4: media = mediaSeq(sequencia, numelem);
                    system("clear");
                    printf("\n\nMédia da sequência: %lf\n", media);
                    printf("\n\nPrima tecla para continuar.\n");
                    getchar();
                    getchar();
                    break;
			case 5: desviop = desviopSeq(sequencia, numelem);
                    system("clear");
                    printf("\n\nDesvio padrão da sequência: %lf\n", desviop);
                    printf("\n\nPrima tecla para continuar.\n");
                    getchar();
                    getchar();
                    break;
			case 6: parimpar = parimparSeq(sequencia, numelem);
                    system("clear");
                    if(parimpar==0)
                        printf("\n\nNem par nem impar\n");
                    else if(parimpar==1)
                        printf("\n\nSequencia de números impares\n");
                    else if(parimpar==2)
                        printf("\n\nSequencia de números pares\n");
                    printf("\n\nPrima tecla para continuar.\n");
                    getchar();
                    getchar();
                    break;
			case 7: fim = 1;
		}
	}while(!fim);
}

void menu_opcao(unsigned int *opcao)
{
    do
    {
        system("clear");
        printf("\n\t\tAnálise de uma sequência de inteiros positivos\n");
        printf("1: Ler a sequência\n");
        printf("2: Escrever a sequência\n"); 
        printf("3: Calcular o máximo e mínimo da sequência\n");
        printf("4: Calcular a média da sequência\n");
        printf("5: Calcular o desvio padrão\n");
        printf("6: Verificar se a sequência é só constituída por números pares/ímpares\n");
        printf("7: Terminar\n");
        printf(" \n\nOpção: ");
        scanf("%d", opcao);
	}while(*opcao < 1 || *opcao > 7);
}

int lerSeq(int v[])
{
    int i, val;
    printf("Introduza elementos (0 termina): ");
    for ( i = 0; i < NUM; i++)
    {
        scanf("%d", &val);
        if(val==0) break;
        v[i]=val;
    }
    return i;
}

void escreverSeq(int v[], int n)
{
    int i;
    printf("Sequencia de valores: ");
    for (i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

int minSeq(int v[], int n)
{
    int i, min;
    min = v[0];
    for (i = 1; i < n; i++)
        if (v[i]<min) min=v[i];
    return min;
}

int maxSeq(int v[], int n)
{
    int i, max;
    max = v[0];
    for (i = 1; i < n; i++)
        if (v[i]>max) max=v[i];
    return max;
}

void minmaxSeq(int v[], int n, int *min, int *max)
{
    int i;
    *max=v[0];
    *min=v[0];
    for(i=1; i<n; i++)
    {
        if(v[i]>*max) *max=v[i];
        if(v[i]<*min) *min=v[i];
    }
}

double mediaSeq(int v[], int n)
{
    int i;
    double media = 0;
    for (i = 0; i < n; i++)
        media += v[i];
    return media/n;
}

double desviopSeq(int v[], int n)
{
    int i;
    double media, dp=0;
    media = mediaSeq(v, n);
    for (i = 0; i < n; i++)
        dp += (v[i]-media)*(v[i]-media); 
    dp = sqrt(dp/(n-1));
    return dp;
}

int parimparSeq(int v[], int n)
{
    int i, cont=0;
    for(i=0; i<n; i++)
        if(v[i]%2==0) cont++;
    if(cont==n) return 2;
    else if(cont==0) return 1;
    return 0;
}