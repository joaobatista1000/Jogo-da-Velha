#include "headers/partida.h"
#include "headers/jogadorTeclado.h"
#include "headers/tabuleiro.h"
#include "headers/jogadorRemoto.h"
#include <stdio.h>
#include <stdbool.h>

#define PORTA 8080
#define IP_SERVIDOR "127.0.0.1"

void jogaTeclado(int (*tabuleiro)[3], int meuTipo){
    int x, y;
    bool escolha = true;

    while(escolha){
        printf("\nSua vez! Digite a coordenada (X Y): ");
        if(scanf("%d %d", &x, &y) != 2){
            printf("\nErro: Entrada invalida! Digite apenas numeros.\n");
            while (getchar() != '\n'); 
            continue;
        } else if (x < 0 || x > 2 || y < 0 || y > 2) {
            printf("\nErro: Coordenadas fora do tabuleiro (0 a 2)!\n");
        } else if (tabuleiro[x][y] != 0) {
            printf("\nErro: Posicao ja ocupada!\n");
        } else {
            escolha = false;
        }
    }
    
    marcajogada(x, y, meuTipo, tabuleiro);
    enviaJogada(x, y);
}

