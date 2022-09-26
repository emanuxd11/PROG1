#include <stdio.h>
#define TAM_MAX 10

void lermatrizquad(int matriz[][TAM_MAX], int N);
int mat_unidim(int matriz[][TAM_MAX], int matriz_uni[TAM_MAX * TAM_MAX], int N);
int pos(int x, int y, int tamanho);
void imprimeMatriz(int matriz[], int N);
void produto_por_Escalar(int matriz[], int N, int escalar);
void multMatrizes(int matriz[], int mult[], int resultado[], int N);

int main()
{
    int mat[TAM_MAX][TAM_MAX], v[TAM_MAX * TAM_MAX], tam, coluna[TAM_MAX], resultado[TAM_MAX] = {0}, i, escalar;
    printf("Insira o tamanho da matriz(n*n): ");
    scanf("%d", &tam);
    lermatrizquad(mat, tam);
    mat_unidim(mat, v, tam);
    puts("\nMatriz:\n");
    imprimeMatriz(v, tam);

    /*printf("\nInsira um escalar para multiplicar pela matriz: ");
    scanf("%d", &escalar);
    produto_por_Escalar(v, tam, escalar);
    puts("\nMatriz multiplicada por 2:\n");   //multiplica por um escalar
    imprimeMatriz(v, tam);*/

    printf("\n");
    for (i = 0; i < tam; i++)
    {
        printf("Insira o %d elemento da matriz coluna: ", i + 1);
        scanf("%d", &coluna[i]);
    }
    multMatrizes(v, coluna, resultado, tam); // multiplica por uma coluna
    puts("\nMatriz x coluna:\n");
    for (i = 0; i < tam; i++)
    {
        printf("%d\n", resultado[i]);
    }
}

void lermatrizquad(int matriz[][TAM_MAX], int N)
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("Insira %d linha %d coluna: ", i + 1, j + 1); // lê a matriz
            scanf("%d", &matriz[i][j]);
        }
    }
}

int mat_unidim(int matriz[][TAM_MAX], int matriz_uni[TAM_MAX * TAM_MAX], int N)
{
    int i, j, k;
    for (i = 0, k = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        { // copia a matriz para um vetor unidimensional
            matriz_uni[k++] = matriz[i][j];
        }
    }
    return N * N; // devolve o tamanho do vetor unidimensional para o qual foi copiada a matriz
}

int pos(int x, int y, int tamanho)
{
    return y + (x - 1) * tamanho - 1;
}

void imprimeMatriz(int matriz[], int N)
{
    int i, cont = 1;
    for (i = 0; i < N * N; i++)
    {
        printf("%3d ", matriz[i]);
        if (i == N * cont - 1)
        {
            printf("\n");
            cont++;
        }
    }
}

void produto_por_Escalar(int matriz[], int N, int escalar)
{
    int i;
    for (i = 0; i < N * N; i++)
    {
        matriz[i] *= escalar;
    }
}

void multMatrizes(int matriz[], int mult[], int resultado[], int N)
{
    int i, j = 0, k = 0;
    for (i = 0; i < N; i++)
    {
        for (k = 0; k < N; j++, k++)
        {
            resultado[i] += matriz[j] * mult[k];
        }
    }
}