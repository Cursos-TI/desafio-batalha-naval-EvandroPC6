#include <stdio.h>
#include<stdlib.h>

int main() {

    char linha[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}; // Linhas do tabuleiro

    int i, j; // Variáveis de controle para os loops
    
    int tabuleiro[10][10] = {0}; // Tabuleiro 10x10 inicializado com 0 (vazio)

    // Inicializa o tabuleiro com 0 (vazio)
    printf("Tabuleiro:\n");
    printf("  A B C D E F G H I J\n");
    for (i = 0; i < 10; i++) {
        printf("%c ", linha[i]);
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    // Inicializa os navios com tamanho fixo de 3 posições
    int navio_horizontal[3] = {0}; // Coordenadas y para o navio horizontal
    int navio_vertical[3] = {0};   // Coordenadas x para o navio vertical

    // Define a posição inicial do navio horizontal
    int x_horizontal = 2; // Linha fixa
    int y_horizontal = 4; // Coluna inicial
    for (i = 0; i < 3; i++) {
        navio_horizontal[i] = y_horizontal + i; // Preenche as colunas consecutivas
        tabuleiro[x_horizontal][navio_horizontal[i]] = 3; // Marca no tabuleiro
    }

    // Define a posição inicial do navio vertical
    int x_vertical = 6; // Linha inicial
    int y_vertical = 7; // Coluna fixa
    for (i = 0; i < 3; i++) {
        navio_vertical[i] = x_vertical + i; // Preenche as linhas consecutivas
        tabuleiro[navio_vertical[i]][y_vertical] = 3; // Marca no tabuleiro
    }

    // Exibe o tabuleiro atualizado com os navios
    printf("\nTabuleiro com navios:\n");
    printf("  A B C D E F G H I J\n");
    for (i = 0; i < 10; i++) {
        printf("%c ", linha[i]);
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    return 0;
}