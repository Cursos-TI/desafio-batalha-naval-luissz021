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
    int linha3 = 1, coluna3 = 1; // Navio diagonal principal
    int linha4 = 6, coluna4 = 8; // Navio diagonal secundária
    
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
    
    // Posicionar navio diagonalmente principal (↘)
    if (linha3 + navio <= tamanho && coluna3 + navio <= tamanho) {
        for (int i = 0; i < navio; i++) {
            tabuleiro[linha3 + i][coluna3 + i] = 3;
        }
    }
    
    // Posicionar navio diagonalmente secundária (↙)
    if (linha4 + navio <= tamanho && coluna4 - navio >= 0) {
        for (int i = 0; i < navio; i++) {
            tabuleiro[linha4 + i][coluna4 - i] = 3;
        }
    }
    
    // Habilidades especiais
    int origem_cone_linha = 2, origem_cone_coluna = 5;
    int origem_cruz_linha = 5, origem_cruz_coluna = 5;
    int origem_octaedro_linha = 7, origem_octaedro_coluna = 5;
    
    // Aplicar habilidade em formato de cone
    for (int i = 0; i < 3; i++) {
        for (int j = -i; j <= i; j++) {
            int lin = origem_cone_linha + i;
            int col = origem_cone_coluna + j;
            if (lin < tamanho && col >= 0 && col < tamanho) {
                tabuleiro[lin][col] = 5;
            }
        }
    }
    
    // Aplicar habilidade em formato de cruz
    for (int i = -2; i <= 2; i++) {
        if (origem_cruz_linha + i >= 0 && origem_cruz_linha + i < tamanho)
            tabuleiro[origem_cruz_linha + i][origem_cruz_coluna] = 5;
        if (origem_cruz_coluna + i >= 0 && origem_cruz_coluna + i < tamanho)
            tabuleiro[origem_cruz_linha][origem_cruz_coluna + i] = 5;
    }
    
    // Aplicar habilidade em formato de octaedro
    for (int i = -2; i <= 2; i++) {
        for (int j = - (2 - (i < 0 ? -i : i)); j <= (2 - (i < 0 ? -i : i)); j++) {
            int lin = origem_octaedro_linha + i;
            int col = origem_octaedro_coluna + j;
            if (lin >= 0 && lin < tamanho && col >= 0 && col < tamanho) {
                tabuleiro[lin][col] = 5;
            }
        }
    }
    
    // Exibir o tabuleiro
    printf("   ");
    char alfa[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    for (int i = 0; i < tamanho; i++) printf("%c ", alfa[i]);
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
