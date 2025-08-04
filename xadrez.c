#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Converte letra 'A'-'H' em número 0-7
int letraParaColuna(char letra) {
    letra = toupper(letra);
    return letra - 'A';
}

// Verifica se posição está dentro do tabuleiro
int posicaoValida(int linha, int coluna) {
    return linha >= 0 && linha < 8 && coluna >= 0 && coluna < 8;
}

int main() {
    char peca[10];
    char posIni[3], posFim[3];
    int li, ci, lf, cf;
    int difLinha, difColuna;

    printf("=== VERIFICADOR DE MOVIMENTO DE PEÇA DE XADREZ ===\n");
    printf("Peças aceitas: rei, torre, bispo, cavalo, rainha\n");

    printf("Informe a peça: ");
    scanf("%s", peca);

    printf("Posição inicial (ex: A1): ");
    scanf("%s", posIni);
    printf("Posição final (ex: B2): ");
    scanf("%s", posFim);

    ci = letraParaColuna(posIni[0]);
    li = posIni[1] - '1';
    cf = letraParaColuna(posFim[0]);
    lf = posFim[1] - '1';

    // Validação
    if (!posicaoValida(li, ci) || !posicaoValida(lf, cf)) {
        printf("Posição fora do tabuleiro!\n");
        return 1;
    }

    difLinha = abs(lf - li);
    difColuna = abs(cf - ci);

    int valido = 0;

    // Verificar regras
    if (strcmp(peca, "rei") == 0) {
        valido = (difLinha <= 1 && difColuna <= 1);
    } else if (strcmp(peca, "torre") == 0) {
        valido = (li == lf || ci == cf);
    } else if (strcmp(peca, "bispo") == 0) {
        valido = (difLinha == difColuna);
    } else if (strcmp(peca, "rainha") == 0) {
        valido = (li == lf || ci == cf || difLinha == difColuna);
    } else if (strcmp(peca, "cavalo") == 0) {
        valido = (difLinha == 2 && difColuna == 1) || (difLinha == 1 && difColuna == 2);
    } else {
        printf("Peça desconhecida!\n");
        return 1;
    }

    if (valido) {
        printf("✅ Movimento válido para %s\n", peca);
    } else {
        printf("❌ Movimento inválido para %s\n", peca);
    }

    return 0;
}
