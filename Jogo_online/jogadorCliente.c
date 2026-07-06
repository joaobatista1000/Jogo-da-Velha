#include "headers/jogadorRemoto.h"
#include "headers/partida.h"

#define PORTA 8080
#define IP_SERVIDOR "127.0.0.1"

int main(){
    conecta(IP_SERVIDOR, PORTA);
    inicia(0); 
    return 0;
}