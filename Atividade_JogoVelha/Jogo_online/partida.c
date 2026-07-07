#include "headers/partida.h"
#include "headers/tabuleiro.h"
#include "headers/jogadorTeclado.h"
#include "headers/jogadorRemoto.h"
#include <stdio.h>
#include <stdbool.h>

void inicia(int souServidor){
    int tabuleiro[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
    int contador = 0;
    int meuTipo, tipoAdversario;
    bool minhaVez;

    if (souServidor == 1) {
        meuTipo = 4;
        tipoAdversario = 1;
        minhaVez = true;
    } else {
        meuTipo = 1;
        tipoAdversario = 4;
        minhaVez = false;
    }

    exibirJogo(tabuleiro);

    while(true){
        if (minhaVez) {
            jogaTeclado(tabuleiro, meuTipo);
            minhaVez = false;
        } else {
            jogaRemoto(tabuleiro, tipoAdversario);
            minhaVez = true;
        }

        contador++;
        exibirJogo(tabuleiro);

        if (validador(tabuleiro) == true) {
            break;
        }

        if (contador == 9) {
            printf("\nO jogo empatou! Deu velha!\n");
            break;
        }
    }
    
    fecharConexao();
}
