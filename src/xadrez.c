#include <stdio.h>

// Função para exibir o tabuleiro de 8x8
void exibirTabuleiro(int x, int y) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (i == x && j == y)
                printf(" P ");  // Posição da peça
            else
                printf(" . ");
        }
        printf("\n");
    }
}

// Movimento da Torre (linha ou coluna)
void movimentoTorre(int x, int y) {
    printf("\nMovimento da Torre a partir da posição (%d, %d):\n", x, y);
    for (int i = 0; i < 8; i++) {
        if (i != x)
            printf("(%d, %d) ", i, y);  // Movimentos verticais
        if (i != y)
            printf("(%d, %d) ", x, i);  // Movimentos horizontais
    }
    printf("\n");
    exibirTabuleiro(x, y);
}

// Movimento do Bispo (diagonais)
void movimentoBispo(int x, int y) {
    printf("\nMovimento do Bispo a partir da posição (%d, %d):\n", x, y);
    for (int i = 1; i < 8; i++) {
        // Diagonais principais
        if (x + i < 8 && y + i < 8)
            printf("(%d, %d) ", x + i, y + i);
        if (x - i >= 0 && y - i >= 0)
            printf("(%d, %d) ", x - i, y - i);

        // Diagonais secundárias
        if (x + i < 8 && y - i >= 0)
            printf("(%d, %d) ", x + i, y - i);
        if (x - i >= 0 && y + i < 8)
            printf("(%d, %d) ", x - i, y + i);
    }
    printf("\n");
    exibirTabuleiro(x, y);
}

// Movimento da Rainha (torre + bispo)
void movimentoRainha(int x, int y) {
    printf("\nMovimento da Rainha a partir da posição (%d, %d):\n", x, y);

    // Torre (horizontal e vertical)
    for (int i = 0; i < 8; i++) {
        if (i != x)
            printf("(%d, %d) ", i, y);  // Vertical
        if (i != y)
            printf("(%d, %d) ", x, i);  // Horizontal
    }

    // Bispo (diagonais)
    for (int i = 1; i < 8; i++) {
        if (x + i < 8 && y + i < 8)
            printf("(%d, %d) ", x + i, y + i);
        if (x - i >= 0 && y - i >= 0)
            printf("(%d, %d) ", x - i, y - i);
        if (x + i < 8 && y - i >= 0)
            printf("(%d, %d) ", x + i, y - i);
        if (x - i >= 0 && y + i < 8)
            printf("(%d, %d) ", x - i, y + i);
    }

    printf("\n");
    exibirTabuleiro(x, y);
}

// Movimento do Cavalo (movimento em "L")
void movimentoCavalo(int x, int y) {
    printf("\nMovimento do Cavalo a partir da posição (%d, %d):\n", x, y);

    // Todas as possibilidades do movimento em "L"
    int movL[8][2] = {
        {x + 2, y + 1}, {x + 2, y - 1},
        {x - 2, y + 1}, {x - 2, y - 1},
        {x + 1, y + 2}, {x + 1, y - 2},
        {x - 1, y + 2}, {x - 1, y - 2}
    };

    for (int i = 0; i < 8; i++) {
        int nx = movL[i][0];
        int ny = movL[i][1];
        if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8) {
            printf("(%d, %d) ", nx, ny);
        }
    }
    printf("\n");
    exibirTabuleiro(x, y);
}

int main() {
    int x, y, opcao;

    printf("Digite a posição inicial da peça (linha e coluna de 0 a 7): ");
    scanf("%d %d", &x, &y);

    printf("\nEscolha a peça para simular o movimento:\n");
    printf("1. Torre\n");
    printf("2. Bispo\n");
    printf("3. Rainha\n");
    printf("4. Cavalo\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            movimentoTorre(x, y);
            break;
        case 2:
            movimentoBispo(x, y);
            break;
        case 3:
            movimentoRainha(x, y);
            break;
        case 4:
            movimentoCavalo(x, y);
            break;
        default:
            printf("Opção inválida!\n");
    }

    return 0;
}
