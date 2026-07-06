#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int escolha_jogador = 0;
    while(escolha_jogador != 4){
        printf("Escolha: \n(1) Jogo Normal\n(2) Jogo contra a IA\n(3) Jogo 'online' (com sockets)\n(4) Para sair\n");
        if(scanf("%d", &escolha_jogador) != 1){
            printf("Entrada invalida!\n");
            while(getchar() != '\n');
            continue;}
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
                system("clear");
                int escolha_jogo_online = 0;
                
                while(escolha_jogo_online != 3){
                printf("Digite:\n(1) Para servidor\n(2) Para client\n (3) Para sair\n");
                if(scanf("%d", &escolha_jogo_online) != 1){
                    printf("Entrada invalida!\n");
                    while(getchar() != '\n');
                    continue;}
                
                switch(escolha_jogo_online){
                    case 1:
                        system("clear");
                        system("gcc \"../jogadorServer.c\" \"../jogadorRemoto.c\" \"../jogadorTeclado.c\" \"../partida.c\" \"../tabuleiro.c\" -o \"../servidor\" && \"../servidor\"");
                        system("clear");
                        break;
                    
                    case 2:
                        system("clear");
                        system("gcc \"../jogadorCliente.c\" \"../jogadorRemoto.c\" \"../jogadorTeclado.c\" \"../partida.c\" \"../tabuleiro.c\" -o \"../cliente\" && \"../cliente\"");
                        system("clear");
                        break; 
                    
                    case 3:
                        break;
                    default:
                        printf("Erro! Tente novamente\n");
                        break;
                    }
                }
                break; 
            case 4:
                break;
            
            default:
                printf("Erro! Tente novamente\n");
            } 
    }
    return 0;
}
