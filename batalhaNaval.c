#include <stdio.h>
#include <stdlib.h>

#define LINHA 10
#define COLUNA 10

int main() {

    char Linhas[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'}; // Linha do tabuleiro

    int tabuleiro [LINHA][COLUNA]; // Tabuleiro 10x10 inicializado com 0 (vazio)
    int agua = 0; // Variável para preencher o tabuleiro

    // Inicializa o tabuleiro com 0 (vazio)
    printf("Tabuleiro:\n");
    printf("  1 2 3 4 5 6 7 8 9 10\n");
    for (int i = 0; i < LINHA; i++) {
        printf("%c ", Linhas[i]);
        for (int j = 0; j < COLUNA; j++) {

            tabuleiro[i][j] = agua;
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    // Inicializa os navios com tamanho fixo de 3 posições
    int navio_horizontal[3] = {0}; // Coordenadas y para o navio horizontal
    int navio_vertical[3] = {0};   // Coordenadas x para o navio vertical
    int navio_diagonal1[3] = {0};  // Coordenadas x e y para o navio diagonal
    int navio_diagonal2[3] = {0};  // Coordenadas x e y para o navio diagonal2

    // Define a posição inicial do navio horizontal
    int x_horizontal = 2; // Linha fixa
    int y_horizontal = 4; // Coluna inicial
    for (int i = 0; i < 3; i++) {
        navio_horizontal[i] = y_horizontal + i; // Preenche as colunas consecutivas
        tabuleiro[x_horizontal][navio_horizontal[i]] = 3; // Marca no tabuleiro
    }

    // Define a posição inicial do navio vertical
    int x_vertical = 6; // Linha inicial
    int y_vertical = 7; // Coluna fixa
    for (int i = 0; i < 3; i++) {
        navio_vertical[i] = x_vertical + i; // Preenche as linhas consecutivas
        tabuleiro[navio_vertical[i]][y_vertical] = 3; // Marca no tabuleiro
    }

    // Define a posição inicial do navio diagonal1 (linha e coluna aumentam simultaneamente)
    int x_diagonal1 = 0; // Linha inicial
    int y_diagonal1 = 0; // Coluna inicial
    for (int i = 0; i < 3; i++) {
        navio_diagonal1[i] = x_diagonal1 + i; // Preenche as linhas consecutivas
        tabuleiro[navio_diagonal1[i]][y_diagonal1 + i] = 3; // Marca no tabuleiro
    }

    // Define a posição inicial do navio diagonal2 (linha aumenta e coluna diminui simultaneamente)
    int x_diagonal2 = 5; // Linha inicial
    int y_diagonal2 = 5; // Coluna inicial
    for (int i = 0; i < 3; i++) {
        navio_diagonal2[i] = x_diagonal2 + i; // Preenche as linhas consecutivas
        tabuleiro[navio_diagonal2[i]][y_diagonal2 - i] = 3; // Marca no tabuleiro
    }

    // Exibe o tabuleiro atualizado com os navios
    printf("\nTabuleiro com navios:\n");
    printf("  1 2 3 4 5 6 7 8 9 10\n");
    for (int i = 0; i < LINHA; i++) {
        printf("%c ", Linhas[i]);
        for (int j = 0; j < COLUNA; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
        
    return 0;
}