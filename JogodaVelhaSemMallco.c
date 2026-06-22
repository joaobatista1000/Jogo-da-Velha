#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int vencedor(int soma){
    if(soma == 15){
            printf("\nO jogador 1 venceu!\n");
            return true;
        }else if(soma == 3){
            printf("\nO jogador 2 venceu!\n");
            return true;
        }
    return false;
}

int validador(int coord[3][3]){
    int somaCruzada1 = 0, somaCruzada2 = 0;
    // 1. Corrige a verificação de todas as Linhas e Colunas
    for(int i = 0 ; i < 3 ; i++){
        int soma_linha = 0;
        int soma_coluna = 0;
        
        for(int j = 0 ; j < 3 ; j++){
            soma_linha += coord[i][j];   // Acumula os valores da linha
            soma_coluna += coord[j][i];  // Acumula os valores da coluna
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
void exibirJogo(int coord[3][3]){
    for(int i = 0 ; i < 3 ; i++){
        printf("|");
        for(int j = 0 ; j < 3 ; j ++){
            if(coord[i][j] == 5){
                printf("X");
            }else{
                if(coord[i][j] == 1){
                printf("O");
            }else{
                printf(" ");
            }}
            
            if(i != 3){
                printf("|");
            }
        }
        printf("\n");
    }
}

int jogo(){
    int array[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
    int running = validador(array);
    int contador = 0;

    exibirJogo(array);

    while (running != true)
    {
        int x1 = 0,y1 = 0;
        int x2 = 0,y2 = 0;

        printf("\n(Jogador 1)\nDigite a coordenada de seu interesse (X Y): ");
        scanf("%d %d",&x1,&y1);
        if (array[x1][y1] == 0){
            array[x1][y1] = 5;
            contador += 1;
        }else{
            printf("\nOps!!! Você digitou um valor inválido, perdeu sua vez!\n\n");
        }
        
        exibirJogo(array);
        running = validador(array);

        if (running != true && contador == 9) {
                printf("\nO jogo empatou! Deu velha!\n");
                break;
            }

        if (running != true){
            printf("\n(Jogador 2)\nDigite a coordenada de seu interesse (X Y): ");
            scanf("%d %d",&x2,&y2);
            if(array[x2][y2] == 0){
                array[x2][y2] = 1;
                contador += 1;
            }else{
                printf("\nOps!!! Você digitou um valor inválido, perdeu sua vez!\n\n");
            }
            
            exibirJogo(array);
            running = validador(array);
            
        }
    }
    
    return 0;
}


int main(){
    jogo();
    return 0;
}