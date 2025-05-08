#include <stdio.h>

// Constantes para as direções
#define CIMA "Cima\n"
#define BAIXO "Baixo\n"
#define ESQUERDA "Esquerda\n"
#define DIREITA "Direita\n"

// ========== FUNÇÕES RECURSIVAS (NÍVEL MESTRE) ==========
void moverBispoRecursivo(int casas) {
    if(casas <= 0) return;
    printf(CIMA);
    printf(DIREITA);
    moverBispoRecursivo(casas - 1);
}

void moverTorreRecursivo(int casas) {
    if(casas <= 0) return;
    printf(DIREITA);
    moverTorreRecursivo(casas - 1);
}

void moverRainhaRecursivo(int casas) {
    if(casas <= 0) return;
    printf(ESQUERDA);
    moverRainhaRecursivo(casas - 1);
}

// ========== FUNÇÃO PRINCIPAL ==========
int main() {
    // ========== NÍVEL NOVATO ==========
    printf("=== NÍVEL NOVATO ===\n");
    
    // Bispo: 5 casas na diagonal superior direita
    printf("\nBispo (5 casas diagonal superior direita):\n");
    for(int i = 0; i < 5; i++) {
        printf(CIMA);
        printf(DIREITA);
    }
    
    // Torre: 5 casas para a direita
    printf("\nTorre (5 casas para direita):\n");
    for(int i = 0; i < 5; i++) {
        printf(DIREITA);
    }
    
    // Rainha: 8 casas para a esquerda
    printf("\nRainha (8 casas para esquerda):\n");
    int contador = 0;
    while(contador < 8) {
        printf(ESQUERDA);
        contador++;
    }
    
    // ========== NÍVEL AVENTUREIRO ==========
    printf("\n\n=== NÍVEL AVENTUREIRO ===");
    printf("\nCavalo (movimento em L - 2 baixo, 1 esquerda):\n");
    
    // Parte vertical do L (2 para baixo)
    for(int i = 0; i < 2; i++) {
        printf(BAIXO);
    }
    
    // Parte horizontal do L (1 para esquerda)
    int j = 0;
    do {
        printf(ESQUERDA);
        j++;
    } while(j < 1);
    
    // ========== NÍVEL MESTRE ==========
    printf("\n\n=== NÍVEL MESTRE ===");
    
    // Bispo recursivo
    printf("\nBispo recursivo (5 casas diagonal direita para cima):\n");
    moverBispoRecursivo(5);
    
    // Torre recursiva
    printf("\nTorre recursiva (5 casas para direita):\n");
    moverTorreRecursivo(5);
    
    // Rainha recursiva
    printf("\nRainha recursiva (8 casas para esquerda):\n");
    moverRainhaRecursivo(8);
    
    // Cavalo com loops aninhados e condições complexas
    printf("\nCavalo (1 L para cima à direita):\n");
    for(int x = 0, y = 0; x < 2 || y < 1; ) {
        if(x < 2) {
            printf(CIMA);
            x++;
            continue;
        }
        if(y < 1) {
            printf(DIREITA);
            y++;
        }
    }
    
    printf("\n=== FIM DE TODOS OS NÍVEIS ===\n");
    return 0;
}