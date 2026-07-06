#include "headers/tabuleiro.h"
#include <stdio.h>

void marcajogada(int x, int y, int tipo, int (*tabuleiro)[3]){
    if (tabuleiro[x][y] == 0){
        tabuleiro[x][y] = tipo;
    } else {
        printf("\nErro! Posicao ja ocupada!\n");
    }
}

void exibirJogo(int (*tabuleiro)[3]){
    printf("\n  0 1 2\n");
    for(int i = 0; i < 3; i++){
        printf("%d|", i);
        for(int j = 0; j < 3; j++){
            if(tabuleiro[i][j] == 5){
                printf("X");
            } else if(tabuleiro[i][j] == 1){
                printf("O");
            } else {
                printf(" ");
            }
            if(j < 2) printf("|");
        }
        printf("|\n");
    }
    printf("\n");
}

int vencedor(int soma){
    if(soma == 15){
        printf("\nO jogador X (Servidor) venceu!\n");
        return true;
    } else if(soma == 3){
        printf("\nO jogador O (Cliente) venceu!\n");
        return true;
    }
    return false;
}

int validador(int (*tabuleiro)[3]){
    for(int i = 0; i < 3; i++){
        int soma_linha = 0;
        int soma_coluna = 0;
        for(int j = 0; j < 3; j++){
            soma_linha += tabuleiro[i][j];   
            soma_coluna += tabuleiro[j][i];  
        }
        if (vencedor(soma_linha) || vencedor(soma_coluna)) return true;
    }

    int somaCruzada1 = tabuleiro[0][0] + tabuleiro[1][1] + tabuleiro[2][2];
    if (vencedor(somaCruzada1)) return true;

    int somaCruzada2 = tabuleiro[2][0] + tabuleiro[1][1] + tabuleiro[0][2];
    if (vencedor(somaCruzada2)) return true;

    return false;
}