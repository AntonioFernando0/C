#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 5
#define NAVIOS 3

// Função para inicializar o tabuleiro
void inicializarTabuleiro(char tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = '~'; // Água
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(char tabuleiro[TAMANHO][TAMANHO], int revelar) {
    printf("  0 1 2 3 4\n");
    for (int i = 0; i < TAMANHO; i++) {
        printf("%d ", i);
        for (int j = 0; j < TAMANHO; j++) {
            if (revelar || tabuleiro[i][j] != 'N') {
                printf("%c ", tabuleiro[i][j]);
            } else {
                printf("~ ");
            }
        }
        printf("\n");
    }
}

// Função para posicionar navios aleatoriamente
void posicionarNavios(char tabuleiro[TAMANHO][TAMANHO]) {
    srand(time(NULL));
    int naviosColocados = 0;

    while (naviosColocados < NAVIOS) {
        int linha = rand() % TAMANHO;
        int coluna = rand() % TAMANHO;

        if (tabuleiro[linha][coluna] != 'N') { // 'N' indica navio
            tabuleiro[linha][coluna] = 'N';
            naviosColocados++;
        }
    }
}

// Função para realizar um ataque
int realizarAtaque(char tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    if (tabuleiro[linha][coluna] == 'N') {
        printf("Acertou! Navio afundado!\n");
        tabuleiro[linha][coluna] = 'X'; // Marca acerto
        return 1;
    } else if (tabuleiro[linha][coluna] == '~') {
        printf("Errou! Água!\n");
        tabuleiro[linha][coluna] = 'O'; // Marca erro
    } else {
        printf("Já atacou essa posição!\n");
    }
    return 0;
}

int main() {
    char tabuleiro[TAMANHO][TAMANHO];
    int acertos = 0;
    int tentativas = 0;

    inicializarTabuleiro(tabuleiro);
    posicionarNavios(tabuleiro);

    printf("=== Batalha Naval ===\n");
    printf("Há %d navios ocultos no tabuleiro!\n", NAVIOS);

    while (acertos < NAVIOS) {
        exibirTabuleiro(tabuleiro, 0);
        int linha, coluna;

        printf("Digite a linha (0 a 4) e a coluna (0 a 4) para atacar: ");
        scanf("%d %d", &linha, &coluna);

        if (linha < 0 || linha >= TAMANHO || coluna < 0 || coluna >= TAMANHO) {
            printf("Posição inválida! Tente novamente.\n");
            continue;
        }

        acertos += realizarAtaque(tabuleiro, linha, coluna);
        tentativas++;
    }

    printf("\nTodos os navios foram afundados em %d tentativas!\n", tentativas);
    printf("Tabuleiro final:\n");
    exibirTabuleiro(tabuleiro, 1);

    return 0;
}
