#ifndef TABULEIRO_H
#define TABULEIRO_H

#include <stdbool.h>

void marcajogada(int x, int y, int tipo, int (*tabuleiro)[3]);
void exibirJogo(int (*tabuleiro)[3]);
int vencedor(int soma);
int validador(int (*tabuleiro)[3]);

#endif
