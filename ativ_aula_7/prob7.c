#include <stdio.h>
#include <stdlib.h>
#define LINHAS 3
#define COLUNAS 3

void imprimeTabuleiro(char tabuleiro[LINHAS][COLUNAS]) {
    int i, j;
    puts("\nTabuleiro:");
    for (i = 0; i < LINHAS; i++) {
        puts("");
        for (j = 0; j < LINHAS; j++) {
            printf(" %c %c", tabuleiro[i][j], j == COLUNAS - 1 ? ' ' : '|');
        }
    }
    puts("");
}

int haVencedor(char tabuleiro[LINHAS][COLUNAS]) {
    int i, j, cont = 1;
    for (i = 0; i < LINHAS; i++) {
        for (j = 0; j < COLUNAS - 1; j++) {
            if (tabuleiro[i][j] == tabuleiro[i][j + 1]) {
                cont++;
            }
            else {
                cont = 1;
            }
            if (cont == COLUNAS){
                return 1;
            }
        }
    }
    for (j = 0; j < COLUNAS; j++) {
        for (i = 0; i < LINHAS - 1; i++) {
            if (tabuleiro[i][j] == tabuleiro[i + 1][j]) {
                cont++;
            } else {
                cont = 1;
            }
            if (cont == LINHAS) {
                return 1;
            }
        }
    }
    for (i = 0; i < COLUNAS - 1; i++) {
        if (tabuleiro[i][i] == tabuleiro[i + 1][i + 1]) {
            cont++;
        } else {
            cont = 1;
        }
        if (cont == LINHAS) {
            return 1;
        }
    }
    for (i = 0, j = COLUNAS - 1; i < LINHAS - 1 && j > 0; i++, j--) {
        if (tabuleiro[i][j] == tabuleiro[i + 1][j - 1]) {
            cont++;
        } else {
            cont = 1;
        }
        if (cont == LINHAS) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int vencedor = 0;
    int escolha = 0;
    int linha = 0;
    int coluna = 0;
    int i;
    char tabuleiro[LINHAS][COLUNAS] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };

    for (i = 0; i < 9 && !vencedor; i++) {
        int jogador = i % 2 + 1;
        system("clear");
        imprimeTabuleiro(tabuleiro);

        do {
            printf("\nJogador %d, introduza o numero do quadrado "
                   "onde quer colocar o seu %c ",
                   jogador, (jogador == 1) ? 'X' : 'O');
            scanf("%d", &escolha);

            linha = --escolha / 3;
            coluna = escolha % 3;
        } while (escolha < 0 || escolha > 9 || tabuleiro[linha][coluna] > '9');

        tabuleiro[linha][coluna] = (jogador == 1) ? 'X' : 'O';
        if (haVencedor(tabuleiro)) {
            vencedor = jogador;
        }
    }
    imprimeTabuleiro(tabuleiro);
    if (!vencedor) {
        printf("Empate\n");
    }
    else {
        printf("O Jogador %d venceu\n", vencedor);
    }
    return 0;
}