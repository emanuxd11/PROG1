#include <stdio.h>
#include <stdlib.h>
#define LINHAS 3
#define COLUNAS 3

int main() {
    int vencedor=0, escolha=0, linha=0, coluna=0, i;
    char tabuleiro[LINHAS][COLUNAS]={
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };

    for(i=0; i<9 && !vencedor; i++) {
        int jogador=i%2+1;
        system("clear");
        imprimeTabuleiro(tabuleiro);

        do {
            printf("\nJogador %d, introduza o numero do quadrado "
                   "onde quer colocar o seu %c ",
                   jogador, jogador==1 ? 'X' : 'O');
            scanf("%d", &escolha);

            linha=--escolha/3;
            coluna=escolha%3;
        } while(escolha<0 || escolha>9 || tabuleiro[linha][coluna]>'9');

        tabuleiro[linha][coluna]=(jogador==1) ? 'X' : 'O';
        if(haVencedor(tabuleiro)) {
            vencedor=jogador;
        }
    }

    imprimeTabuleiro(tabuleiro);
    if(!vencedor) {
        printf("Empate\n");
    } else {
        printf("O Jogador %d venceu\n", vencedor);
    }
}