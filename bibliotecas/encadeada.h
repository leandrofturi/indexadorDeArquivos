#ifndef ENCADEADA_H
#define ENCADEADA_H

#include "palavra.h"

typedef struct tCelula tCelula;
struct tCelula {
    tPalavra *P;
    tCelula *prox;
};

typedef struct tEncadeada tEncadeada;
struct tEncadeada {
    tCelula *cabeca;
	tCelula *rabo;
	int n;
};


tEncadeada *criaEncadeada ( );

void liberaEncadeada (tEncadeada *E);

void insereEncadeada (char *palavra, int posicao, tEncadeada *E);

tPalavra *buscaPalavraEncadeada (char *palavra, tEncadeada *E);

void imprimeEncadeada (tEncadeada *E);

#endif
