#include "headers/tabuleiro.h"
#include <stdbool.h>
#include <stdio.h>

void marcajogada(int x, int y, int tipo, int (*tabuleiro)[3]){
    if (tabuleiro[x][y] == 0){
        tabuleiro[x][y] = tipo;
    } else {
        printf("\nErro! Posicao ja ocupada!\n");
    }
}

void exibirJogo(int coord[3][3]){
    
    for(int i = 0 ; i < 3 ; i++){
        printf("|");
        for(int j = 0 ; j < 3 ; j ++){
            if(coord[i][j] == 4){
                printf("X");
            } else {
                if(coord[i][j] == 1){
                    printf("O");
                } else {
                    printf(" ");
                }
            }
            
            if(i != 3){
                printf("|");
            }
        }
        printf("\n");
    }
}

int vencedor(int soma){
    if(soma == 12){
        printf("\nO jogador 1 venceu!\n");
        return true;
    } else if(soma == 3){
        printf("\nA IA venceu!\n");
        return true;
    }
    return false;
}

int validador(int coord[3][3]){
    int somaCruzada1 = 0, somaCruzada2 = 0;

    for(int i = 0 ; i < 3 ; i++){
        int soma_linha = 0;
        int soma_coluna = 0;
        
        for(int j = 0 ; j < 3 ; j++){
            soma_linha += coord[i][j];   
            soma_coluna += coord[j][i];  
        }

        if (vencedor(soma_linha) == true || vencedor(soma_coluna) == true){
            return true;
        }
    }

    somaCruzada1 += coord[0][0] + coord[1][1] + coord[2][2];

    if (vencedor(somaCruzada1) == true){
        return true;
    }

    somaCruzada2 += coord[2][0] + coord[1][1] + coord[0][2];

    if(vencedor(somaCruzada2) == true){
        return true;
    }

    return false;
}