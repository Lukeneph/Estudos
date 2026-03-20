#include <stdio.h>

typedef struct {
    char estado;
    char codigo[4];
    char nomeCidade[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float SuperPoder;
    
    
} Carta;
 // Função principal
int main() {
    Carta c1, c2;
    
    printf("estado (A-H): ");
    scanf(" %c", &c1.estado);

    printf("Codigo: ");
    scanf("%s", c1.codigo);
    
    printf("nome da cidade: ");
    scanf(" %[^\n]", c1.nomeCidade);
    
    printf("PIB: ");
    scanf("%f", &c1.pib);
    
    printf("população (em milhões): ");
    scanf("%lu", &c1.populacao);
    
    printf("área (em km2):");
    scanf("%f", &c1.area );
    
    printf("numero de pontos turisticos: ");
    scanf("%d", &c1.pontosTuristicos);
    
    printf("                  \n");
      
    printf("estado (A-H): ");
    scanf(" %c", &c2.estado);

    printf("Codigo: ");
    scanf("%s", c2.codigo);
    
    printf("nome da cidade: ");
    scanf(" %[^\n]", c2.nomeCidade);
    
    printf("PIB: ");
    scanf("%f", &c2.pib);
    
    printf("população (em milhões): ");
    scanf("%lu", &c2.populacao);
    
    printf("área (em km2):");
    scanf("%f", &c2.area );
    
    printf("numero de pontos turisticos: ");
    scanf("%d", &c2.pontosTuristicos);
  
    
// calculo de denssidade populacional e pib por capital
    float densidade1 = (float)c1.populacao / c1.area;
    float densidade2 = (float)c2.populacao / c2.area;
    float pibPerCapita1 = c1.pib / c1.populacao;
    float pibPerCapita2 = c2.pib / c2.populacao;

    int atributo1, atributo2;
    float valor1c1 = 0, valor1c2 = 0;
    float valor2c1 = 0, valor2c2 = 0;

    // menu interativo 1
    int opcao;
    printf("                  \n");
    printf("Menu Interativo \n");
    printf("1 - Informações das cartas\n");
    printf("2 - Regras\n");
    printf("3 - Exit\n");
    scanf("%d", &opcao);

    printf("             \n");

    switch (opcao) {
    case 1:
        printf("Carta 1 \n");
        printf("Cidade: %s\n", c1.nomeCidade);
        printf("PIB: %.2f\n", c1.pib);
        printf("População: %lu\n", c1.populacao);

        printf("             \n");


        printf("Carta 2 \n");
        printf("Cidade: %s\n", c2.nomeCidade);
        printf("PIB: %.2f\n", c2.pib);
        printf("População: %lu\n", c2.populacao);

        printf("             \n");

        // segundo menu
        printf("Comparativo Carta 1: %s \n", c1.nomeCidade);
        printf("1 - PIB per capita\n");
        printf("2 - População\n");
        int escolha1;
        scanf("%d", &escolha1);

        printf("             \n");


        printf("Comparativo Carta 2: %s \n", c2.nomeCidade);
        printf("1 - PIB per capita\n");
        printf("2 - População\n");
        int escolha2;
        scanf("%d", &escolha2);

        printf("             \n");


        // Impedir que os jogadores escolham o mesmo atributo
        if (escolha1 == escolha2) {
            printf("Erro: não é permitido escolher o mesmo atributo!\n");
        } else {
            float valor1 = 0, valor2 = 0;

            // Escolha da carta 1
            if (escolha1 == 1) valor1 = pibPerCapita1;
            else if (escolha1 == 2) valor1 = c1.populacao;

            // Escolha da carta 2
            if (escolha2 == 1) valor2 = pibPerCapita2;
            else if (escolha2 == 2) valor2 = c2.populacao;
            // comparação e resultado
            printf("Resultado:\n");
            if (valor1 > valor2) {
                printf("Carta 1 (%s) venceu!\n", c1.nomeCidade);
                printf("Com diferença de (Aproximadamente): %.2f\n", valor1 - valor2);
            } else if (valor2 > valor1) {
                printf("Carta 2 (%s) venceu!\n", c2.nomeCidade);
                printf("Com diferença de (Aproximadamente): %.2f\n", valor2 - valor1);
            } else {
                printf("Empate!\n");
            }
        }
        break;

    case 2:
        printf("Regras: Cada jogador seleciona um valor para uma carta.\n");
        printf("Quem tiver o maior valor VENCE!!!!!!\n");
        printf("Se ambos escolherem o mesmo atributo, o jogo termina em empate.\n");
        printf("Um jogador não pode escolher o mesmo atributo que o outro jogador.\n");
        printf("Não é permitido valores negativos.\n");
        printf("Não abuse dos numeros absurdos.\n");
        printf("Boa sorte e divirta-se!\n");
        break;

    case 3:
        printf("Saindo...\n");
        break;

    default:
        printf("Opção inválida!\n");
        break;
    }

    return 0;
}