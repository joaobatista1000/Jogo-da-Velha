#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){

    bool running = true;

    int x, y;
    char **jogo;

    jogo = malloc(3 * sizeof(char*));

    for(int i = 0; i < 3; i++){
        jogo[i] = malloc(3 * sizeof(char));
    }

    if(jogo == NULL){
        printf("Deu ruim");
        return 1;
    }
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            jogo[i][j] = '*';
            printf("%c ", jogo[i][j]);
        }
        printf("\n");
    }

    while(running){
        
        printf("Informe a coordenanda (x,y): ");
        scanf("%d %d", &x,&y);
        
        jogo[x][y] = 1;
        
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
               
            }
        }

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                printf("%c ", jogo[i][j]);
            }
            printf("\n");
        }
    }
    
    return 0;
}