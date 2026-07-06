#include "headers/jogadorRemoto.h"
#include "headers/tabuleiro.h"
#include "headers/partida.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

static int socket_conexao = -1;

void acceptConexao(int porta){
    int servidor_fd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in endereco;
    int opt = 1;

    setsockopt(servidor_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    endereco.sin_family = AF_INET;
    endereco.sin_addr.s_addr = INADDR_ANY;
    endereco.sin_port = htons(porta);

    bind(servidor_fd, (struct sockaddr *)&endereco, sizeof(endereco));
    listen(servidor_fd, 1);
    
    printf("Aguardando conexao do adversario na porta %d...\n", porta);
    socket_conexao = accept(servidor_fd, NULL, NULL);
    printf("Adversario conectado!\n");
    close(servidor_fd);
}

void conecta(const char* ip, int porta){
    socket_conexao = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv_addr;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(porta);
    inet_pton(AF_INET, ip, &serv_addr.sin_addr);

    printf("Conectando ao servidor...\n");
    while (connect(socket_conexao, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        sleep(1);
    }
    printf("Conectado com sucesso!\n");
}

void enviaJogada(int x, int y){
    char buffer[16];
    sprintf(buffer, "%d %d", x, y);
    send(socket_conexao, buffer, strlen(buffer) + 1, 0);
}

void jogaRemoto(int (*tabuleiro)[3], int tipoRemoto){
    char buffer[16];
    memset(buffer, 0, sizeof(buffer));
    
    printf("\nAguardando jogada do adversario...\n");
    int bytes = recv(socket_conexao, buffer, sizeof(buffer) - 1, 0);
    
    if (bytes <= 0) {
        printf("Conexao perdida com o adversario!\n");
        exit(1);
    }

    int x, y;
    sscanf(buffer, "%d %d", &x, &y);
    marcajogada(x, y, tipoRemoto, tabuleiro);
    printf("O adversario jogou na posicao (%d, %d):\n", x, y);
}

void fecharConexao(){
    if(socket_conexao != -1) {
        close(socket_conexao);
    }       
}