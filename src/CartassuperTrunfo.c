#include <stdio.h>

struct Cidade {
    char estado[3];
    int codigo;
    char nome[50];
    int populacao;
    double pib;
    double area;
    int pontos_turisticos;
    double densidade_populacional;
    double pib_per_capita;
};

// Função para registrar dados de uma cidade
struct Cidade registrarCidade() {
    struct Cidade c;

    printf("Digite o estado (sigla com 2 letras): ");
    scanf("%2s", c.estado);

    printf("Digite o código da cidade: ");
    scanf("%d", &c.codigo);

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", c.nome);

    printf("Digite a população da cidade: ");
    scanf("%d", &c.populacao);

    printf("Digite o PIB da cidade: ");
    scanf("%lf", &c.pib);

    printf("Digite a área da cidade (em km²): ");
    scanf("%lf", &c.area);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &c.pontos_turisticos);

    // Cálculo das propriedades derivadas
    c.densidade_populacional = c.populacao / c.area;
    c.pib_per_capita = c.pib / c.populacao;

    return c;
}

// Função para exibir os dados de uma cidade
void exibirCidade(struct Cidade c) {
    printf("\n--- Dados da Cidade ---\n");
    printf("Estado: %s\n", c.estado);
    printf("Código: %d\n", c.codigo);
    printf("Nome: %s\n", c.nome);
    printf("População: %d\n", c.populacao);
    printf("PIB: %.2lf\n", c.pib);
    printf("Área: %.2lf km²\n", c.area);
    printf("Pontos turísticos: %d\n", c.pontos_turisticos);
    printf("Densidade Populacional: %.2lf hab/km²\n", c.densidade_populacional);
    printf("PIB per capita: %.2lf\n", c.pib_per_capita);
    printf("-----------------------\n");
}

int main() {
    struct Cidade cidade;

    cidade = registrarCidade();
    exibirCidade(cidade);

    return 0;
}
