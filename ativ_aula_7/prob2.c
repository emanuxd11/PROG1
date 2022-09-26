#include <stdio.h>
#define TAM 1000

int compacta(char orig[], int N, char dst[]);

int main()
{
    char orig[TAM], dst[TAM], character;
    int i=0, tamdst;
    do
    {   
        scanf("%c", &character);
        if(character!='.') orig[i++]=character;
    }while(character!='.');
    printf("\nValores lidos: %d\n", i);
    tamdst=compacta(orig, i, dst);
    printf("\nA string tem tamanho %d e e igual a: ", tamdst);
    for(i=0; i<tamdst; i++)
        printf("%c", dst[i]);
}

int compacta(char orig[], int N, char dst[])
{
    int i, tamdst;
    for(i=0, tamdst=0; i<N; i++)
        if(orig[i]!=orig[i+1] || i==N+1) dst[tamdst++]=orig[i];
    return tamdst;
}