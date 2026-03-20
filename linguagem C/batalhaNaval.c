#include <stdio.h>
#include <stdlib.h>

// Inicio do codigo, função do tabuleiro naval
int main() {
    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int Tabuleiro[10][10];

// Inicializa o tabuleiro com (zeros = agua)

    for (int Numero1 = 0; Numero1 < 10; Numero1++) {
        for (int Numero2 = 0; Numero2 < 10; Numero2++) {
            Tabuleiro[Numero1][Numero2] = 0;
        }
    }

// Coloca o tamanho do navio no tabuleiro

    int Navio[3] = {3, 3, 3};

// Define a posição do navio no tabuleiro
// No Tabuleiro e de 0 a 9, onde 0 é a primeira linha/coluna e 9 a ultima linha/coluna
// Masmostra 1 a 10 para o usuario por questão de visualização

    int linhaX1 = 4, colunaX1 = 7;

    int linhaY2 = 4, colunaY2 = 0;

    int linhaX3 = 0, colunaX3 = 1;

    int linhaY4 = 2, colunaY4 = 7;

// Coloca o navio 1 horizontal no tabuleiro

    if (linhaX1 >= 0 && linhaX1 < 10 && colunaX1 >= 0 && colunaX1 + 2 < 10) {
        int sobreposicao = 0;
        for (int i = 0; i < 3; i++) {
            if (Tabuleiro[linhaX1][colunaX1 + i] != 0) {
                sobreposicao = 1;
                break;
            }
        }
        if (sobreposicao == 0) {
            for (int i = 0; i < 3; i++) {
                Tabuleiro[linhaX1][colunaX1 + i] = Navio[i];
            }
        } else {
            printf("Erro: Sobreposição de navios na posição horizontal.\n"); // mensagem de erro
            return 1;
        }
    } else {
        printf("Erro: Posição do navio horizontal fora dos limites do tabuleiro.\n"); // mensagem de erro
        return 1;
    }

// Coloca o navio vertical no tabuleiro

    if (linhaY2 >= 0 && linhaY2 + 2 < 10 && colunaY2 >= 0 && colunaY2 < 10) {
        int sobreposicao = 0;
        for (int i = 0; i < 3; i++) {
            if (Tabuleiro[linhaY2 + i][colunaY2] != 0) {
                sobreposicao = 1;
                break;
            }
        }
        if (sobreposicao == 0) {
            for (int i = 0; i < 3; i++) {
                Tabuleiro[linhaY2 + i][colunaY2] = Navio[i];
            }
        } else {
            printf("Erro: Sobreposição de navios na posição vertical.\n"); // mensagem de erro
            return 1;
        }
    } else {
        printf("Erro: Posição do navio vertical fora dos limites do tabuleiro.\n"); // mensagem de erro
        return 1;
    }

// Coloca navio 3 diagonal no tabuleiro

    if (linhaX3 >= 0 && linhaX3 + 2 < 10 && colunaX3 >= 0 && colunaX3 + 2 < 10) {
        int sobreposicao = 0;
        for (int i = 0; i < 3; i++) {
            if (Tabuleiro[linhaX3 + i][colunaX3 + i] != 0) {
                sobreposicao = 1;
                break;
            }
        }
        if (sobreposicao == 0) {
            for (int i = 0; i < 3; i++) {
                Tabuleiro[linhaX3 + i][colunaX3 + i] = Navio[i];
            }
        } else {
            printf("Erro: Sobreposição de navios na posição diagonal.\n"); // mensagem de erro
            return 1;
        }
    } else {
        printf("Erro: Posição do navio diagonal fora dos limites do tabuleiro.\n"); // mensagem de erro
        return 1;
    }

// Coloca navio 4 diagonal invertido no tabuleiro

    if (linhaY4 - 2 >= 0 && linhaY4 < 10 && colunaY4 >= 0 && colunaY4 + 2 < 10) {
        int sobreposicao = 0;
        for (int i = 0; i < 3; i++) {
            if (Tabuleiro[linhaY4 - i][colunaY4 + i] != 0) {
                sobreposicao = 1;
                break;
            }
        }
        if (sobreposicao == 0) {
            for (int i = 0; i < 3; i++) {
                Tabuleiro[linhaY4 - i][colunaY4 + i] = Navio[i];
            }
        } else {
            printf("Erro: Sobreposição de navios na posição diagonal invertida.\n"); // mensagem de erro
            return 1;
        }
    } else {
        printf("Erro: Posição do navio diagonal invertida fora dos limites do tabuleiro.\n"); // mensagem de erro
        return 1;
    }
// Define as habilidades como matrizes 5x5

    int cone [5][5];
    int cruz [5][5];
    int octaedro [5][5];
    int centro = 2;

// Preenche a matriz do cone

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (j >= centro - i && j <= centro + i) {
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }
        }
    }

// Preenche a matriz da cruz

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == centro || j == centro) {
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }
        }
    }

// Preenche a matriz do octaedro

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int distancia_linha = abs(i - centro);
            int distancia_coluna = abs(j - centro);
            if (distancia_linha + distancia_coluna <= centro) {
                octaedro[i][j] = 1;
            } else {
                octaedro[i][j] = 0;
            }
        }
    }
// Define a posição das habilidades no tabuleiro

    int Cone_linha = 9, Cone_coluna = 2;
    int Cruz_linha = 4, Cruz_coluna = 4;
    int Octaedro_linha = 7, Octaedro_coluna = 7;

    void Habilidades(int habilidade[5][5], int linha_inicial, int coluna_inicial, int tabuleiro[10][10], int centro_habilidade) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {

                if (habilidade [i][j] == 1) {

                    int linha_tabuleiro = linha_inicial + (i - centro_habilidade);
                    int coluna_tabuleiro = coluna_inicial + (j - centro_habilidade);

                    if (linha_tabuleiro >= 0 && linha_tabuleiro < 10 &&
                        coluna_inicial >= 0 && coluna_tabuleiro < 10) {

                        if (tabuleiro[linha_tabuleiro][coluna_tabuleiro] == 0) {
                            tabuleiro[linha_tabuleiro][coluna_tabuleiro] = 5;
                    }
                }
            }
        }
    }
}
// Aplica as habilidades no tabuleiro
    Habilidades(cone, Cone_linha, Cone_coluna, Tabuleiro, centro);

    Habilidades(cruz, Cruz_linha, Cruz_coluna, Tabuleiro, centro);

    Habilidades(octaedro, Octaedro_linha, Octaedro_coluna, Tabuleiro, centro);

// imprime as Letras no tabuleiro

    printf("  ");
    for (int c = 0; c < 10; c++) {
        printf(" %c ", linha[c]);
    }
    printf("\n");

    for (int Numero1 = 0; Numero1 < 10; Numero1++) {
        int Numero2 = Numero1 + 1;

        if (Numero2 < 10) {
            printf("%d ", Numero2);
        } else {
            printf("%d", Numero2);
        }

        for (int Numero3 = 0; Numero3 < 10; Numero3++) {
            
            int valor_casa = Tabuleiro[Numero1][Numero3];

            if (valor_casa == 0) {
                printf(" 0 "); // 0 para Água   
            } else if (valor_casa == 3) {
                printf(" 3 "); // 3 para Navio
            } else if (valor_casa == 5) {
                printf(" 5 "); // 5 para Habilidade 
            } else {
                printf(" %d ", valor_casa);
            }
        }
        printf("\n");
    }
    return 0;
}
        