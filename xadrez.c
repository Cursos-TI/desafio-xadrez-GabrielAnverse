#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Constantes para direções
#define CIMA "Cima"
#define BAIXO "Baixo"
#define ESQUERDA "Esquerda"
#define DIREITA "Direita"

// Estrutura para representar uma carta de cidade
struct Carta {
    char estado[50];
    char codigo[10];
    char cidade[50];
    float populacao;
    float area;
    float pib;
    int pontos_turisticos;
};

// Protótipos das funções
void nivelNovato();
void nivelAventureiro();
void nivelMestre();
void cadastrarCarta(struct Carta *carta, int numero);
void exibirCarta(struct Carta carta);
void compararCartas(struct Carta carta1, struct Carta carta2, char atributo[20]);
void moverBispo();
void moverTorre();
void moverRainha();
void moverCavalo();
void moverTorreRecursivo(int casas);
void moverRainhaRecursivo(int casas);
void moverBispoRecursivo(int casas);
void moverCavaloAvancado();

int main() {
    int opcao;
    
    do {
        printf("\n=== SUPER TRUNFO - PAÍSES ===\n");
        printf("1. Nível Novato (Comparação de Cartas)\n");
        printf("2. Nível Aventureiro (Movimento Cavalo)\n");
        printf("3. Nível Mestre (Funções Recursivas)\n");
        printf("0. Sair\n");
        printf("Escolha o nível: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                nivelNovato();
                break;
            case 2:
                nivelAventureiro();
                break;
            case 3:
                nivelMestre();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while(opcao != 0);
    
    return 0;
}

// ========== NÍVEL NOVATO ========== //
void nivelNovato() {
    printf("\n=== MODO NOVATO - COMPARAÇÃO DE CARTAS ===\n");
    
    struct Carta carta1, carta2;
    
    // Cadastrar duas cartas
    cadastrarCarta(&carta1, 1);
    cadastrarCarta(&carta2, 2);
    
    // Exibir cartas cadastradas
    printf("\nCartas Cadastradas:");
    exibirCarta(carta1);
    exibirCarta(carta2);
    
    // Comparar cartas por diferentes atributos
    compararCartas(carta1, carta2, "populacao");
    compararCartas(carta1, carta2, "area");
    compararCartas(carta1, carta2, "pib");
    compararCartas(carta1, carta2, "pontos_turisticos");
    compararCartas(carta1, carta2, "densidade");
}

void cadastrarCarta(struct Carta *carta, int numero) {
    printf("\nCadastro da Carta %d:\n", numero);
    
    printf("Digite o estado: ");
    scanf("%s", carta->estado);
    
    printf("Digite o código da cidade: ");
    scanf("%s", carta->codigo);
    
    printf("Digite o nome da cidade: ");
    scanf("%s", carta->cidade);
    
    printf("Digite a população (em milhares): ");
    scanf("%f", &carta->populacao);
    
    printf("Digite a área (em km²): ");
    scanf("%f", &carta->area);
    
    printf("Digite o PIB (em milhões): ");
    scanf("%f", &carta->pib);
    
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta->pontos_turisticos);
}

void exibirCarta(struct Carta carta) {
    printf("\nDetalhes da Carta:\n");
    printf("Estado: %s\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Cidade: %s\n", carta.cidade);
    printf("População: %.2f mil habitantes\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f milhões\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontos_turisticos);
}

void compararCartas(struct Carta carta1, struct Carta carta2, char atributo[20]) {
    printf("\nResultado da Comparação (%s):\n", atributo);
    
    if (strcmp(atributo, "populacao") == 0) {
        if (carta1.populacao > carta2.populacao) {
            printf("%s tem maior população que %s\n", carta1.cidade, carta2.cidade);
        } else if (carta1.populacao < carta2.populacao) {
            printf("%s tem maior população que %s\n", carta2.cidade, carta1.cidade);
        } else {
            printf("As cidades têm a mesma população\n");
        }
    }
    else if (strcmp(atributo, "area") == 0) {
        if (carta1.area > carta2.area) {
            printf("%s tem maior área que %s\n", carta1.cidade, carta2.cidade);
        } else if (carta1.area < carta2.area) {
            printf("%s tem maior área que %s\n", carta2.cidade, carta1.cidade);
        } else {
            printf("As cidades têm a mesma área\n");
        }
    }
    else if (strcmp(atributo, "pib") == 0) {
        if (carta1.pib > carta2.pib) {
            printf("%s tem maior PIB que %s\n", carta1.cidade, carta2.cidade);
        } else if (carta1.pib < carta2.pib) {
            printf("%s tem maior PIB que %s\n", carta2.cidade, carta1.cidade);
        } else {
            printf("As cidades têm o mesmo PIB\n");
        }
    }
    else if (strcmp(atributo, "pontos_turisticos") == 0) {
        if (carta1.pontos_turisticos > carta2.pontos_turisticos) {
            printf("%s tem mais pontos turísticos que %s\n", carta1.cidade, carta2.cidade);
        } else if (carta1.pontos_turisticos < carta2.pontos_turisticos) {
            printf("%s tem mais pontos turísticos que %s\n", carta2.cidade, carta1.cidade);
        } else {
            printf("As cidades têm o mesmo número de pontos turísticos\n");
        }
    }
    else if (strcmp(atributo, "densidade") == 0) {
        float densidade1 = carta1.populacao / carta1.area;
        float densidade2 = carta2.populacao / carta2.area;
        
        if (densidade1 < densidade2) {
            printf("%s tem menor densidade populacional que %s\n", carta1.cidade, carta2.cidade);
        } else if (densidade1 > densidade2) {
            printf("%s tem menor densidade populacional que %s\n", carta2.cidade, carta1.cidade);
        } else {
            printf("As cidades têm a mesma densidade populacional\n");
        }
    }
    else {
        printf("Atributo inválido para comparação!\n");
    }
}

// ========== NÍVEL AVENTUREIRO ========== //
void nivelAventureiro() {
    printf("\n=== MODO AVENTUREIRO - MOVIMENTO CAVALO ===\n");
    printf("Demonstração do movimento do cavalo em L:\n");
    moverCavalo();
}

void moverCavalo() {
    printf("\nMovimento do Cavalo (em L para baixo e esquerda):\n");
    
    // Primeira parte do L (2 casas para baixo)
    for(int i = 0; i < 2; i++) {
        printf("%s\n", BAIXO);
    }
    
    // Segunda parte do L (1 casa para esquerda)
    int j = 0;
    while(j < 1) {
        printf("%s\n", ESQUERDA);
        j++;
    }
}

// ========== NÍVEL MESTRE ========== //
void nivelMestre() {
    printf("\n=== MODO MESTRE - FUNÇÕES RECURSIVAS ===\n");
    
    printf("\nBispo (5 casas diagonal direita para cima):\n");
    moverBispoRecursivo(5);
    
    printf("\nTorre (5 casas para a direita):\n");
    moverTorreRecursivo(5);
    
    printf("\nRainha (8 casas para a esquerda):\n");
    moverRainhaRecursivo(8);
    
    printf("\nCavalo (1 vez em L para cima à direita):\n");
    moverCavaloAvancado();
}

void moverTorreRecursivo(int casas) {
    if(casas <= 0) return;
    printf("%s\n", DIREITA);
    moverTorreRecursivo(casas - 1);
}

void moverRainhaRecursivo(int casas) {
    if(casas <= 0) return;
    printf("%s\n", ESQUERDA);
    moverRainhaRecursivo(casas - 1);
}

void moverBispoRecursivo(int casas) {
    if(casas <= 0) return;
    printf("%s e %s\n", CIMA, DIREITA);
    moverBispoRecursivo(casas - 1);
}

void moverCavaloAvancado() {
    int i, j;
    for(i = 0, j = 0; i < 2 || j < 1; ) {
        if(i < 2) {
            printf("%s\n", CIMA);
            i++;
            continue;
        }
        if(j < 1) {
            printf("%s\n", DIREITA);
            j++;
        }
    }
}