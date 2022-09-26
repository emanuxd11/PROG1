#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAMANHO 5
#define MSG "Insira a opcao:\n\n1 - Inserir vetor\n2 - Imprimir vetor\n3 - Ordenar por ordem crescente\n4 - Ordenar por ordem decrescente\n5 - Baralhar a ordem\n6 - Sair\n\nOpcao: "

void ler_vetor(int v[], int n);
void imprimir_vetor(int v[], int n);
void sortcresc(int v[], int n);
void sortdecresc(int v[], int n);
void shuffle(int v[], int n);

int main()
{
    srand(time(NULL));
    int i, j, v[TAMANHO], op;
    do
    {
        system("clear");
        printf(MSG);
        scanf("%d", &op);
        switch(op)
        {
            case 1:
                system("clear");
                ler_vetor(v, TAMANHO);
                printf("\nVetor inserido: ");
                imprimir_vetor(v, TAMANHO);
                getchar();
                getchar();
                break;
            case 2:
                system("clear");
                printf("Vetor: ");
                imprimir_vetor(v, TAMANHO);
                getchar();
                getchar();
                break;
            case 3:
                system("clear");
                sortcresc(v, TAMANHO);
                printf("Vetor por ordem crescente: ");
                imprimir_vetor(v, TAMANHO);
                getchar();
                getchar();
                break;
            case 4:
                system("clear");
                sortdecresc(v, TAMANHO);
                printf("Vetor por ordem decrescente: ");
                imprimir_vetor(v, TAMANHO);
                getchar();
                getchar();
                break;
            case 5:
                system("clear");
                shuffle(v, TAMANHO);
                printf("Vetor baralhado: ");
                imprimir_vetor(v, TAMANHO);
                getchar();
                getchar();
                break;
        }
        puts("\n");
    }while(op!=6);
}

void ler_vetor(int v[], int n)
{
    int i;
    for(i=0; i<TAMANHO; i++)
    {
        printf("Insira o elemento %d: ", i+1);
        scanf("%d", &v[i]);
    }
}

void imprimir_vetor(int v[], int n)
{
    int i;
    printf("{");
    for(i=0; i<n; i++) 
    {
        printf("%d", v[i]);
        if(i>=0 && i<n-1) printf(", ");
    }
    printf("}");
}

void sortcresc(int v[], int n)
{
    int i, j;
    for(i=0; i<n; i++)
    {
        for(j=i; j>0; j--)
        {   
            if(v[j]<v[j-1])
            {
                v[j]=v[j]+v[j-1];
                v[j-1]=v[j]-v[j-1];
                v[j]=v[j]-v[j-1];
            }
        }
    }
}

void sortdecresc(int v[], int n)
{
    int i, j;
    for(i=0; i<n; i++)
    {
        for(j=i; j>0; j--)
        {   
            if(v[j]>v[j-1])
            {
                v[j]=v[j]+v[j-1];
                v[j-1]=v[j]-v[j-1];
                v[j]=v[j]-v[j-1];
            }
        }
    }
}

void shuffle(int v[], int n)
{
    int i, vaux[TAMANHO], posicoesocupadas[TAMANHO]={0}, posicao;
    for(i=0; i<n; i++)
        vaux[i]=v[i];            //copiar para vetor auxiliar
    for(i=0; i<n; i++)
    {
        do
            posicao=rand()%n;
        while(posicoesocupadas[posicao]);
        posicoesocupadas[posicao]=1;
        v[i]=vaux[posicao];     //v1 toma o valor de vaux na posicao aleatoria
    }
}

/*void shuffle(int v[], int n)
{
    int i, posicao, t;
    for(i=0; i<n; i++)
    {
        posicao=rand()%n;
        t=v[i];
        v[i]=v[posicao]; //troca as posições
        v[posicao]=t;
    }
}*/