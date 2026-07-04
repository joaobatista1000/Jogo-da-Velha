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
            system("cls");
            system("gcc \"..\\Jogo_normal\\main_normal.c\" \"..\\Jogo_normal\\partida.c\" \"..\\Jogo_normal\\tabuleiro.c\" -o \"..\\Jogo_normal\\jogo.exe\" && \"..\\Jogo_normal\\jogo.exe\"");
            system("pause");
            system("cls");
            break;
            case 2:
            case 3:
                system("cls");
                //Função BR3
                system("pause");
                system("cls");
                break;
            case 4:
                break;
            } 
    }
    return 0;
}