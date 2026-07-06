#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "headers/tabuleiro.h"
#include "headers/partida.h"
#include "headers/jogadorIA.h"
#include "headers/jogadorTeclado.h"

void inicia(){
    int array[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
    int running = validador(array);
    int contador = 0;

    exibirJogo(array);

    while (running != true){

        if(running != true){

            jogaTeclado(array);
            contador++;

        }

        exibirJogo(array);
        running = validador(array);

        if (running != true && contador == 9) {
            printf("\nO jogo empatou! Deu velha!\n");
            break;
        }

        if (running != true) {
            printf("\n(Turno da IA)...\n");
            
            jogadaIA(array); 
            contador += 1;
            
            exibirJogo(array);
            running = validador(array);
        }
    }
}

int main(){
    inicia();
    return 0;
}