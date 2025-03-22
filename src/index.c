#include <stdio.h>

// Definição da estrutura para representar uma carta
typedef struct {
    char estado[50];      // Estado da cidade
    char codigo[20];      // Código da carta
    char cidade[50];      // Nome da cidade
    int populacao;        // População da cidade
    float area;           // Área da cidade
    float pib;            // PIB da cidade
    int pontos_turisticos; // Número de pontos turísticos
} Carta;

// Função para calcular a densidade populacional
float calcularDensidadePopulacional(Carta carta) {
    return (float)carta.populacao / carta.area;
}

// Função para calcular o PIB per capita
float calcularPibPerCapita(Carta carta) {
    return carta.pib / carta.populacao;
}

int main() {
    // Cartas pré-definidas
    Carta carta1 = {"São Paulo", "SP123", "São Paulo", 12300000, 1500.0, 520000, 30};
    Carta carta2 = {"Rio de Janeiro", "RJ456", "Rio de Janeiro", 6000000, 1200.0, 450000, 25};

    // Atributo escolhido para comparação (pode ser População, Área, PIB, Densidade Populacional ou PIB per capita)
    // Para este exemplo, a comparação será feita pela População
    char atributoComparacao[] = "População";

    int vencedor;  // Variável para armazenar o índice da carta vencedora (1 para carta1, 2 para carta2)

    printf("Comparação de cartas (Atributo: %s):\n", atributoComparacao);
    printf("Carta 1 - %s (%s): %d\n", carta1.cidade, carta1.estado, carta1.populacao);
    printf("Carta 2 - %s (%s): %d\n", carta2.cidade, carta2.estado, carta2.populacao);

    // Comparação dos atributos
    if (strcmp(atributoComparacao, "População") == 0) {
        // Comparar População: maior valor vence
        if (carta1.populacao > carta2.populacao) {
            vencedor = 1;
        } else {
            vencedor = 2;
        }
    } else if (strcmp(atributoComparacao, "Área") == 0) {
        // Comparar Área: maior valor vence
        if (carta1.area > carta2.area) {
            vencedor = 1;
        } else {
            vencedor = 2;
        }
    } else if (strcmp(atributoComparacao, "PIB") == 0) {
        // Comparar PIB: maior valor vence
        if (carta1.pib > carta2.pib) {
            vencedor = 1;
        } else {
            vencedor = 2;
        }
    } else if (strcmp(atributoComparacao, "Densidade Populacional") == 0) {
        // Comparar Densidade Populacional: menor valor vence
        if (calcularDensidadePopulacional(carta1) < calcularDensidadePopulacional(carta2)) {
            vencedor = 1;
        } else {
            vencedor = 2;
        }
    } else if (strcmp(atributoComparacao, "PIB per capita") == 0) {
        // Comparar PIB per capita: maior valor vence
        if (calcularPibPerCapita(carta1) > calcularPibPerCapita(carta2)) {
            vencedor = 1;
        } else {
            vencedor = 2;
        }
    }

    // Exibir o resultado da comparação
    if (vencedor == 1) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
    } else {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
    }

    return 0;
}
