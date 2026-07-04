#include "headers/partida.h"
#include "headers/tabuleiro.h"
#include <stdio.h>
#include <stdbool.h>

int jogo(){
    int array[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
    int running = validador(array);
    int contador = 0;

    exibirJogo(array);

    while (running != true)
    {
        int x1, y1;
        int x2, y2;
        bool escolha = true;

        if (contador == 9) {
            printf("\nO jogo empatou! Deu velha!\n");
            break;
        }

        while(escolha){

            printf("\n(Jogador 1)\nDigite a coordenada de seu interesse (X Y): ");

            if(scanf("%d %d", &x1, &y1) != 2){

                printf("\nErro:\nEntrada invalida! Digite novamente apenas numeros inteiros.\n\n");

                exibirJogo(array);

                while (getchar() != '\n'){

                }

                continue;
        
            } else if (x1 < 0 || x1 > 2 || y1 < 0 || y1 > 2) {
                printf("\nErro:\nCoordenadas fora do tabuleiro (Digite novamente valores de 0 a 2)!\n\n");
                exibirJogo(array);
            }else{
                escolha = false;
            }
        }

        escolha = true;
        
        if (array[x1][y1] == 0){
            array[x1][y1] = 5;
            contador += 1;
        } else {
            printf("\nErro!\nVoce digitou um valor invalido, perdeu sua vez!\n\n");
        }
        
        exibirJogo(array);
        running = validador(array);

        if (contador == 9) {
            printf("\nO jogo empatou! Deu velha!\n");
            break;
        }

        if (running != true){

            while(escolha){

                printf("\n(Jogador 2)\nDigite a coordenada de seu interesse (X Y): ");

                if(scanf("%d %d", &x2, &y2) != 2){

                    printf("\nErro:\nEntrada invalida! Digite novamente apenas numeros inteiros.\n\n");

                    exibirJogo(array);

                    while (getchar() != '\n'){

                    }

                    continue;
            
                } else if (x2 < 0 || x2 > 2 || y2 < 0 || y2 > 2) {
                    printf("\nErro:\nCoordenadas fora do tabuleiro (Diginite novamente valores de 0 a 2)!\n\n");
                    exibirJogo(array);
                }else{
                    escolha = false;
                }
            }
            
            if (array[x2][y2] == 0){
                array[x2][y2] = 1;
                contador += 1;
            } else {
                printf("\nErro!\nVoce digitou um valor invalido, perdeu sua vez!\n\n");
            }
            
            exibirJogo(array);
            running = validador(array);
        }  
    }
    return 0;
}
