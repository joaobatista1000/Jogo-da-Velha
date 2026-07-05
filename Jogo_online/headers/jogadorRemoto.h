#ifndef JOGADOR_REMOTO_H
#define JOGADOR_REMOTO_H

void acceptConexao(int porta);
void conecta(const char* ip, int porta);
void enviaJogada(int x, int y);
void jogaRemoto(int (*tabuleiro)[3], int tipoRemoto);
void fecharConexao();

#endif
