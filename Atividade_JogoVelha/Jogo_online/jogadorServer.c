#include "headers/jogadorRemoto.h"
#include "headers/partida.h"

#define PORTA 8080

int main(){
    acceptConexao(PORTA);
    inicia(1); 
    return 0;
}