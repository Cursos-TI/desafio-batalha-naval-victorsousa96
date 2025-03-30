#include <stdio.h>
#define SIZE 10

void inicializarTabuleiro(int tabuleiro[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

void exibirTabuleiro(int tabuleiro[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

void posicionarNavios(int tabuleiro[SIZE][SIZE]) {
    tabuleiro[2][2] = 3;
    tabuleiro[3][2] = 3;
    tabuleiro[4][2] = 3;
    
    tabuleiro[6][4] = 3;
    tabuleiro[6][5] = 3;
    tabuleiro[6][6] = 3;
    
    tabuleiro[1][8] = 3;
    tabuleiro[2][7] = 3;
    tabuleiro[3][6] = 3;
}

void aplicarHabilidadeCruz(int tabuleiro[SIZE][SIZE], int x, int y) {
    for (int i = 0; i < SIZE; i++) {
        tabuleiro[i][y] = 1;
    }
    for (int j = 0; j < SIZE; j++) {
        tabuleiro[x][j] = 1;
    }
}

void aplicarHabilidadeCone(int tabuleiro[SIZE][SIZE], int x, int y) {
    if (x < SIZE - 2) {
        tabuleiro[x + 1][y] = 1;
        if (y > 0) tabuleiro[x + 1][y - 1] = 1;
        if (y < SIZE - 1) tabuleiro[x + 1][y + 1] = 1;
        if (x < SIZE - 3) tabuleiro[x + 2][y] = 1;
    }
}

void aplicarHabilidadeOctaedro(int tabuleiro[SIZE][SIZE], int x, int y) {
    if (x > 0) tabuleiro[x - 1][y] = 1;
    if (x < SIZE - 1) tabuleiro[x + 1][y] = 1;
    if (y > 0) tabuleiro[x][y - 1] = 1;
    if (y < SIZE - 1) tabuleiro[x][y + 1] = 1;
}

int main() {
    int tabuleiro[SIZE][SIZE];
    inicializarTabuleiro(tabuleiro);
    
    posicionarNavios(tabuleiro);
    printf("Tabuleiro com navios:\n");
    exibirTabuleiro(tabuleiro);
    
    aplicarHabilidadeCruz(tabuleiro, 5, 5);
    printf("\nTabuleiro com habilidade Cruz:\n");
    exibirTabuleiro(tabuleiro);
    
    aplicarHabilidadeCone(tabuleiro, 2, 2);
    printf("\nTabuleiro com habilidade Cone:\n");
    exibirTabuleiro(tabuleiro);
    
    aplicarHabilidadeOctaedro(tabuleiro, 7, 7);
    printf("\nTabuleiro com habilidade Octaedro:\n");
    exibirTabuleiro(tabuleiro);
    
    return 0;
}
