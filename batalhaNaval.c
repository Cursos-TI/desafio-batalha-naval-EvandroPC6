#include <stdio.h>
#include <stdlib.h>

#define LINHA 10
#define COLUNA 10

int main() {

    char Linhas[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'}; // Linhas do tabuleiro

    int tabuleiro [LINHA][COLUNA]; // Tabuleiro 10x10 inicializado com 0 (vazio)
    int agua = 0; // Variável para preencher o tabuleiro

    // Inicializa o tabuleiro com 0 (vazio)
    printf("Tabuleiro:\n");
    printf("  1 2 3 4 5 6 7 8 9 10\n");
    for (int i = 0; i < LINHA; i++) {
        printf("%c ", Linhas[i]);
        for (int j = 0; j < COLUNA; j++) {
            tabuleiro[i][j] = agua;
            if (tabuleiro[i][j] == agua) {
                printf("0 "); // Água
            }
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
            if (tabuleiro[i][j] == agua) {
                printf("0 "); // Água
            } else if (tabuleiro[i][j] == 3) {
                printf("3 "); // Navio
            }
        }
        printf("\n");
    }

    // Matrizes de habilidades
    int cone[5][5] = {0};
    int cruz[5][5] = {0};
    int octaedro[5][5] = {0};

    // Preenche a matriz cone
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (j >= 2 - i && j <= 2 + i && i <= 2) {
                cone[i][j] = 1;
            }
        }
    }

    // Preenche a matriz cruz
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 2 || j == 2) {
                cruz[i][j] = 1;
            }
        }
    }

    // Preenche a matriz octaedro
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (abs(i - 2) + abs(j - 2) <= 2) {
                octaedro[i][j] = 1;
            }
        }
    }

    // Define o ponto de origem para cada habilidade no tabuleiro
    int origem_cone_x = 4, origem_cone_y = 2;
    int origem_cruz_x = 7, origem_cruz_y = 5;
    int origem_octaedro_x = 2, origem_octaedro_y = 7;

    // Aplica a matriz cone no tabuleiro
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int x = origem_cone_x + i - 2;
            int y = origem_cone_y + j - 2;
            if (x >= 0 && x < LINHA && y >= 0 && y < COLUNA && cone[i][j] == 1) {
                tabuleiro[x][y] = 5;
            }
        }
    }

    // Aplica a matriz cruz no tabuleiro
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int x = origem_cruz_x + i - 2;
            int y = origem_cruz_y + j - 2;
            if (x >= 0 && x < LINHA && y >= 0 && y < COLUNA && cruz[i][j] == 1) {
                tabuleiro[x][y] = 5;
            }
        }
    }

    // Aplica a matriz octaedro no tabuleiro
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int x = origem_octaedro_x + i - 2;
            int y = origem_octaedro_y + j - 2;
            if (x >= 0 && x < LINHA && y >= 0 && y < COLUNA && octaedro[i][j] == 1) {
                tabuleiro[x][y] = 5;
            }
        }
    }

    // Exibe o tabuleiro atualizado com as habilidades
    printf("\nTabuleiro com habilidades:\n");
    printf("  1 2 3 4 5 6 7 8 9 10\n");
    for (int i = 0; i < LINHA; i++) {
        printf("%c ", Linhas[i]);
        for (int j = 0; j < COLUNA; j++) {
            if (tabuleiro[i][j] == agua) {
                printf("0 "); // Água
            } else if (tabuleiro[i][j] == 3) {
                printf("3 "); // Navio
            } else if (tabuleiro[i][j] == 5) {
                printf("1 "); // Área afetada
            }
        }
        printf("\n");
    }

    return 0;
}