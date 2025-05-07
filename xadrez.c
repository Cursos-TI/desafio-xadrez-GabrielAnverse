#include <stdio.h>

// Desafio de Xadrez - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de movimentação das peças de xadrez.
// O objetivo é utilizar estruturas de repetição e funções para determinar os limites de movimentação dentro do jogo.

// Constantes para direções (sugestão do professor)
#define CIMA "Cima"
#define BAIXO "Baixo"
#define ESQUERDA "Esquerda"
#define DIREITA "Direita"

// Constantes para número de movimentos (sugestão do professor)
#define MOV_BISPO 5
#define MOV_TORRE 5
#define MOV_RAINHA 8

// Nível Novato - Movimentação das Peças
void movimentoBispo() {
    // Implementação de Movimentação do Bispo (sugestão: loop para diagonal)
    printf("\nBispo movendo %d casas na diagonal superior direita:\n", MOV_BISPO);
    for(int i = 1; i <= MOV_BISPO; i++) {
        printf("%s + %s\n", CIMA, DIREITA); // Combinação de direções
    }
}

void movimentoTorre() {
    // Implementação de Movimentação da Torre (sugestão: loop para direita)
    printf("\nTorre movendo %d casas para a direita:\n", MOV_TORRE);
    for(int i = 1; i <= MOV_TORRE; i++) {
        printf("%s\n", DIREITA);
    }
}

void movimentoRainha() {
    // Implementação de Movimentação da Rainha (sugestão: loop para esquerda)
    printf("\nRainha movendo %d casas para a esquerda:\n", MOV_RAINHA);
    int i = 1;
    while(i <= MOV_RAINHA) {
        printf("%s\n", ESQUERDA);
        i++;
    }
}

// Nível Aventureiro - Movimentação do Cavalo (esqueleto sugerido)
void movimentoCavalo() {
    // Sugestão: loops aninhados para movimento em L
    printf("\nCavalo movendo em L (baixo + esquerda):\n");
    // Loop externo (vertical)
    for(int vertical = 1; vertical <= 2; vertical++) {
        // Loop interno (horizontal)
        for(int horizontal = 1; horizontal <= 1; horizontal++) {
            printf("%s + %s + %s\n", BAIXO, BAIXO, ESQUERDA); // Padrão em L
        }
    }
}

// Nível Mestre - Funções Recursivas (esqueleto sugerido)
void movimentoBispoRecursivo(int casa) {
    // Caso base
    if(casa > MOV_BISPO) return;
    
    printf("%s + %s (Recursivo)\n", CIMA, DIREITA);
    movimentoBispoRecursivo(casa + 1); // Chamada recursiva
}

int main() {
    printf("=== NÍVEL NOVATO ===\n");
    movimentoBispo();
    movimentoTorre();
    movimentoRainha();

    printf("\n=== NÍVEL AVENTUREIRO ===\n");
    movimentoCavalo();

    printf("\n=== NÍVEL MESTRE ===\n");
    printf("Bispo recursivo (%d casas):\n", MOV_BISPO);
    movimentoBispoRecursivo(1);

    return 0;
}
