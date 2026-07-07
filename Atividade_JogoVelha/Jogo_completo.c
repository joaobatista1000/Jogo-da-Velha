#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int escolha_jogador = 0;
    while (escolha_jogador != 4) {
        printf("Escolha:\n");
        printf("(1) Jogo Normal\n");
        printf("(2) Jogo contra a IA\n");
        printf("(3) Jogo online (com sockets)\n");
        printf("(4) Sair\n");
        printf("> ");
        if (scanf("%d", &escolha_jogador) != 1) {
            printf("Entrada invalida!\n");
            while (getchar() != '\n');
            continue;
        }
        switch (escolha_jogador) {
            case 1:
                system("clear");
                system("\"Jogo_normal/jogo.exe\"");
                sleep(3);
                system("clear");
                break;
            case 2:
                system("clear");
                system("\"JogoIA/teste.exe\"");
                sleep(3);
                system("clear");
                break;
            case 3: {
                int escolha_jogo_online = 0;
                while (escolha_jogo_online != 3) {
                    printf("Digite:\n");
                    printf("(1) Servidor\n");
                    printf("(2) Cliente\n");
                    printf("(3) Sair\n");
                    printf("> ");
                    if (scanf("%d", &escolha_jogo_online) != 1) {
                        printf("Entrada invalida!\n");
                        while (getchar() != '\n');
                        continue;
                    }
                    switch (escolha_jogo_online) {
                        case 1:
                            system("clear");
                            system("\"Jogo_online/servidor.exe\"");
                            sleep(3);
                            system("clear");
                            break;
                        case 2:
                            system("clear");
                            system("\"Jogo_online/cliente.exe\"");
                            sleep(3);
                            system("clear");
                            break;
                        case 3:
                            system("clear");
                            break;
                        default:
                            printf("Erro! Tente novamente.\n");
                            break;
                    }
                }
                break;
            }
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Erro! Tente novamente.\n");
                break;
        }
    }
    return 0;
}
