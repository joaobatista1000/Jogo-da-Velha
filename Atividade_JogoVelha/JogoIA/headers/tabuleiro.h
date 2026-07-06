#ifndef TABULEIRO_H
#define TABULEIRO_H

void exibirJogo(int coord[3][3]);
int validador(int coord[3][3]);
int vencedor(int soma);
void marcajogada(int x, int y, int tipo, int (*tabuleiro)[3]);

#endif