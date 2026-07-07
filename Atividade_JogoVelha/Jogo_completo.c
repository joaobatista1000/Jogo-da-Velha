#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int escolha_jogador = 0;
    while(escolha_jogador != 4){
        printf("Escolha: \n(1) Jogo Normal\n(2) Jogo contra a IA\n(3) Jogo 'online' (com sockets)\n(4) Para sair\n");
        scanf("%d",&escolha_jogador);
        switch(escolha_jogador){
            case 1:
                system("clear");
                system("gcc \"../Jogo_normal/main_normal.c\" \"../Jogo_normal/partida.c\" \"../Jogo_normal/tabuleiro.c\" -o \"../Jogo_normal/jogo\" && \"../Jogo_normal/jogo\"");
                system("clear");
                break;
            case 2:
                system("clear");
                system("gcc \"../JogoIA/jogadorIA.c\" \"../JogoIA/jogadorTeclado.c\" \"../JogoIA/partida.c\" \"../JogoIA/tabuleiro.c\" -o \"../JogoIA/jogo\" && \"../JogoIA/jogo\"");
                system("clear");
                break;
            case 3:
            break;
            case 4:
                break;
            } 
    }
    return 0;
}