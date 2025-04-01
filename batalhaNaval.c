#include <stdio.h>

int main() {
    int tamanho = 10;
    int navio = 3;
    int tabuleiro[10][10];
    
    // Inicializar tabuleiro com água (0)
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            tabuleiro[i][j] = 0;
        }
    }
    
    // Coordenadas predefinidas para os navios
    int linha1 = 2, coluna1 = 3; // Navio horizontal
    int linha2 = 5, coluna2 = 7; // Navio vertical
    
    // Posicionar navio horizontalmente
    if (coluna1 + navio <= tamanho) {
        for (int i = 0; i < navio; i++) {
            tabuleiro[linha1][coluna1 + i] = 3;
        }
    }
    
    // Posicionar navio verticalmente
    if (linha2 + navio <= tamanho) {
        for (int i = 0; i < navio; i++) {
            tabuleiro[linha2 + i][coluna2] = 3;
        }
    }
    
    // Exibir o tabuleiro
    printf("   ");
    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    for (int i = 0; i < tamanho; i++) printf("%c ", linha[i]);
    printf("\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d  ", i);
        for (int j = 0; j < tamanho; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
