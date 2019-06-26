#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../bibliotecas/palavra.h"

tPalavra *criaPalavra (char *palavra, int posicao) {
    tPalavra *P;
    P = (tPalavra*) malloc (sizeof (tPalavra));
    P->palavra = (char*) malloc ((strlen (palavra) + 1) * sizeof (char));
    strcpy (P->palavra, palavra);
    P->posicao = (int*) malloc (sizeof (int));
    P->posicao[0] = posicao;
    P->ocorrencias = 1;

    return (P);
}

void liberaPalavra (tPalavra *P) {
    free (P->palavra);
    free (P->posicao);
    free (P);
}

void colocaPosicao (int novaPosicao, tPalavra *P) {
    int *nova;
    nova = (int*) malloc ((P->ocorrencias + 1) * sizeof (int));
    for (int i = 0; i < P->ocorrencias; i ++) {
        nova[i] = P->posicao[i];
    }
    nova[P->ocorrencias] = novaPosicao;
    free (P->posicao);
    P->posicao = nova;
    P->ocorrencias ++;
}
