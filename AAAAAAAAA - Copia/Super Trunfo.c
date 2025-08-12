#include <stdio.h>

typedef struct {
    char nome[50];
    char estado[30];
    char Codigo[3];
    float pib;
    int populacao;
    float area;
    int pontosTuristicos;
} Carta;

int main() {
    Carta c1, c2;
    

    printf("nome da cidade: ");
    scanf("%49s", c1.nome);

    printf("estado principal: ");
    scanf("%29s", c1.estado);

    printf("Codigo(2Digito): ");
    scanf("%2s", c1.Codigo);

    printf("PIB: ");
    scanf("%f", &c1.pib);

    printf("população (em milhões): ");
    scanf("%d", &c1.populacao);

    printf("área (em km2):");
    scanf("%f", &c1.area );

    printf("Numero de pontos Turisticos: ");
    scanf("%d", &c1.pontosTuristicos);

    printf("                  \n");

    printf("nome da cidade: ");
    scanf("%49s", c2.nome);

    printf("estado principal: ");
    scanf("%29s", c2.estado);

    printf("Codigo(2dIGITO): ");
    scanf("%2s", c2.Codigo);

    printf("PIB: ");
    scanf("%f", &c2.pib);

    printf("população (em milhões): ");
    scanf("%d", &c2.populacao);

    printf("área (em km2):");
    scanf("%f", &c2.area );

    printf("Numero de pontos Turisticos: ");
    scanf("%d", &c2.pontosTuristicos);

    printf("                  \n");
    printf("carta 1:\n");
    printf("Codigo: %s\n", c1.Codigo);
    printf("Nome da cidade: %s\n", c1.nome);
    printf("estado: %s\n", c1.estado);
    printf("PIB: %.2f Bilhões de reais\n", c1.pib);
    printf("população: %d milhões\n", c1.populacao);
    printf("área: %.2f km2\n", c1.area);
    printf("Numero de pontos Turisticos: %d\n", c1.pontosTuristicos);

    printf("                  \n");
    printf("carta 2:\n");
    printf("Codigo: %s\n", c2.Codigo);
    printf("Nome da cidade: %s\n", c2.nome);
    printf("estado: %s\n", c2.estado);
    printf("PIB: %.2f Bilhões de reais\n", c2.pib);
    printf("população: %d milhões\n", c2.populacao);
    printf("área: %.2f km2\n", c2.area);
    printf("Numero de pontos Turisticos: %d\n", c2.pontosTuristicos);
    return 0;
    
}
