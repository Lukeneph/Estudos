#include <stdio.h>

int torre_moves = 5;
int bispo_moves = 5;
int rainha_moves = 8;
int cavalo_moves = 3;
int bispo_aninhados_moves = 5;

// Função para o movimento da Torre utilizando Recursão
void Torre(int casas) {
    if (casas <= 0) {
        return;
    }
    printf("Direita\n");
    Torre(casas - 1);
}

// Função para o movimento do Bispo utilizando Recursão
void Bispo(int Casas) {
    if (Casas <= 0) {
        return;
    }
    printf("Cima\n");
    printf("Direita\n");
    Bispo(Casas - 1);
}

// Função para o movimento da Rainha utilizando Recursão
void Rainha(int Casas) {
    if (Casas <= 0) {
        return;
    }
    printf("Direita\n");
    Rainha(Casas - 1);
}

// Função para o movimento do Cavalo utilizando Loop Complexo 
void Cavalo(int Casas) {
    int Movimentos_Cima = 0;
    int movimentos_Direita = 0;
    for (int i = 0; i < 3; i++) {
        if (Movimentos_Cima < 2) {
            printf("Cima\n");
            Movimentos_Cima++;
        } else {
            printf("Direita\n");
            movimentos_Direita++;
            Movimentos_Cima = 0;
        }
    }
}

// Função para o movimento do Bispo utilizando Loops Aninhados
void Bispo_Aninhados(int Casas) {
    for (int i = 0; i < Casas; i++) {
        for (int j = 0; j < 1; j++) {
            printf("Cima\n");
        }
        for (int k = 0; k < 1; k++) {
            printf("Direita\n");
        }
    }
}

// Função Para printar os movimentos das peças
int main() {
    printf("\nMovimentos da Torre:\n"); // Chama a função Torre
    Torre(torre_moves);

    printf("\nMovimentos do Bispo:\n"); // Chama a função Bispo
    Bispo(bispo_moves);

    printf("\nMovimentos do Bispo com Loops Aninhados:\n"); // Chama a função Bispo_Aninhados
    Bispo_Aninhados(bispo_aninhados_moves);

    printf("\nMovimentos da Rainha:\n"); // Chama a função Rainha
    Rainha(rainha_moves);

    printf("\nMovimentos do Cavalo:\n"); // Chama a função Cavalo
    Cavalo(cavalo_moves);
    return 0;
}