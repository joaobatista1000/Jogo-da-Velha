#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "headers/tabuleiro.h"

void jogadaIA(int (*tabuleiro)[3]) {

    // R1. OPONENTE GANHANDO
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] + tabuleiro[i][1] + tabuleiro[i][2] == 2) {
            if (tabuleiro[i][0] == 0) { tabuleiro[i][0] = 1; return; }
            else if (tabuleiro[i][1] == 0) { tabuleiro[i][1] = 1; return; }
            else if (tabuleiro[i][2] == 0) { tabuleiro[i][2] = 1; return; }
        }
      
        if (tabuleiro[0][i] + tabuleiro[1][i] + tabuleiro[2][i] == 2) {
            if (tabuleiro[0][i] == 0) { tabuleiro[0][i] = 1; return; }
            else if (tabuleiro[1][i] == 0) { tabuleiro[1][i] = 1; return; }
            else if (tabuleiro[2][i] == 0) { tabuleiro[2][i] = 1; return; }
        }
    }
  
    if (tabuleiro[0][0] + tabuleiro[1][1] + tabuleiro[2][2] == 2) {
        if (tabuleiro[0][0] == 0) { tabuleiro[0][0] = 1; return; }
        else if (tabuleiro[1][1] == 0) { tabuleiro[1][1] = 1; return; }
        else if (tabuleiro[2][2] == 0) { tabuleiro[2][2] = 1; return; }
    }

    if (tabuleiro[0][2] + tabuleiro[1][1] + tabuleiro[2][0] == 2) {
        if (tabuleiro[0][2] == 0) { tabuleiro[1][1] = 1; return; }
        else if (tabuleiro[2][0] == 0) { tabuleiro[2][0] = 1; return; }
    }

    // R1 OPONENTE PERDENDO\
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] + tabuleiro[i][1] + tabuleiro[i][2] == 8) {
            if (tabuleiro[i][0] == 0) { tabuleiro[i][0] = 1; return; }
            else if (tabuleiro[i][1] == 0) { tabuleiro[i][1] = 1; return; }
            else if (tabuleiro[i][2] == 0) { tabuleiro[i][2] = 1; return; }
        }
      
        if (tabuleiro[0][i] + tabuleiro[1][i] + tabuleiro[2][i] == 8) {
            if (tabuleiro[0][i] == 0) { tabuleiro[0][i] = 1; return; }
            else if (tabuleiro[1][i] == 0) { tabuleiro[1][i] = 1; return; }
            else if (tabuleiro[2][i] == 0) { tabuleiro[2][i] = 1; return; }
        }
    }
    
    if (tabuleiro[0][0] + tabuleiro[1][1] + tabuleiro[2][2] == 8) {
        if (tabuleiro[0][0] == 0) { tabuleiro[0][0] = 1; return; }
        else if (tabuleiro[1][1] == 0) { tabuleiro[1][1] = 1; return; }
        else if (tabuleiro[2][2] == 0) { tabuleiro[2][2] = 1; return; }
    }

    if (tabuleiro[0][2] + tabuleiro[1][1] + tabuleiro[2][0] == 8) {
        if (tabuleiro[0][2] == 0) { tabuleiro[0][2] = 1; return; }
        else if (tabuleiro[1][1] == 0) { tabuleiro[1][1] = 1; return; }
        else if (tabuleiro[2][0] == 0) { tabuleiro[2][0] = 1; return; }
    }

    // R2
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tabuleiro[i][j] == 0) {
                tabuleiro[i][j] = 1; 
                int jogada = 0;
                
                for(int k = 0; k < 3; k++) {
                    if (tabuleiro[k][0] + tabuleiro[k][1] + tabuleiro[k][2] == 2) jogada++;
                    if (tabuleiro[0][k] + tabuleiro[1][k] + tabuleiro[2][k] == 2) jogada++;
                }

                if (tabuleiro[0][0] + tabuleiro[1][1] + tabuleiro[2][2] == 2) jogada++;
                if (tabuleiro[0][2] + tabuleiro[1][1] + tabuleiro[2][0] == 2) jogada++;
                
                if (jogada >= 2) {
                    return; 
                } else {
                    tabuleiro[i][j] = 0; 
                }
            }
        }
    }

    // R3
    if (tabuleiro[1][1] == 0) { tabuleiro[1][1] = 1; return; }

    // R4
    if (tabuleiro[0][0] == 4 && tabuleiro[2][2] == 0) { tabuleiro[2][2] = 1; return; }
    if (tabuleiro[2][2] == 4 && tabuleiro[0][0] == 0) { tabuleiro[0][0] = 1; return; }
    if (tabuleiro[0][2] == 4 && tabuleiro[2][0] == 0) { tabuleiro[2][0] = 1; return; }
    if (tabuleiro[2][0] == 4 && tabuleiro[0][2] == 0) { tabuleiro[0][2] = 1; return; }

    // R5
    if (tabuleiro[0][0] == 0) { tabuleiro[0][0] = 1; return; }
    if (tabuleiro[0][2] == 0) { tabuleiro[0][2] = 1; return; }
    if (tabuleiro[2][0] == 0) { tabuleiro[2][0] = 1; return; }
    if (tabuleiro[2][2] == 0) { tabuleiro[2][2] = 1; return; }

    // R6
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tabuleiro[i][j] == 0) {
                tabuleiro[i][j] = 1;
                return;
            }
        }
    }
}