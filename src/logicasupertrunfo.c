#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar uma carta do Super Trunfo
struct Carta {
    char nome[50];
    int forca;
    int velocidade;
    int inteligencia;
};

// Função para mostrar o menu de atributos
void mostrarMenu() {
    printf("\nEscolha o atributo para a comparação:\n");
    printf("1. Força\n");
    printf("2. Velocidade\n");
    printf("3. Inteligência\n");
    printf("Opção: ");
}

// Função para comparar um único atributo (Desafio 1)
void compararAtributoSimples(struct Carta c1, struct Carta c2) {
    int opcao;
    mostrarMenu();
    scanf("%d", &opcao);

    if (opcao == 1) {
        printf("\nComparando Força...\n");
        if (c1.forca > c2.forca)
            printf("%s venceu!\n", c1.nome);
        else if (c1.forca < c2.forca)
            printf("%s venceu!\n", c2.nome);
        else
            printf("Empate!\n");
    }
    else if (opcao == 2) {
        printf("\nComparando Velocidade...\n");
        if (c1.velocidade > c2.velocidade)
            printf("%s venceu!\n", c1.nome);
        else if (c1.velocidade < c2.velocidade)
            printf("%s venceu!\n", c2.nome);
        else
            printf("Empate!\n");
    }
    else if (opcao == 3) {
        printf("\nComparando Inteligência...\n");
        if (c1.inteligencia > c2.inteligencia)
            printf("%s venceu!\n", c1.nome);
        else if (c1.inteligencia < c2.inteligencia)
            printf("%s venceu!\n", c2.nome);
        else
            printf("Empate!\n");
    }
    else {
        printf("Opção inválida!\n");
    }
}

// Função para comparação com múltiplos atributos (Desafio 2)
void compararMultiplosAtributos(struct Carta c1, struct Carta c2) {
    int opcao;
    mostrarMenu();
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            printf("\nComparando Força e Velocidade...\n");
            if (c1.forca > c2.forca && c1.velocidade > c2.velocidade)
                printf("%s venceu!\n", c1.nome);
            else if (c2.forca > c1.forca && c2.velocidade > c1.velocidade)
                printf("%s venceu!\n", c2.nome);
            else
                printf("Empate ou comparação indefinida!\n");
            break;
        case 2:
            printf("\nComparando Velocidade e Inteligência...\n");
            if (c1.velocidade > c2.velocidade && c1.inteligencia > c2.inteligencia)
                printf("%s venceu!\n", c1.nome);
            else if (c2.velocidade > c1.velocidade && c2.inteligencia > c1.inteligencia)
                printf("%s venceu!\n", c2.nome);
            else
                printf("Empate ou comparação indefinida!\n");
            break;
        case 3:
            printf("\nComparando Força e Inteligência...\n");
            if (c1.forca > c2.forca && c1.inteligencia > c2.inteligencia)
                printf("%s venceu!\n", c1.nome);
            else if (c2.forca > c1.forca && c2.inteligencia > c1.inteligencia)
                printf("%s venceu!\n", c2.nome);
            else
                printf("Empate ou comparação indefinida!\n");
            break;
        default:
            printf("Opção inválida!\n");
    }
}

// Função para comparação com base em dois atributos (Desafio 3)
void compararDoisAtributos(struct Carta c1, struct Carta c2) {
    int opcao;
    mostrarMenu();
    scanf("%d", &opcao);

    printf("\nComparação complexa...\n");
    // Utilização de operador ternário para definir o vencedor
    char *vencedor = (opcao == 1 && c1.forca + c1.inteligencia > c2.forca + c2.inteligencia) ? c1.nome :
                     (opcao == 2 && c1.velocidade + c1.inteligencia > c2.velocidade + c2.inteligencia) ? c1.nome :
                     (opcao == 3 && c1.forca + c1.velocidade > c2.forca + c2.velocidade) ? c1.nome : c2.nome;

    printf("O vencedor é: %s\n", vencedor);
}

int main() {
    struct Carta carta1 = {"Herói A", 80, 90, 85};
    struct Carta carta2 = {"Herói B", 75, 88, 90};

    printf("--- Super Trunfo ---\n");
    printf("1. Comparação simples (Desafio 1)\n");
    printf("2. Comparação múltipla (Desafio 2)\n");
    printf("3. Comparação complexa (Desafio 3)\n");
    printf("Escolha o tipo de comparação: ");

    int tipo;
    scanf("%d", &tipo);

    switch (tipo) {
        case 1:
            compararAtributoSimples(carta1, carta2);
            break;
        case 2:
            compararMultiplosAtributos(carta1, carta2);
            break;
        case 3:
            compararDoisAtributos(carta1, carta2);
            break;
        default:
            printf("Opção inválida!\n");
    }

    return 0;
}
